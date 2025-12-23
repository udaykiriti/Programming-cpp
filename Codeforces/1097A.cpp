#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;
#define FOR(i,a,b) for(int i=a;i<b;i++)

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  string a; cin>>a;
  string arr[5];
  FOR(i,0,5){
    cin>>arr[i];
  }
  FOR(i,0,5){
    if(a[0] == arr[i][0]){
      cout<<"YES"<<endl;
      return 0;
    }
  }

  FOR(i,0,5){
    if(a[1] == arr[i][1]){
      cout<<"YES"<<endl;
      return 0;
    }
  }
  cout<<"NO"<<endl;
}