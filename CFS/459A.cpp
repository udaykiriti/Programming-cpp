#include <bits/stc++.h>
using namespace std;
#define ll long long

int main(){
    ll x1, y1, x2, y2;
    while (cin >> x1 >> y1 >> x2 >> y2)
    {
        ll dx = abs(x1 - x2), dy = abs(y1 - y2);
        if (dx == dy)
            cout << x1 << " " << y2 << " " << x2 << " " << y1 << endl;
        else if (x1 == x2)
            cout << x1 + dy << " " << y1 << " " << x2 + dy << " " << y2 << endl;
        else if (y1 == y2)
            cout << x1 << " " << y1 + dx << " " << x2 << " " << y2 + dx << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
