#include <bits/stdc++.h>
using namespace std;
using i64 = long long int;
#define ln "\n"
#define stop_sync ios::sync_with_stdio(false)
#define untie_ios cin.tie(nullptr)
#define pb push_back
#define All(x) (x).begin(), (x).end()

void solve()
{
  const int N = 3;
  i64 t; cin >> t;

  while (t--)
  {
    i64 n; cin >> n;
    vector<set<string>> v(N);
    for (int p = 0; p < N; p++)
    {
      for (int q = 0; q < n; q++)
      {
        string s; cin >> s;
        v[p].insert(s);
      }
    }

    vector<i64> score(N, 0);
    for (int p = 0; p < N; p++)
    {
      for (const auto &x : v[p])
      {
        i64 cnt = 0;
        for (int q = 0; q < N; q++)
        {
          if (q == p) continue;
          cnt += v[q].count(x);
        }

        if (cnt == 0) score[p] += 3;
        else if (cnt == 1) score[p] += 1;
      }
    }

    for (int p = 0; p < N; p++) cout << score[p] << " ";
    cout << ln;
  }
}

int main()
{
  stop_sync;
  untie_ios;
  solve();
  return 0;
}