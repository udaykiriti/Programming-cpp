#include <bits/stdc++.h>
using namespace std;
const int N = 1001;

void solve()
{
  vector<bool> prime(N, true);
  prime[0] = prime[1] = false;

  for (int i = 2; i <= sqrt(N); i++)
    if (prime[i])
      for (int j = i * i; j < N; j += i)
        prime[j] = false;

  vector<int> primes;
  for (int i = 2; i < N; i++)
    if (prime[i])
      primes.push_back(i);

  vector<bool> vec(N, false);
  for (size_t i = 0; i + 1 < primes.size(); i++)
  {
    int res = primes[i] + primes[i + 1] + 1;
    if (res >= N)
      continue;
    if (prime[res])
      vec[res] = true;
  }
  int n, k; cin >> n >> k;
  int c = 0;
  for (int i = 2; i <= n; i++)
    if (vec[i])
      c++;

  cout << (c >= k ? "YES" : "NO") << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  return 0;
}