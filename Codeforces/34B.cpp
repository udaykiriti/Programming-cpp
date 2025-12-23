#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define debug(n) cout<<(n)<<endl;
const ll INF = 2e18 + 99;
#define mod 1000000007
#define FOR(i,a,b) for(int i=(a);i<(b);i++)

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n, m; cin>>n>>m;
  int arr[n];
  FOR(i,0,n)
    cin>>arr[i];
  sort(arr, arr+n);
  int count = 0;
  FOR(i,0,m)
    if(arr[i] < 0)
      count -= arr[i];
  cout<<count<<endl;
}