#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cout<<(x)<<endl


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, k; cin>>n>>k;
  int sum = 0;
  int i;
  for(i = 1; i <= n; i++)
    if(sum + (5 * i) > (240 -k))
      break;
    sum += (5 * i);
  i--;
  cout<<i;

}
