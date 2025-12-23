#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cout<<(x)<<endl

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n, m; cin>>n>>m;
  char x;
  for(int i = 0; i < (n*m); i++){
    cin>>x;
    if(x != 'B' && x != 'W' && x != 'G'){
      cout<<"#Color"<<endl;
      return 0;
    }
  }
  cout<<"#Black&White"<<endl;
  return 0;
}