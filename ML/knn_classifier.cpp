/*
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
*/
#include<bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
    int label;
};

double distance(const Point& a, const Point& b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

int predictLabel(const vector<Point>& trainingData, const Point& testPoint, int k) {
    vector<pair<double, int>> distances;
    for (const auto& p : trainingData) {
        double dist = distance(p, testPoint);
        distances.push_back({dist, p.label});
    }
    sort(distances.begin(), distances.end());

    int count0 = 0, count1 = 0;
    for (int i = 0; i < k; ++i) {
        if (distances[i].second == 0) count0++;
        else count1++;
    }
    return (count1 > count0) ? 1 : 0;
}

int main() {
    vector<Point> training = {
        {1.0, 2.0, 0}, {2.0, 3.0, 0}, {3.0, 3.0, 0},
        {6.0, 5.0, 1}, {7.0, 7.0, 1}, {8.0, 6.0, 1}
    };

    vector<Point> testPoints = {
        {2.5, 2.5, -1},
        {7.0, 5.0, -1}
    };

    int k = 3;

    for (const auto& pt : testPoints) {
        int pred = predictLabel(training, pt, k);
        cout << "Point (" << pt.x << ", " << pt.y << ") predicted label: " << pred << "\n";
    }
}
