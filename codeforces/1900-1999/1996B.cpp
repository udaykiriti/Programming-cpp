#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
    int n, k; cin >> n >> k;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<string> w(n / k, string(n / k, '0'));
    for (int row = 0; row < n; row += k)
        for (int col = 0; col < n; col += k)
            w[row / k][col / k] = v[row][col];

    for (int i = 0; i < w.size(); i++)
        cout << w[i] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}