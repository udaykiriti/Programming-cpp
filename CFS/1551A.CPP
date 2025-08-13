#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin>>t;
  int n;
  while(t--){
    cin>>n;
    int c1 = 0, c2 = 0;
    if(n%3 == 0){
      cout<<n/3<<" "<<n/3<<endl;
      continue;
    }
    if(n%3 == 1){
      cout<<(n/3 + 1)<<" "<<n/3<<endl;
      continue;
    }
    cout<<(n/3)<<" "<<(n/3 + 1)<<endl;
  }
}