#include <bits/stdc++.h>
using namespace std;

// Count inversions using merge sort
// Time: O(n log n)

long long mergeCount(vector<int> &a, int l, int m, int r) {
    vector<int> temp;
    int i = l;
    int j = m + 1;
    long long inv = 0;

    while (i <= m && j <= r) {
        if (a[i] <= a[j]) {
            temp.push_back(a[i++]);
        } else {
            temp.push_back(a[j++]);
            inv += (m - i + 1);
        }
    }

    while (i <= m) {
        temp.push_back(a[i++]);
    }

    while (j <= r) {
        temp.push_back(a[j++]);
    }

    for (int k = l; k <= r; k++) {
        a[k] = temp[k - l];
    }

    return inv;
}

long long countInversions(vector<int> &a, int l, int r) {
    if (l >= r) {
        return 0;
    }

    int m = (l + r) / 2;
    long long inv = 0;
    inv += countInversions(a, l, m);
    inv += countInversions(a, m + 1, r);
    inv += mergeCount(a, l, m, r);
    return inv;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << countInversions(a, 0, n - 1) << "\n";
    return 0;
}
