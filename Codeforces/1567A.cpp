#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(){
    int n; cin>>n;
    string s; cin>> s;
    for(int i=0;i<n;i++){
        if(s[i]=='U') s[i]='D';
        else if(s[i]=='D') s[i] = 'U';
    }
    cout << s << endl;
}

int main(int argc , char *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int  t(1),tcase(0); cin>>t;
    while(++tcase,t--) solve();
}