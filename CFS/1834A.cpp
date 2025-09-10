#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;

        sort(a.begin(), a.end());
        int sum = accumulate(a.begin(), a.end(), 0);
        int negativeCount = count_if(a.begin(), a.end(), [](int x){ return x < 0; });

        if (sum >= 0 && negativeCount % 2 == 0) {
            cout << 0 << "\n";
            continue;
        }
        int flips = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < 0) {
                sum += (-2 * a[i]); 
                flips++;
                negativeCount--;
            }
            if (sum >= 0 && negativeCount % 2 == 0) break;
        }
        cout << flips << "\n";
    }
    return 0;
}
