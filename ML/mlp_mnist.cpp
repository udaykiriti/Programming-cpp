#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <Eigen/Dense>
#include <random>
#include <cmath>

using namespace std;
using namespace Eigen;

#define INPUT_SIZE 784
#define HIDDEN_SIZE 128
#define OUTPUT_SIZE 10
#define EPOCHS 5
#define LEARNING_RATE 0.01
#define BATCH_SIZE 32

struct Sample {
    VectorXd features;
    VectorXd label;
};

vector<Sample> load_csv(const string& filename, int limit = -1) {
    vector<Sample> data;
    ifstream file(filename);
    string line;
    int count = 0;
    while (getline(file, line)) {
        if (limit != -1 && count++ >= limit) break;
        stringstream ss(line);
        string cell;
        vector<double> values;
        while (getline(ss, cell, ',')) values.push_back(stod(cell));
        VectorXd x(INPUT_SIZE);
        for (int i = 1; i <= INPUT_SIZE; ++i)
            x(i - 1) = values[i] / 255.0; // normalize
        VectorXd y = VectorXd::Zero(OUTPUT_SIZE);
        y((int)values[0]) = 1.0;
        data.push_back({x, y});
    }
    return data;
}

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double d_sigmoid(double x) {
    double s = sigmoid(x);
    return s * (1 - s);
}

double softmax_stable(const VectorXd& z, VectorXd& output) {
    double max_val = z.maxCoeff();
    VectorXd exp_vals = (z.array() - max_val).exp();
    double sum = exp_vals.sum();
    output = exp_vals / sum;
    return sum;
}

class MLP {
public:
    MatrixXd W1, W2;
    VectorXd b1, b2;

    MLP() {
        random_device rd;
        mt19937 gen(rd());
        normal_distribution<> d(0, 1);

        W1 = MatrixXd::NullaryExpr(HIDDEN_SIZE, INPUT_SIZE, [&]() { return d(gen) * sqrt(2.0 / INPUT_SIZE); });
        W2 = MatrixXd::NullaryExpr(OUTPUT_SIZE, HIDDEN_SIZE, [&]() { return d(gen) * sqrt(2.0 / HIDDEN_SIZE); });
        b1 = VectorXd::Zero(HIDDEN_SIZE);
        b2 = VectorXd::Zero(OUTPUT_SIZE);
    }

    void forward(const VectorXd& x, VectorXd& out, VectorXd& z1, VectorXd& a1) {
        z1 = W1 * x + b1;
        a1 = z1.unaryExpr(ptr_fun(sigmoid));
        VectorXd z2 = W2 * a1 + b2;
        softmax_stable(z2, out);
    }

    void train_batch(const vector<Sample>& batch) {
        MatrixXd dW1 = MatrixXd::Zero(HIDDEN_SIZE, INPUT_SIZE);
        MatrixXd dW2 = MatrixXd::Zero(OUTPUT_SIZE, HIDDEN_SIZE);
        VectorXd db1 = VectorXd::Zero(HIDDEN_SIZE);
        VectorXd db2 = VectorXd::Zero(OUTPUT_SIZE);

        for (const auto& sample : batch) {
            VectorXd z1, a1, y_hat;
            forward(sample.features, y_hat, z1, a1);

            VectorXd dz2 = y_hat - sample.label;
            dW2 += dz2 * a1.transpose();
            db2 += dz2;

            VectorXd da1 = W2.transpose() * dz2;
            VectorXd dz1 = z1.unaryExpr(ptr_fun(d_sigmoid)).array() * da1.array();
            dW1 += dz1 * sample.features.transpose();
            db1 += dz1;
        }

        W1 -= (LEARNING_RATE / batch.size()) * dW1;
        b1 -= (LEARNING_RATE / batch.size()) * db1;
        W2 -= (LEARNING_RATE / batch.size()) * dW2;
        b2 -= (LEARNING_RATE / batch.size()) * db2;
    }

    int predict(const VectorXd& x) {
        VectorXd z1, a1, y_hat;
        forward(x, y_hat, z1, a1);
        Eigen::Index maxIndex;
        y_hat.maxCoeff(&maxIndex);
        return maxIndex;
    }

    double evaluate(const vector<Sample>& test_data) {
        int correct = 0;
        for (const auto& sample : test_data)
            if (predict(sample.features) == sample.label.maxCoeff(&correct)) ++correct;
        return (double)correct / test_data.size();
    }
};

int main() {
    auto train_data = load_csv("mnist_train.csv", 60000);
    auto test_data = load_csv("mnist_test.csv", 10000);
    MLP model;

    for (int epoch = 0; epoch < EPOCHS; ++epoch) {
        shuffle(train_data.begin(), train_data.end(), std::mt19937{std::random_device{}()});
        for (int i = 0; i < train_data.size(); i += BATCH_SIZE) {
            int end = min(i + BATCH_SIZE, (int)train_data.size());
            vector<Sample> batch(train_data.begin() + i, train_data.begin() + end);
            model.train_batch(batch);
        }
        cout << "Epoch " << epoch + 1 << " completed.\n";
    }

    double acc = model.evaluate(test_data);
    cout << "Test Accuracy: " << acc * 100 << "%\n";
    return 0;
}
