/**
 *    author:  uday
 *    created: 15 16:35:13
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
    int n; cin>>n;
    vector<int> vec(n);
    for(auto &x : vec) cin>>x;
    map<int,int> freq;
    for(int i=0;i<n;i++){
        freq[vec[i]]++;
    }
    /*
    wrong way to access
    for(int i=0;i<n;i++){
        cout<<freq[i].first << freq[i].second <<" ";
    }
    */

    // two correct ways
    for(auto &p : freq){
        cout<<p.first <<"->"<<p.second<<endl;
    } cout<<endl;

    for(auto it = freq.begin() ; it!=freq.end();it++){
        cout<<it->first <<"->" << it->second << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0);
    //cin >> t;
    while (++tcase, t--) solve();
}