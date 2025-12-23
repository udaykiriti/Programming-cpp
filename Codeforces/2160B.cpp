#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define vi vector<int>
#define vll vector<long long>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ll long long

void solve(){
    int n; cin>>n;
    vll vec1(n+1);
    FOR(i,1,n) cin>>vec1[i];
    vi vec2(n+1,0);
    ll fst(0), nx(0);
    FOR(k,1,n)
    {
        ll ns=vec1[k] - fst;
        fst = vec1[k];
        int ls = int(k-ns);
        if(ls == 0){
            ++nx;
            vec2[k] = nx;
        }else{
            vec2[k] = vec2[ls];
        }
    }
    FOR(p,1,n){
        if(p>1) cout<<" ";
        cout<<vec2[p];
    }
    cout<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1),tcase(0); cin>>t;
    while(++tcase,t--) solve();
    return 0;
}