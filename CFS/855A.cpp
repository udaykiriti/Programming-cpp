#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    unordered_set<string> s;
    while (n--) {
        string x; cin >> x;
        cout << (s.count(x) ? "YES\n" : "NO\n");
        s.insert(x);
    }
}
