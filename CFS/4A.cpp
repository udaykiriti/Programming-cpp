#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  ll w; cin>>w;
  if (w % 2 == 0 && w > 2)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
  return 0;
}