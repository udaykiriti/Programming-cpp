#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define vi vector<int>

const int N = 51;
vector<bool> p(N);
vi primes;

void sieve()
{
  for (int i = 0; i < N; i++)
    p[i] = true;

  p[0] = p[1] = false;

  for (int i = 2; i * i < N; i++)
    if (p[i])
      for (int j = i * i; j < N; j += i)
        p[j] = false;

  for (int i = 0; i < N; i++)
    if (p[i])
      primes.push_back(i);
}

void solve(int now, int next)
{
  for (int i = 0; i < primes.size(); i++)
  {
    if (primes[i] == now)
    {
      if (i + 1 < primes.size() && primes[i + 1] == next)
        cout << "YES\n";
      else
        cout << "NO\n";
      return;
    }
  }
  cout << "NO\n";
}

int main()
{
  int now, next; cin >> now >> next;
  sieve();
  solve(now, next);
}