#include <mlpack/core.hpp>
#include <mlpack/methods/linear_regression/linear_regression.hpp>
#include <armadillo>

using namespace mlpack;
using namespace mlpack::regression;
using namespace arma;
using namespace std;

int main(){
    mat X;
    rowvec y;
    data::Load("data_multifeature.csv", X, true);
    LinearRegression lr(X, y);

    rowvec point = {1800, 3, 5};
    double prediction;
    lr.Predict(point, prediction);

    cout << "Predicted price: $" << prediction * 1000 << endl;

    return 0;
}
