/******************************
 *    author:  uday           *
 *    created: 18 12:18:31    *
 ******************************/

#undef _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define vi vector<int>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

void solve() {
    int xa, ya, xb, yb, xf, yf;
    cin >> xa >> ya >> xb >> yb >> xf >> yf;

    int moves(0);

    if (xa == xb) {
        if (xf == xa) {
            if (ya > yb) {
                if (yf > yb && yf < ya)
                    moves = ya - yb + 2;
                else
                    moves = ya - yb;
            } else {
                if (yf < yb && yf > ya)
                    moves = yb - ya + 2;
                else
                    moves = yb - ya;
            }
        } else {
            moves = abs(ya - yb);
        }
    } else if (ya == yb) {
        if (yf == ya) {
            if (xa > xb) {
                if (xf > xb && xf < xa)
                    moves = xa - xb + 2;
                else
                    moves = xa - xb;
            } else {
                if (xf < xb && xf > xa)
                    moves = xb - xa + 2;
                else
                    moves = xb - xa;
            }
        } else {
            moves = abs(xa - xb);
        }
    } else {
        moves = abs(xa - xb) + abs(ya - yb);
    }

    cout << moves << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase (0);cin >> t;
    while (++tcase, t--) solve();
    return 0;
}
