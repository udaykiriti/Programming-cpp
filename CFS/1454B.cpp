/**
 *    author:  uday
 *    created: 15 16:50:21
 **/

// g++ -std=c++17 new.cpp -o new
// ./new
#undef _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

void solve(){
    int n ; cin>>n;
    vector<int> vec(n);
    vector<pair<int,int>> par;
    for(int i=0;i<n;i++){
        cin>>vec[i];
        par.push_back(make_pair(vec[i],i));
    }
    sort(par.begin(),par.end());
    int in(-1);
    for(int i=0;i<n;i++){
        int a=par[i].first;
        if(i==n-1 && par[i].second != -1){
            in = par[i].second+1;
            break;
        }
        if(a != par[i+1].first){
            if(par[i].second == -1) continue;
            in=par[i].second + 1;
            break;
        }else{
            par[i+1].second = -1;
        }
    } cout<<in<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0);
    cin >> t;
    while (++tcase, t--) solve();
}