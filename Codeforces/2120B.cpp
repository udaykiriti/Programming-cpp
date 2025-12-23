#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cout << (x) << endl
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define in(x) cin >> x
#define PRINT(x) cout << x << endl

void solve() {
    int a, b; cin>>a>>b;
    int c = 0;
    FOR(i, 0, a) {
        int d, e, f, g; cin>>d>>e>>f>>g;
        if (d == e) {
            if ((f - g) % b == 0)
                c++;
        } else {
            if ((f + g) % b == 0)
                c++;
        }
    }
    cout<<c;
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin>>t;
    while(t--) solve();
}