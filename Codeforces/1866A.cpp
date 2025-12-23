#include <bits/stdc++.h>
#define i64 long long int
#define nline '\n'
using namespace std;

void solve(){
    i64 n; cin >> n;
    i64 minOper = INT_MAX;
    for (i64 i = 0; i < n; i++){
        i64 t; cin >> t;
        if (t == 0){
            minOper = 0;
            break;
        }
        minOper = min(minOper, abs(t));
    }
    cout << minOper << nline;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    i64 T = 1;
    while (T--) solve();
}
