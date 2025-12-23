#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        ll n, l, r, k; cin >> n >> l >> r >> k;
        if (n % 2 == 1)
            cout << l << "\n";
        else
        {
            int c = 0;
            ll x = l;
            while (x > 0)
                x /= 2, c++;
            ll p = 1LL << c;
            if (n == 2)
                cout << -1 << "\n";
            else if (p <= r)
                if (k < n - 1) cout << l << "\n";
                else cout << p << "\n";
            else cout << -1 << "\n";
        }
    }
    return 0;
}