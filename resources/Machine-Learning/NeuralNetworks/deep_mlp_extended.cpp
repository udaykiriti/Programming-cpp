#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

struct MLP {
    int input_size, output_size;
    vector<int> hidden_layers;
    vector<vector<vector<double>>> weights;
    vector<vector<double>> biases;
    vector<vector<double>> activations;
    vector<vector<double>> zs;

    MLP(int input_sz, vector<int> hidden, int output_sz)
        : input_size(input_sz), hidden_layers(hidden), output_size(output_sz) {
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
                    activations[l + 1][j] = sum;
                else
                    activations[l + 1][j] = relu(sum);
            }
        }
        activations.back() = softmax(activations.back());
        return activations.back();
    }

    void backward(const vector<double>& target, vector<vector<vector<double>>>& grad_w,
                  vector<vector<double>>& grad_b) {
        int L = (int)weights.size();
        vector<vector<double>> delta(L);

        delta[L - 1].resize(output_size);
        for (int i = 0; i < output_size; ++i)
            delta[L - 1][i] = activations[L][i] - target[i];

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
                    grad_w[l][j][k] += delta[l][j] * activations[l][k];
                }
                grad_b[l][j] += delta[l][j];
            }
        }
    }

    void updateWeights(const vector<vector<vector<double>>>& grad_w, const vector<vector<double>>& grad_b,
                       int batch_size, double lr) {
        int L = (int)weights.size();
        for (int l = 0; l < L; ++l) {
            for (size_t j = 0; j < weights[l].size(); ++j) {
                for (size_t k = 0; k < weights[l][j].size(); ++k) {
                    weights[l][j][k] -= lr * grad_w[l][j][k] / batch_size;
                }
                biases[l][j] -= lr * grad_b[l][j] / batch_size;
            }
        }
    }

    void saveWeights(const string& filename) {
        ofstream file(filename, ios::binary);
        if (!file) {
            cerr << "Cannot open file to save weights.\n";
            return;
        }
        int L = (int)weights.size();
        file.write((char*)&input_size, sizeof(int));
        int hidden_size = (int)hidden_layers.size();
        file.write((char*)&hidden_size, sizeof(int));
        for (int x : hidden_layers)
            file.write((char*)&x, sizeof(int));
        file.write((char*)&output_size, sizeof(int));

        for (int l = 0; l < L; ++l) {
            int rows = (int)weights[l].size();
            int cols = (int)weights[l][0].size();
            file.write((char*)&rows, sizeof(int));
            file.write((char*)&cols, sizeof(int));
            for (int i = 0; i < rows; ++i)
                file.write((char*)weights[l][i].data(), sizeof(double) * cols);

            file.write((char*)biases[l].data(), sizeof(double) * rows);
        }
        file.close();
    }

    void loadWeights(const string& filename) {
        ifstream file(filename, ios::binary);
        if (!file) {
            cerr << "Cannot open file to load weights.\n";
            return;
        }
        int L = (int)weights.size();
        int in_sz, hidden_size, out_sz;
        file.read((char*)&in_sz, sizeof(int));
        file.read((char*)&hidden_size, sizeof(int));
        vector<int> hidden(hidden_size);
        for (int& x : hidden)
            file.read((char*)&x, sizeof(int));
        file.read((char*)&out_sz, sizeof(int));

        if (in_sz != input_size || hidden != hidden_layers || out_sz != output_size) {
            cerr << "Model architecture mismatch on loading weights.\n";
            file.close();
            return;
        }

        for (int l = 0; l < L; ++l) {
            int rows, cols;
            file.read((char*)&rows, sizeof(int));
            file.read((char*)&cols, sizeof(int));
            for (int i = 0; i < rows; ++i)
                file.read((char*)weights[l][i].data(), sizeof(double) * cols);
            file.read((char*)biases[l].data(), sizeof(double) * rows);
        }
        file.close();
    }
};

double cross_entropy_loss(const vector<double>& prediction, const vector<double>& target) {
    double loss = 0;
    for (size_t i = 0; i < prediction.size(); ++i)
        loss -= target[i] * log(prediction[i] + 1e-9);
    return loss;
}

void shuffle_data(vector<vector<double>>& X, vector<vector<double>>& Y) {
    random_device rd;
    mt19937 g(rd());
    for (size_t i = X.size() - 1; i > 0; --i) {
        uniform_int_distribution<size_t> distrib(0, i);
        size_t j = distrib(g);
        swap(X[i], X[j]);
        swap(Y[i], Y[j]);
    }
}

int main() {
    vector<vector<double>> X = {
        {0.0, 0.0}, {1.0, 0.0}, {0.0, 1.0}, {1.0, 1.0},
        {0.5, 0.5}, {0.8, 0.2}, {0.2, 0.9}, {0.9, 0.9}
    };

    vector<vector<double>> Y = {
        {1, 0, 0}, {0, 1, 0}, {0, 1, 0}, {0, 0, 1},
        {1, 0, 0}, {0, 1, 0}, {1, 0, 0}, {0, 0, 1}
    };

    MLP net(2, {8, 8}, 3);

    int epochs = 5000;
    int batch_size = 2;
    double lr = 0.01;

    for (int e = 0; e < epochs; ++e) {
        shuffle_data(X, Y);
        double epoch_loss = 0;

        for (size_t start = 0; start < X.size(); start += batch_size) {
            vector<vector<vector<double>>> grad_w = net.weights;
            vector<vector<double>> grad_b = net.biases;
            // Initialize grads to zero
            for (auto& mat : grad_w)
                for (auto& row : mat)
                    fill(row.begin(), row.end(), 0.0);
            for (auto& vec : grad_b)
                fill(vec.begin(), vec.end(), 0.0);

            size_t end = min(start + batch_size, X.size());

            for (size_t i = start; i < end; ++i) {
                net.forward(X[i]);
                epoch_loss += cross_entropy_loss(net.activations.back(), Y[i]);
                net.backward(Y[i], grad_w, grad_b);
            }

            net.updateWeights(grad_w, grad_b, (int)(end - start), lr);
        }

        if (e % 500 == 0)
            cout << "Epoch " << e << ", Loss: " << epoch_loss / X.size() << endl;
    }

    net.saveWeights("model_weights.bin");
    cout << "Weights saved.\n";

    // Reload to test
    MLP net2(2, {8, 8}, 3);
    net2.loadWeights("model_weights.bin");
    cout << "Weights loaded.\n";

    cout << "Predictions after loading:\n";
    for (size_t i = 0; i < X.size(); ++i) {
        int pred = net2.predict(X[i]);
        cout << "Input: (" << X[i][0] << ", " << X[i][1] << ") -> Class " << pred << "\n";
    }

    return 0;
}
