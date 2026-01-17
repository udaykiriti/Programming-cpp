#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int argc , char *argv[]){
    long t; cin>>t;
    while(t--){
        ll n; cin>>n;
        vector<ll> a(n); 
        for(ll i = 0; i < n; i++) cin>>a[i];
        ll total(1);
        for(ll p = 0; p < n; p++){
            ll b; cin>>b;
            total += (a[p] > b ? (a[p] - b) : 0);
        }
        cout<<total<<'\n';
    }
}