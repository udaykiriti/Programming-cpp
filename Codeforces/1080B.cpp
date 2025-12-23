#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin>>t;
  ll l, r;
  while(t--){
    cin>>l>>r; ll odd_l, odd_r;
    l--;
    if(l % 2 == 0) odd_l = l/2 * l/2;
    else odd_l = (l/2 + 1) * (l/2 + 1);
    ll even_l = l/2 * (l/2 + 1);
    if(r % 2 == 0) odd_r = r/2 * r/2;
    else odd_r = (r/2 + 1) * (r/2 + 1);
    ll even_r = r/2 * (r/2 + 1);
    ll even_s = even_r - even_l;
    ll odd_s = odd_r - odd_l;
    cout<<(even_s - odd_s)<<"\n";
  }
  return 0;
}
