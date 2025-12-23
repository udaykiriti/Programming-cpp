#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long

const int N = 202;
vi prs;

vector<bool> isp(N+1,true);

void sieve(){
    isp[0] = isp[1] = false;
    for(int i=2;i<=N;i++){
        if(isp[i])
            prs.push_back(i);
        for(int j = i*i ;j<=N;j+=i)
            isp[j] = false;
    }
}

void solve(){
    int n;
    cin>>n;
    ll tmp(0);
    for(int i=0;i<n;i++){
        ll x; cin>>x;     
        if (i == 0) tmp = x;
        else tmp = __gcd(tmp, x);

    }
    int res(-1);
    for(int nm : prs){
        if(tmp % nm != 0){
            res = nm;
            break;
        }
    }
    cout << res << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    sieve();
    int t;
    cin>>t;
    while(t--) solve();
}