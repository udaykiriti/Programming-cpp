#include <bits/stdc++.h>
using namespace std;

double calculateMean(const vector<double>& values) {
    double sum{0.0};
    for (double value : values) {
        sum += value;
    }
    return sum / values.size();
}

void trainLinearRegression(const vector<double>& inputs, const vector<double>& outputs, double& slope, double& intercept) {
    double xMean = calculateMean(inputs);
    double yMean = calculateMean(outputs);

    double numerator = 0.0;
    double denominator = 0.0;

    for (size_t i = 0; i < inputs.size(); ++i) {
        numerator += (inputs[i] - xMean) * (outputs[i] - yMean);
        denominator += (inputs[i] - xMean) * (inputs[i] - xMean);
    }

    slope = numerator / denominator;
    intercept = yMean - slope * xMean;
}

double predictPrice(double area, double slope, double intercept) {
    return slope * area + intercept;
}

bool readCSV(const string& filename, vector<double>& x, vector<double>& y) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << '\n';
        return false;
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string item;
        double area, price;

        getline(ss, item, ',');
        area = stod(item);

        getline(ss, item, ',');
        price = stod(item);

        x.push_back(area);
        y.push_back(price);
    }

    file.close();
    return true;
}

int main() {
    vector<double> areas;
    vector<double> prices;

    string filename = "data.csv";

    if (!readCSV(filename, areas, prices)) {
        return 1;
    }

    double slope = 0.0;
    double intercept = 0.0;

    trainLinearRegression(areas, prices, slope, intercept);

    cout << "Model trained!" << '\n';
    cout << "Price = " << slope << " * Area + " << intercept << '\n' << '\n';

    double newHouseArea = 1800;
    double predictedPrice = predictPrice(newHouseArea, slope, intercept);

    cout << "Predicting price for house with area " << newHouseArea << " sqft..." << '\n';
    cout << "Estimated price: $" << predictedPrice * 1000 << '\n';

    return 0;
}
