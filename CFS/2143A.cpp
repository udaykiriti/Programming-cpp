#include <bits/stdc++.h>
using namespace std;

bool iscan(vector<int>& p) {
    int n = p.size();
    for (int i = 1; i < n - 1; i++) 
        if (p[i] < p[i - 1] && p[i] < p[i + 1]) 
            return false; 
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) cin >> p[i];
        if (iscan(p)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}