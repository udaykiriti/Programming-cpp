#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long t; cin>>t;
    while(t--){
        long n, k; cin>>n>>k;
        long odd = ( (k + (n % 2)) / 2) % 2;
        cout<<(odd ? "NO" : "YES")<<endl;
    }
}
