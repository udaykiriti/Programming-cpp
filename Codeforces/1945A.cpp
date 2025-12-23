#include <iostream>
using namespace std;

void solve()
{
    int a, b, c, ans; cin >> a >> b >> c;
    ans = a + b / 3;
    b %= 3;

    if (b && c < 3 - b)
    {
        cout << -1 << endl;
        return;
    }

    if (b)
    {
        ans++;
        c -= 3 - b;
    }

    ans += c / 3;
    if (c % 3) ans++;

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
}
