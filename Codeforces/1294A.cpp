#include<bits/stdc++.h>
using namespace std;
#define endl '\n';
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin>>t;
  int a, b, c, n;
  while(t--){
    cin>>a>>b>>c>>n;
    int maxi = max(a, b);
    maxi = max(maxi, c);
    n -= 3*maxi - (a + b + c);
    if(n < 0){
      cout<<"NO"<<endl;
      continue;
    }
    if(n%3 == 0){
      cout<<"YES"<<endl;
    }
    else{
      cout<<"NO"<<endl;
    }
  }
}