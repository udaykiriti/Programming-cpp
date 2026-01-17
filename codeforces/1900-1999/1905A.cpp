#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve() {
    int x,y; cin>>x>>y;
    cout << max(x,y) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t(1),tcase(0); cin >> t;
    while(++tcase,t--) solve();
    return 0;
}
