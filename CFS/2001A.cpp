#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        unordered_map<int, int> freq;
        int mx = 0;
        for (int x : a) {
            freq[x]++;
            mx = max(mx, freq[x]);
        }
        cout << (n - mx) << "\n";
    }
    return 0;
}
