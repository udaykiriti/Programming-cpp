#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cout<<(x)<<endl

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin>>t;
  int x, s, n;
  for(int i = 0; i < t; i++){
    cin>>n>>s;
    if(n%2 == 0)
      x = s/((n/2) + 1);
    else
      x = s/((n+1)/2);
    cout<<x<<endl;
  }
}