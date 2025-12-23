#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cout<<(x)<<endl

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t; cin>>t;
  int n;
  while(t--){
    cin>>n;
    if(n%2 != 0){
      n--; cout<<(n/2)<<endl;
      continue;
    }
    cout<<(n/2)<<endl;
  }
  return 0;
}