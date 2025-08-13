#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define EXIT return 0
#define input(x) cin >> x
#define FOR(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    int t;
    input(t);
    int x;
    int n;
    FOR(i, 0, t)
    {
        input(n);
        n += 1;
        x = n / 10;
        cout << x << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    EXIT;
}