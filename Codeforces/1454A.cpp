#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin>>t;
  int n;
  while(t--){
    cin>>n;
    for(int i = 2; i <= n; i++)
      cout<<i<<" ";
    cout<<1<<endl;
  }
  return 0;
}
