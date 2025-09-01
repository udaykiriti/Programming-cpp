/*
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
*/
#include<bits/stdc++.h>
using namespace std;

double relu(double x) {
    return x > 0 ? x : 0;
}

double relu_deriv(double y) {
    return y > 0 ? 1 : 0;
}

struct NeuralNetwork {
    int inputSize, hiddenSize, outputSize;
    vector<vector<double>> wInputHidden;
    vector<vector<double>> wHiddenOutput;
    vector<double> hiddenLayer;
    vector<double> outputLayer;

    NeuralNetwork(int inputs, int hidden, int outputs)
        : inputSize(inputs), hiddenSize(hidden), outputSize(outputs),
          wInputHidden(hidden, vector<double>(inputs)),
          wHiddenOutput(outputs, vector<double>(hidden)),
          hiddenLayer(hidden), outputLayer(outputs) {
        srand(time(0));
        for (auto &row : wInputHidden)
            for (auto &w : row)
                w = ((double)rand() / RAND_MAX) * 2 - 1;
        for (auto &row : wHiddenOutput)
            for (auto &w : row)
                w = ((double)rand() / RAND_MAX) * 2 - 1;
    }

    vector<double> forward(const vector<double>& inputs) {
        for (int i = 0; i < hiddenSize; ++i) {
            double sum = 0;
            for (int j = 0; j < inputSize; ++j)
                sum += wInputHidden[i][j] * inputs[j];
            hiddenLayer[i] = relu(sum);
        }
        for (int i = 0; i < outputSize; ++i) {
            double sum = 0;
            for (int j = 0; j < hiddenSize; ++j)
                sum += wHiddenOutput[i][j] * hiddenLayer[j];
            outputLayer[i] = sum;  
        }
        return outputLayer;
    }

    void train(const vector<vector<double>>& X, const vector<vector<double>>& Y, double lr, int epochs) {
        for (int e = 0; e < epochs; ++e) {
            double loss = 0;
            for (int n = 0; n < (int)X.size(); ++n) {
                forward(X[n]);
                vector<double> outputErrors(outputSize);
                for (int i = 0; i < outputSize; ++i) {
                    outputErrors[i] = Y[n][i] - outputLayer[i];
                    loss += outputErrors[i] * outputErrors[i];
                }
                vector<double> outputDeltas(outputSize);
                for (int i = 0; i < outputSize; ++i)
                    outputDeltas[i] = outputErrors[i];  // Linear output

                vector<double> hiddenErrors(hiddenSize, 0);
                for (int i = 0; i < hiddenSize; ++i)
                    for (int j = 0; j < outputSize; ++j)
                        hiddenErrors[i] += outputDeltas[j] * wHiddenOutput[j][i];

                vector<double> hiddenDeltas(hiddenSize);
                for (int i = 0; i < hiddenSize; ++i)
                    hiddenDeltas[i] = hiddenErrors[i] * relu_deriv(hiddenLayer[i]);

                for (int i = 0; i < outputSize; ++i)
                    for (int j = 0; j < hiddenSize; ++j)
                        wHiddenOutput[i][j] += lr * outputDeltas[i] * hiddenLayer[j];

                for (int i = 0; i < hiddenSize; ++i)
                    for (int j = 0; j < inputSize; ++j)
                        wInputHidden[i][j] += lr * hiddenDeltas[i] * X[n][j];
            }
            if (e % 1000 == 0)
                cout << "Epoch " << e << " loss: " << loss << "\n";
        }
    }
};

int main() {
    vector<vector<double>> inputs = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1}
    };

    vector<vector<double>> targets = {
        {0},
        {1},
        {1},
        {0}
    };

    NeuralNetwork nn(2, 4, 1);
    nn.train(inputs, targets, 0.1, 10000);

    for (auto &input : inputs) {
        auto output = nn.forward(input);
        cout << input[0] << " XOR " << input[1] << " = " << output[0] << "\n";
    }
}
