#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (auto &x : a) cin >> x;
        vector<int> b(k);
        for (auto &x : b) cin >> x;

        // Max-heap for products
        priority_queue<long long> pq(a.begin(), a.end());

        // Sort vouchers ascending
        sort(b.begin(), b.end());

        long long total = 0;

        for (int bi : b) {
            if (bi > (int)pq.size()) continue; // safety
            vector<long long> taken;
            for (int j = 0; j < bi; j++) {
                taken.push_back(pq.top());
                pq.pop();
            }
            // Free the smallest in the group
            long long freeItem = *min_element(taken.begin(), taken.end());
            for (auto x : taken) {
                if (x != freeItem) total += x;
                else {
                    freeItem = -1; // ensure only one free
                }
            }
        }

        // Remaining items in heap are fully paid
        while (!pq.empty()) {
            total += pq.top();
            pq.pop();
        }

        cout << total << "\n";
    }
}
