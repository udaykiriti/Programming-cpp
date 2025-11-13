#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll rec(int i, int prev, vector<int> &v, vector<int> &c, vector<vector<ll>> &dp){

    if(i == v.size()) return 0;

    if(dp[i][prev + 1] != -1){
        return dp[i][prev + 1];
    }

    ll change = LLONG_MAX, nChange = LLONG_MAX;
    
    change = rec(i + 1, prev, v, c, dp) + c[i]; 

    if(prev == -1 || v[prev] <= v[i]){
        nChange = rec(i + 1, i, v, c, dp);
    }

    return dp[i][prev + 1] = min(change, nChange);
}

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    vector<int> c(n);
    for(auto &x : v) cin >> x;
    for(auto &x : c) cin >> x;
    
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -1));
    cout << rec(0, -1, v, c, dp) << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tcase(0),t(1); cin >> t;
    while(++tcase,t--) solve();
}