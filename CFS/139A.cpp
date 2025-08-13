#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i = 0, a[7];
    cin >> n;
    for (int j = 0; j < 7; j++)
        cin >> a[j];

    int t = a[0];
    while (t < n)
    {
        i++;
        i %= 7;
        t += a[i];
    }
    cout << i + 1 << endl;
    return 0;
}