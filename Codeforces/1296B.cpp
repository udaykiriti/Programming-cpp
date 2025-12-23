#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve(){
    int n; cin>>n;
    int res(0);
    while(n){
        int sum = n/10;
        if(sum==0){
            res+=n;
            break;
        }
        res+=sum*10;
        n=sum+n%10;
    } cout<<res<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
