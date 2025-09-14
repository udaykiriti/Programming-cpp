#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isPrime(long long x) {
  if (x < 2) return false;
  for (long long i = 2; i <= sqrt(x); ++i)
    if (x % i == 0) return false;
  return true;
}

void solve() {
  ll d; cin >> d;
  ll p1 = d + 1;
  while (!isPrime(p1)) ++p1;
  ll p2 = p1 + d;
  while (!isPrime(p2)) ++p2;
  ll result = min(p1 * p2, p1 * p1 * p1);
  cout << result << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}
