#include <bits/stdc++.h>

using namespace std;

vector<double> matVecMultiply(const vector<vector<double>>& mat, const vector<double>& vec) {
    vector<double> result(mat.size(), 0.0);
    for (size_t i = 0; i < mat.size(); ++i) {
        for (size_t j = 0; j < vec.size(); ++j) {
            result[i] += mat[i][j] * vec[j];
        }
    }
    return result;
}

vector<vector<double>> transpose(const vector<vector<double>>& mat) {
    if (mat.empty()) return {};
    vector<vector<double>> result(mat[0].size(), vector<double>(mat.size()));
    for (size_t i = 0; i < mat.size(); ++i) 
        for (size_t j = 0; j < mat[0].size(); ++j) 
            result[j][i] = mat[i][j];
    return result;
}

vector<vector<double>> matMultiply(const vector<vector<double>>& A, const vector<vector<double>>& B) {
    size_t n = A.size(), m = B[0].size(), p = B.size();
    vector<vector<double>> result(n, vector<double>(m, 0.0));
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < m; ++j)
            for (size_t k = 0; k < p; ++k)
                result[i][j] += A[i][k] * B[k][j];
    return result;
}

void gradientDescent(const vector<vector<double>>& X, const vector<double>& y, vector<double>& theta,
                     double alpha, int iterations) {
    size_t m = y.size();
    size_t n = theta.size();

    for (int iter = 0; iter < iterations; ++iter) {
        vector<double> predictions(m, 0.0);
        for (size_t i = 0; i < m; ++i) {
            double pred = 0.0;
            for (size_t j = 0; j < n; ++j)
                pred += X[i][j] * theta[j];
            predictions[i] = pred;
        }

        vector<double> errors(m, 0.0);
        for (size_t i = 0; i < m; ++i)
            errors[i] = predictions[i] - y[i];

        for (size_t j = 0; j < n; ++j) {
            double gradient = 0.0;
            for (size_t i = 0; i < m; ++i) {
                gradient += errors[i] * X[i][j];
            }
            theta[j] -= alpha * gradient / m;
        }
    }
}

bool readCSVMultifeature(const string& filename, vector<vector<double>>& X, vector<double>& y) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return false;
    }

    string line;
    getline(file, line); // skip header

    while (getline(file, line)) {
        stringstream ss(line);
        string item;
        vector<double> features;

        while (getline(ss, item, ',')) {
            features.push_back(stod(item));
        }

        y.push_back(features.back());
        features.pop_back();
        features.insert(features.begin(), 1.0);

        X.push_back(features);
    }

    file.close();
    return true;
}

double predictMultifeature(const vector<double>& features, const vector<double>& theta) {
    double prediction = 0.0;
    for (size_t i = 0; i < features.size(); ++i)
        prediction += features[i] * theta[i];
    return prediction;
}

int main() {
    vector<vector<double>> features;
    vector<double> prices;

    if (!readCSVMultifeature("data_multifeature.csv", features, prices)) {
        return 1;
    }

    vector<double> theta(features[0].size(), 0.0); 

    double learning_rate = 0.0000001;
    int iterations = 100000;

    gradientDescent(features, prices, theta, learning_rate, iterations);

    cout << "Model trained with multiple features!" << endl;
    cout << "Weights:" << endl;
    for (size_t i = 0; i < theta.size(); ++i) {
        if (i == 0)
            cout << "Intercept: " << theta[i] << endl;
        else
            cout << "Feature " << i << ": " << theta[i] << endl;
    }
    cout << endl;

    vector<double> newHouse = {1.0, 1800, 3, 5}; // 1.0 for intercept, 1800 sqft, 3 bedrooms, 5 years old
    double predictedPrice = predictMultifeature(newHouse, theta);
    cout << "Predicting price for new house (area=1800, bedrooms=3, age=5)..." << endl;
    cout << "Estimated price: $" << predictedPrice * 1000 << endl;

    return 0;
}