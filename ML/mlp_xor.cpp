#include <bits/stdc++.h>
/*
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
*/
using namespace std;

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double sigmoid_deriv(double y) {
    return y * (1 - y);
}

struct NeuralNet {
    int inputCount, hiddenCount, outputCount;
    vector<vector<double>> wInputHidden;
    vector<vector<double>> wHiddenOutput;
    vector<double> hiddenVals;
    vector<double> outputVals;

    NeuralNet(int inputs, int hidden, int outputs)
        : inputCount(inputs), hiddenCount(hidden), outputCount(outputs),
          wInputHidden(hidden, vector<double>(inputs)),
          wHiddenOutput(outputs, vector<double>(hidden)),
          hiddenVals(hidden), outputVals(outputs) {
        srand(time(0));
        for (auto &row : wInputHidden)
            for (auto &w : row)
                w = ((double)rand() / RAND_MAX) * 2 - 1;
        for (auto &row : wHiddenOutput)
            for (auto &w : row)
                w = ((double)rand() / RAND_MAX) * 2 - 1;
    }

    vector<double> forward(const vector<double> &inputs) {
        for (int i = 0; i < hiddenCount; ++i) {
            double sum = 0;
            for (int j = 0; j < inputCount; ++j)
                sum += wInputHidden[i][j] * inputs[j];
            hiddenVals[i] = sigmoid(sum);
        }
        for (int i = 0; i < outputCount; ++i) {
            double sum = 0;
            for (int j = 0; j < hiddenCount; ++j)
                sum += wHiddenOutput[i][j] * hiddenVals[j];
            outputVals[i] = sigmoid(sum);
        }
        return outputVals;
    }

    void train(const vector<vector<double>> &inputs, const vector<vector<double>> &targets, double lr, int epochs) {
        for (int e = 0; e < epochs; ++e) {
            double errorSum = 0;
            for (int n = 0; n < (int)inputs.size(); ++n) {
                vector<double> out = forward(inputs[n]);
                vector<double> outErr(outputCount);
                for (int i = 0; i < outputCount; ++i) {
                    outErr[i] = targets[n][i] - out[i];
                    errorSum += outErr[i] * outErr[i];
                }
                vector<double> outDelta(outputCount);
                for (int i = 0; i < outputCount; ++i)
                    outDelta[i] = outErr[i] * sigmoid_deriv(out[i]);

                vector<double> hidErr(hiddenCount, 0);
                for (int i = 0; i < hiddenCount; ++i)
                    for (int j = 0; j < outputCount; ++j)
                        hidErr[i] += outDelta[j] * wHiddenOutput[j][i];

                vector<double> hidDelta(hiddenCount);
                for (int i = 0; i < hiddenCount; ++i)
                    hidDelta[i] = hidErr[i] * sigmoid_deriv(hiddenVals[i]);

                for (int i = 0; i < outputCount; ++i)
                    for (int j = 0; j < hiddenCount; ++j)
                        wHiddenOutput[i][j] += lr * outDelta[i] * hiddenVals[j];

                for (int i = 0; i < hiddenCount; ++i)
                    for (int j = 0; j < inputCount; ++j)
                        wInputHidden[i][j] += lr * hidDelta[i] * inputs[n][j];
            }
            if (e % 1000 == 0)
                cout << "Epoch " << e << " error " << errorSum << endl;
        }
    }
};

int main() {
    vector<vector<double>> inputData = {
        {0, 0, 1},
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    vector<vector<double>> targetData = {
        {0},
        {1},
        {1},
        {0}
    };

    NeuralNet net(3, 4, 1);
    net.train(inputData, targetData, 0.5, 10000);

    for (auto &input : inputData) {
        auto output = net.forward(input);
        cout << input[0] << " XOR " << input[1] << " = " << round(output[0]) << " (" << output[0] << ")\n";
    }
<<<<<<< HEAD
<<<<<<< HEAD
}
=======
}
>>>>>>> 07c3463 (c++ ml)
=======
}
>>>>>>> 5ac2cfa (Fixes missing newline in source file)
