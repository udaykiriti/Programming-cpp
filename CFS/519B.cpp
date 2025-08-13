#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(0);
    int n, t; cin >> n;
    int a = 0, b = 0, c = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> t;
        a += t;
    }

    for (int i = 0; i < n - 1; i++)
    {
        cin >> t;
        b += t;
    }

    for (int i = 0; i < n - 2; i++)
    {
        cin >> t;
        c += t;
    }
    cout << a - b << endl;
    cout << b - c << endl;
    return 0;
}