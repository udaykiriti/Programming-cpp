#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(){
    int n; cin>>n;
    cout<<(3-(n % 3))%3<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1),tcase(0); cin>>t;
    while(tcase++,t--) solve();
    return 0;
}