#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define debug(x) cout<<(x)<<endl
#define FOR(i,a,b) for(int i=a;i<b;i++)

void solve(){
    int n; cin>>n;
    vector<ll>counts(n+1,0);
    FOR(i,0,n){
        int val; cin>>val;
        if(val<=n) counts[val]++;
    }
    vector<ll>diff(n+2,0);
    for (int m = 0; m <= n; m++)
    {
        ll min_k=counts[m];
        ll max_k=n-m;
        if(min_k<=max_k){
            diff[min_k]++;
            if(max_k+1<=n){
                diff[max_k+1]--;
            }
        }
        if(counts[m]==0) break;
    }
    ll curr=0;
    for(int k=0;k<=n;k++){
        curr+=diff[k];
        cout<<curr<<endl;
    }
    cout<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin>>t;
    while(t--) solve();
}