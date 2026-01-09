#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 2e18 + 99;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t; cin>>t;
  ll n;
  while(t--){
    cin>>n;
    cout<<max(6LL, n + 1) / 2 * 5 << '\n';
  }
}
