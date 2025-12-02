#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  ll n, m, a; cin >> n >> m >> a;
  ll c = (m % a == 0) ? (m / a) : (m / a + 1); 
  ll d = (n % a == 0) ? (n / a) : (n / a + 1); 
  cout << c * d << '\n';
  return 0;
}