#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
 
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int hikes = 0;
        for (int i = 0; i <= n - k; ) {
            bool can_hike = true;
            for (int j = 0; j < k; j++) {
                if (a[i + j] == 1) {
                    can_hike = false;
                    break;
                }
            }
            if (can_hike) {
                hikes++;
                i += k + 1;
            } else {
                i++;
            }
        }
        cout << hikes << "\n";
    }
    return 0;
}
