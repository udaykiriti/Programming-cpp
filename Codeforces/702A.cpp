#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  ll n; cin>>n;
  ll prev, curr; cin>>prev;
  ll maxlen = 1, count = 1;
  for(ll i = 0; i < n-1; i++){
    cin>>curr;
    if(curr <= prev){
      count = 1;
      prev = curr;
      continue;
    }
    count++;
    if(maxlen < count)
      maxlen = count;
    prev = curr;
  }
  cout<<maxlen<<endl;
}