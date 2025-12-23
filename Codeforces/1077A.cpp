#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t; cin >> t;
    ll a, b, k, TwoSteps;
    while(t--)
    {
        cin >> a >> b>> k;
        TwoSteps = a - b;
        if(k % 2 == 0) 
            cout << TwoSteps * k / 2 << endl;
        else 
            cout << TwoSteps * (k / 2) + a << endl;
    }
    return 0;
}
