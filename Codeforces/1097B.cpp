#include <bits/stdc++.h>
using namespace std;

bool isPossible(const vector<int> &a, int i = 0, int sum = 0)
{
  if (i == a.size()) return sum % 360 == 0;
  return isPossible(a, i + 1, sum + a[i]) || isPossible(a, i + 1, sum - a[i]);
}

int main(int argc, char *argv[])
{
  ios::sync_with_stdio(false); 
  cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  cout << (isPossible(a) ? "YES\n" : "NO\n");
}