#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
#define  pb push_back

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n, d; cin >> n >> d;
        vector<int> ans;
        ans.pb(1);
        if(n >= 3 || d % 3 == 0) ans.pb(3);
        if(d == 5) ans.pb(5);
        if(d % 7 == 0 || n >= 3) ans.pb(7);
        if(d % 9 == 0 || n >= 6 || (n >= 3 && d % 3 == 0)) ans.pb(9);
        for(auto i: ans) cout << i << ' ';
        cout << ln;
    }
    return 0;
}