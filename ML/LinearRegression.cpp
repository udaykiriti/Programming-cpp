#include <bits/stdc++.h>
using namespace std;

double calculateMean(const vector<double>& values) {
    double sum = 0.0;
    for (double value : values) 
        sum += value;
    return sum / values.size();
}

void trainLinearRegression(const vector<double>& inputs, const vector<double>& outputs, double& slope, double& intercept) {
    double xMean = calculateMean(inputs);
    double yMean = calculateMean(outputs);

    double numerator = 0.0;
    double denominator = 0.0;

    for (size_t i = 0; i < inputs.size(); ++i) {
        numerator   += (inputs[i] - xMean) * (outputs[i] - yMean);
        denominator += (inputs[i] - xMean) * (inputs[i] - xMean);
    }

    slope = numerator / denominator;
    intercept = yMean - slope * xMean;
}

double predictPrice(double area, double slope, double intercept) {
    return slope * area + intercept;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    vector<double> houseAreas = {1000, 1500, 2000, 2500, 3000};    
    vector<double> housePrices = {200, 300, 400, 500, 600};        

    double slope (0.0);
    double intercept (0.0);

    trainLinearRegression(houseAreas, housePrices, slope, intercept);
    cout << " Model trained!" << endl;
    cout << " Price = " << slope << " * Area + " << intercept << endl << endl;
    double newHouseArea = 1800;
    double predictedPrice = predictPrice(newHouseArea, slope, intercept);
    cout << " Predicting price for house with area " << newHouseArea << " sqft..." << endl;
    cout << " Estimated price: $" << predictedPrice * 1000 << endl;
    return 0;
}
