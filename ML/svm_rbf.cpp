#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

class SVM {
    vector<vector<double>> X;
    vector<int> y;
    vector<double> alphas;
    double b;
    double C;
    double tol;
    double eps;
    double gamma;
    int max_passes;

public:
    SVM(double C = 1.0, double tol = 1e-3, double eps = 1e-3, double gamma = 0.5, int max_passes = 5)
        : C(C), tol(tol), eps(eps), gamma(gamma), max_passes(max_passes), b(0.0) {}

    double kernel(const vector<double>& xi, const vector<double>& xj) {
        double sum = 0.0;
        for (size_t i = 0; i < xi.size(); ++i)
            sum += (xi[i] - xj[i]) * (xi[i] - xj[i]);
        return exp(-gamma * sum);
    }

    double f(const vector<double>& x) {
        double result = -b;
        for (size_t i = 0; i < X.size(); ++i)
            result += alphas[i] * y[i] * kernel(X[i], x);
        return result;
    }

    void train(const vector<vector<double>>& X_train, const vector<int>& y_train) {
        X = X_train;
        y = y_train;
        int m = X.size();
        alphas.assign(m, 0.0);
        b = 0.0;
        int passes = 0;

        while (passes < max_passes) {
            int num_changed = 0;
            for (int i = 0; i < m; ++i) {
                double Ei = f(X[i]) - y[i];
                if ((y[i]*Ei < -tol && alphas[i] < C) || (y[i]*Ei > tol && alphas[i] > 0)) {
                    int j = i;
                    while (j == i)
                        j = rand() % m;
                    double Ej = f(X[j]) - y[j];
                    double alpha_i_old = alphas[i];
                    double alpha_j_old = alphas[j];

                    double L, H;
                    if (y[i] != y[j]) {
                        L = max(0.0, alphas[j] - alphas[i]);
                        H = min(C, C + alphas[j] - alphas[i]);
                    } else {
                        L = max(0.0, alphas[i] + alphas[j] - C);
                        H = min(C, alphas[i] + alphas[j]);
                    }

                    if (L == H) continue;

                    double eta = 2 * kernel(X[i], X[j]) - kernel(X[i], X[i]) - kernel(X[j], X[j]);
                    if (eta >= 0) continue;

                    alphas[j] -= y[j] * (Ei - Ej) / eta;
                    if (alphas[j] > H) alphas[j] = H;
                    else if (alphas[j] < L) alphas[j] = L;

                    if (abs(alphas[j] - alpha_j_old) < eps) continue;

                    alphas[i] += y[i]*y[j]*(alpha_j_old - alphas[j]);

                    double b1 = b + Ei + y[i]*(alphas[i] - alpha_i_old)*kernel(X[i], X[i])
                                + y[j]*(alphas[j] - alpha_j_old)*kernel(X[i], X[j]);
                    double b2 = b + Ej + y[i]*(alphas[i] - alpha_i_old)*kernel(X[i], X[j])
                                + y[j]*(alphas[j] - alpha_j_old)*kernel(X[j], X[j]);

                    if (0 < alphas[i] && alphas[i] < C)
                        b = b1;
                    else if (0 < alphas[j] && alphas[j] < C)
                        b = b2;
                    else
                        b = (b1 + b2) / 2.0;

                    num_changed++;
                }
            }

            if (num_changed == 0)
                passes++;
            else
                passes = 0;
        }
    }

    int predict(const vector<double>& x) {
        return f(x) >= 0 ? 1 : -1;
    }
};

int main() {
    vector<vector<double>> X = {
        {2.0, 2.0},
        {1.0, 1.0},
        {2.0, 0.0},
        {0.0, 0.0},
        {0.0, 1.0},
        {1.0, 0.0}
    };

    vector<int> y = {1, 1, 1, -1, -1, -1};

    SVM svm(1.0, 1e-3, 1e-3, 0.5, 10);
    svm.train(X, y);

    for (const auto& x : X)
        cout << x[0] << " " << x[1] << " => " << svm.predict(x) << endl;

    return 0;
}
