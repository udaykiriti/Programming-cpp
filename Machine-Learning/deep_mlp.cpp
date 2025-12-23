#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>

using namespace std;

struct MLP {
    int input_size, output_size;
    vector<int> hidden_layers;
    vector<vector<vector<double>>> weights; // weights[layer][neuron][input]
    vector<vector<double>> biases;          // biases[layer][neuron]
    vector<vector<double>> activations;     // activations[layer][neuron]
    vector<vector<double>> zs;               // weighted inputs before activation

    MLP(int input_sz, vector<int> hidden, int output_sz) :
        input_size(input_sz), hidden_layers(hidden), output_size(output_sz)
    {
        vector<int> layers_sizes = hidden_layers;
        layers_sizes.insert(layers_sizes.begin(), input_size);
        layers_sizes.push_back(output_size);

        random_device rd;
        mt19937 gen(rd());
        normal_distribution<> dist(0, 1);

        weights.resize(layers_sizes.size() - 1);
        biases.resize(layers_sizes.size() - 1);
        activations.resize(layers_sizes.size());
        zs.resize(layers_sizes.size() - 1);

        for (size_t l = 0; l < weights.size(); ++l) {
            weights[l].resize(layers_sizes[l + 1], vector<double>(layers_sizes[l]));
            biases[l].resize(layers_sizes[l + 1]);
            zs[l].resize(layers_sizes[l + 1]);
            for (int j = 0; j < layers_sizes[l + 1]; ++j) {
                biases[l][j] = dist(gen) * sqrt(2.0 / layers_sizes[l]);
                for (int k = 0; k < layers_sizes[l]; ++k) {
                    weights[l][j][k] = dist(gen) * sqrt(2.0 / layers_sizes[l]);
                }
            }
        }
        for (size_t l = 0; l < activations.size(); ++l)
            activations[l].resize(layers_sizes[l]);
    }

    static double relu(double x) {
        return x > 0 ? x : 0;
    }

    static double relu_derivative(double x) {
        return x > 0 ? 1 : 0;
    }

    static vector<double> softmax(const vector<double>& input) {
        double max_val = *max_element(input.begin(), input.end());
        vector<double> exps(input.size());
        double sum = 0;
        for (size_t i = 0; i < input.size(); ++i) {
            exps[i] = exp(input[i] - max_val);
            sum += exps[i];
        }
        for (auto& v : exps)
            v /= sum;
        return exps;
    }

    vector<double> forward(const vector<double>& input) {
        activations[0] = input;
        for (size_t l = 0; l < weights.size(); ++l) {
            for (size_t j = 0; j < weights[l].size(); ++j) {
                double sum = biases[l][j];
                for (size_t k = 0; k < weights[l][j].size(); ++k) {
                    sum += weights[l][j][k] * activations[l][k];
                }
                zs[l][j] = sum;
                if (l == weights.size() - 1)
                    activations[l + 1][j] = sum; // output layer no ReLU, softmax later
                else
                    activations[l + 1][j] = relu(sum);
            }
        }
        activations.back() = softmax(activations.back());
        return activations.back();
    }

    void backward(const vector<double>& target, double lr) {
        int L = (int)weights.size();
        vector<vector<double>> delta(L);

        delta[L - 1].resize(output_size);
        for (int i = 0; i < output_size; ++i)
            delta[L - 1][i] = activations[L][i] - target[i]; // dC/dz for output layer (cross-entropy with softmax)

        for (int l = L - 2; l >= 0; --l) {
            delta[l].resize(hidden_layers[l]);
            for (int i = 0; i < hidden_layers[l]; ++i) {
                double sum = 0;
                for (int j = 0; j < (int)delta[l + 1].size(); ++j) {
                    sum += weights[l + 1][j][i] * delta[l + 1][j];
                }
                delta[l][i] = sum * relu_derivative(zs[l][i]);
            }
        }

        for (int l = 0; l < L; ++l) {
            for (size_t j = 0; j < weights[l].size(); ++j) {
                for (size_t k = 0; k < weights[l][j].size(); ++k) {
                    weights[l][j][k] -= lr * delta[l][j] * activations[l][k];
                }
                biases[l][j] -= lr * delta[l][j];
            }
        }
    }

    int predict(const vector<double>& input) {
        vector<double> out = forward(input);
        return (int)(max_element(out.begin(), out.end()) - out.begin());
    }
};

double cross_entropy_loss(const vector<double>& prediction, const vector<double>& target) {
    double loss = 0;
    for (size_t i = 0; i < prediction.size(); ++i)
        loss -= target[i] * log(prediction[i] + 1e-9);
    return loss;
}

int main() {
    // Example: classify 3 classes with 2D input

    vector<vector<double>> X = {
        {0.0, 0.0},
        {1.0, 0.0},
        {0.0, 1.0},
        {1.0, 1.0},
        {0.5, 0.5},
        {0.8, 0.2},
        {0.2, 0.9},
        {0.9, 0.9}
    };

    vector<vector<double>> Y = {
        {1,0,0},
        {0,1,0},
        {0,1,0},
        {0,0,1},
        {1,0,0},
        {0,1,0},
        {1,0,0},
        {0,0,1}
    };

    MLP net(2, {8, 8}, 3);

    int epochs = 10000;
    double lr = 0.01;

    for (int e = 0; e < epochs; ++e) {
        double epoch_loss = 0;
        for (size_t i = 0; i < X.size(); ++i) {
            net.forward(X[i]);
            epoch_loss += cross_entropy_loss(net.activations.back(), Y[i]);
            net.backward(Y[i], lr);
        }
        if (e % 1000 == 0)
            cout << "Epoch " << e << ", loss = " << epoch_loss << "\n";
    }

    cout << "Predictions:\n";
    for (size_t i = 0; i < X.size(); ++i) {
        int pred = net.predict(X[i]);
        cout << "Input: (" << X[i][0] << ", " << X[i][1] << ") -> Class " << pred << "\n";
    }
}
