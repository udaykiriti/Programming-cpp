#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FastIO()                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(nullptr);                 \
  cout.tie(nullptr);
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)

void solve()
{
  int n; string s; cin >> n >> s;
  map<string, int> freq;
  string max_two_gram;
  int max_count = 0;
  FOR(i, 0, n - 2)
  {
    string two_gram = s.substr(i, 2);
    freq[two_gram]++;
    if (freq[two_gram] > max_count)
    {
      max_count = freq[two_gram];
      max_two_gram = two_gram;
    }
  }
  cout << max_two_gram << endl;
}

int main()
{
  FastIO();
  solve();
  return 0;
}