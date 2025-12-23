/******************************
 *    author:  uday           *
 *    created: 16 13:18:24    *
 ******************************/

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

#define lli long long int
template<typename type> type Nsum(type n){return (n * (n + 1)) / (type)2;}


void solve(){
    int n,k; cin>>n>>k;
    string s; cin>>s;
    map<char,int> m;
    s.push_back('A');
    for(int i=0;i<k;i++){
        char ch; cin >> ch;
        ++m[ch];
    }
    lli ans(0ll);
    int now(0);
    for(int i=0;i<=n;i++){
        if(m[s[i]] == 0){
            ans+=Nsum((lli)i-(lli) now);
            now=i+1;
        }
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0);
    //cin >> t;
    while (++tcase, t--) solve();
}