#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

void solve() {
    int n; cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];
    
    if (n == 1) {
        cout << vec[0] << "\n";
        return;
    }
    
    sort(vec.begin(), vec.end(), cmp);
    
    for (int i = 0; i < n; i++) 
        cout << vec[i] << (i == n - 1 ? '\n' : ' ');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
