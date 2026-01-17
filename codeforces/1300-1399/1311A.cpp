#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll int t,a,b,ans,dis; cin>>t;
    while(t--){
        ans=dis=0;
        cin>>a>>b;
        if(a == b){
            cout<<0<<endl;
            continue;
        }
        if(a>b){
            dis=a - b;
            ans++;
            if(dis % 2 !=0)
              ans++;
        }
        else if(a < b){
            dis= b - a;
            ans++;
            if(dis % 2 != 1)
              ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}