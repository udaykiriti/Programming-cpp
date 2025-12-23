#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FastIO()                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(nullptr);                 \
  cout.tie(nullptr);

const int MAX = 1000000;

vector<bool> sieve(int max_val)
{
  vector<bool> is_prime(max_val + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= max_val; ++i)
    if (is_prime[i])
      for (int j = i * i; j <= max_val; j += i)
        is_prime[j] = false;
  return is_prime;
}

void solve()
{
  vector<bool> is_prime = sieve(MAX);
  set<long long> t_primes;
  for (int i = 2; i <= MAX; ++i)
    if (is_prime[i])
      t_primes.insert((long long)i * i);

  int n; cin >> n;
  while (n--)
  {
    long long x; cin >> x;
    if (t_primes.find(x) != t_primes.end())
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}

int main()
{
  FastIO();
  solve();
  return 0;
}