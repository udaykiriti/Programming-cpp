#include <bits/stdc++.h>
using namespace std;

// Smallest possible sum after repeated subtraction operations
// Answer = gcd of all elements * n

unsigned long long arrayGcdSum(vector<unsigned long long> &a) {
    unsigned long long g = a[0];
    for (int i = 1; i < (int)a.size(); i++) {
        g = gcd(g, a[i]);
    }
    return g * a.size();
}

int main() {
    int n;
    cin >> n;

    vector<unsigned long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << arrayGcdSum(a) << "\n";
    return 0;
}
