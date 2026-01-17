#include <bits/stdc++.h>
#define endl '\n'
#define YES std::cout << "YES" << endl
#define NO std::cout << "NO" << endl
#define debug(x) std::cout << (x) << endl

void solve() {
    int a, b, c; std::cin >> a >> b >> c;
    std::vector<int> vec(a);
    for (auto &e : vec) std::cin >> e;
    if (c > 1) {
        YES;
    } else {
        int f = *std::max_element(vec.begin(), vec.end());
        if (vec[b - 1] == f) YES;
        else NO;
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    int t; if(!std::cin >> t) return 0;
    while (t--) solve();
}