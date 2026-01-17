#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cout<<(x)<<endl

int main(){
  int k, l, m, n, d; cin>>k>>l>>m>>n>>d;
  int i = 0, j = 1;
  while(j <= d){
    if(j % k == 0 || j % l == 0 || j % m == 0 || j % n == 0) i++;
    j++;
  }
  cout<<i;
}