#include <bits/stdc++.h>
using namespace std;
int main(int argc , char *argv[]){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1), pr(n + 1, 0), fx(n + 1, 0);
        int z = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            if (a[i] == 0)
                z++;
            else if (a[i] >= 1 && a[i] <= n)
                pr[a[i]] = 1;
        }
        for (int i = 1; i <= n; i++)
            if (a[i] == i)
                fx[i] = 1;
        bool bol = false;
        int zi = -1, miss = -1;
        if (z == 1){
            for (int i = 1; i <= n; i++)
                if (a[i] == 0)
                    zi = i;
            for (int v = 1; v <= n; v++)
                if (!pr[v])
                    miss = v;
            if (zi == miss)
                bol = true;
        }
        int L = 1;
        while (L <= n && (fx[L] || (bol && L == zi)))
            L++;
        if (L > n) {
            cout << 0 << "\n";
            continue;
        }
        int R = n;
        while (R >= 1 && (fx[R] || (bol && R == zi)))
            R--;
        cout << R - L + 1 << "\n";
    }
    return 0;
}
