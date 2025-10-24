/******************************
 *    author:  uday           *
 *    created: 24 08:20:26    *
 ******************************/

// g++ -std=c++17 new.cpp -o new
// ./new
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

int isprime[100050];
int ans[100050]; 

void eratos() {
    int n = 100050;
    for (int i = 0; i < n; i++) isprime[i] = 1;
    isprime[0] = isprime[1] = 0;
    for (int i = 2; i * i <= n; i++)
        if (isprime[i])
            for (int j = i * 2; j <= n; j += i) 
                isprime[j] = 0;
}


void solve(){
    int n; cin >> n;
    if(n==1 || n==2) cout << 1 << endl;
    else cout << 2 << endl;

    for(int i=1;i<=n;i++){
        if(isprime[i+1]) ans[i] = 1;
        else ans[i] = 2;
    }

    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    eratos();
    int t(1), tcase(0); //cin>>t;
    while (++tcase, t--) solve();
}
