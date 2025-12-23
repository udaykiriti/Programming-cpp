#include <bits/stdc++.h>
#define endl '\n'
#define FOR(i,a,b) for(int i=a;i<b;i++)

void solve() {
    int n; std::cin >> n;
    std::vector<int> a(n); 
    for (int& x : a) std::cin >> x;
    std::string s(n, '0');
    int m = INT_MAX;
    FOR (i,0,n) {
        m = std::min(m, a[i]);
        if (a[i] == m) s[i] = '1';
    }
    m = INT_MIN;
    for (int i = n - 1; i >= 0; --i) {
        m = std::max(m, a[i]);
        if (a[i] == m) s[i] = '1';
    }
    std::cout << s << endl;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    int t; if(!std::cin >> t) return 0;
    while (t--) solve();
    return 0;
}