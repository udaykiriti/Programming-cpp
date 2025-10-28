#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve(){
    int n;
    cin>>n;
    vll vec1(n), vec2(n);
    for (auto &x : vec1) cin >> x;
    for (auto &x : vec2) cin >> x;

    ll ToTC = accumulate(vec2.begin(),vec2.end(),0LL);
    vll dp(n, 0);
    ll MK(0);

    for(int i=0;i<n;i++){
        dp[i] = vec2[i];
        for(int j=0;j<i;j++){
            if(vec1[j] <= vec1[i])
                dp[i] = max(dp[i] , dp[j] + vec2[i]);
        }
        MK = max(MK,dp[i]);
    }
    cout << ToTC - MK << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}