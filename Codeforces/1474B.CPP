#include <bits/stdc++.h>
using namespace std;

string lcmString(const string &a, const string &b) {
    if (a + b != b + a) return "-1";
    int l = lcm((int)a.size(), (int)b.size());
    string res;
    while ((int)res.size() < l) res += a;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        string s, t2;
        cin >> s >> t2;
        cout << lcmString(s, t2) << "\n";
    }
    return 0;
}
