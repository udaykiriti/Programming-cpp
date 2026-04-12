#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define endl '\n'
#define ALL(v) v.begin(), v.end()
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define SZ(x) ((int)(x).size())

#define DBG(x...) cerr << "[" << #x << "] = ["; _print(x); cerr << "]" << endl;
void _print() {}
template <typename T, typename... V>
void _print(T t, V... v) { cerr << t; if (sizeof...(v)) cerr << ", "; _print(v...); }

const int MOD = 1e9 + 7;
const int INF = 1e9;

class Solution {
public:
    int solve(vector<int>& v) {
        int n = SZ(v);

        return n > 0 ? v[0] : -1;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("in.txt", "r")) {
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    }

    int n;
    while (cin >> n) {
        vector<int> v(n);
        FOR(i, 0, n) cin >> v[i];

        Solution sol;
        auto res = sol.solve(v);
        cout << res << endl;
    }

    return 0;
}
