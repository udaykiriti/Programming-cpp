/******************************
 *    author:  -----          *
 *    created: 25 22:58:17    *
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

void solve(){
   //solution here.........
   int n; cin>>n;
   vector<pair<int,int>> vec(n);
   for(int i=0;i<n;i++){
    cin>>vec[i].first>>vec[i].second;
   }
    sort(vec.begin(), vec.end(), [&](const pair<ll, ll>& x, const pair<ll, ll>& y) {
        return (x.first - x.second) > (y.first - y.second);
    });

    debug(vec);
    ll res = 0;
    for (int i = 0; i < n; i++) {
        ll a = vec[i].first;
        ll b = vec[i].second;
        res += a * i + b * (n - 1 - i);
    }
    cout<<res<<endl;
}

int main(){
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0); //cin>>t;
    while (++tcase, t--) solve();
}