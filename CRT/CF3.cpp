#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(x) (x).begin(), (x).end()
#define pb push_back
#define SZ(x) int((x).size())
#define sc scanf
#define pr printf

const int N = 10, D = 150;
static std::vector<std::vector<std::vector<std::vector<int>>>> tbl;
static int f[N];

bool cp(const std::vector<int> &bl, int w, int h)
{
  int uh = 0, rw = 0, rh = 0;
  for (int s : bl)
  {
    if (s > w || s > h)
      return false;
    if (rw + s <= w)
    {
      rw += s;
      rh = std::max(rh, s);
    }
    else
    {
      uh += rh;
      if (uh + s > h)
        return false;
      rw = rh = s;
    }
  }
  return (uh + rh) <= h;
}

void pc()
{
  tbl.assign(N + 1, std::vector<std::vector<std::vector<int>>>(D + 1));
  FOR(n, 2, N + 1)
  {
    f[0] = 1;
    f[1] = 2;
    FOR(i, 2, n)
      f[i] = f[i - 1] + f[i - 2];

    int fm = f[n - 1];
    int full = (1 << n) - 1;
    std::vector<int> sm(1 << n, 0);
    FOR(m, 1, full + 1)
    {
      int l = m & -m;
      sm[m] = sm[m ^ l] + f[__builtin_ctz(l)];
    }

    std::vector<int> dp(1 << n);
    FOR(h, 1, D + 1)
    {
      if (h < fm)
        continue;
      dp[0] = 0;
      FOR(m, 1, full + 1)
      {
        if (sm[m] <= h)
          dp[m] = 1;
        else
        {
          int best = n + 1;
          for (int s = (m - 1) & m; s; s = (s - 1) & m)
            if (sm[s] <= h)
              best = std::min(best, dp[m ^ s] + 1);
          dp[m] = best;
        }
      }

      int bins = dp[full];
      if (bins > n)
        continue;

      std::vector<std::vector<int>> vs(1 << n);
      FOR(m, 1, full + 1)
      {
        int l = m & -m;
        int i = __builtin_ctz(l);
        int r = m ^ (1 << i);
        for (int s = r;; s = (s - 1) & r)
        {
          int sf = s | (1 << i);
          if (sm[sf] <= h)
            vs[m].pb(sf);
          if (!s)
            break;
        }
      }

      std::set<std::vector<int>> bs;
      std::vector<int> tmp;
      std::function<void(int, int)> dfs = [&](int r, int b)
      {
        if (b == 1)
        {
          if (sm[r] <= h)
          {
            int idx = 31 - __builtin_clz(r);
            tmp.pb(f[idx]);
            std::vector<int> v = tmp;
            std::sort(v.begin(), v.end(), std::greater<>());
            bs.insert(v);
            tmp.pop_back();
          }
          return;
        }
        for (int s : vs[r])
        {
          int idx = 31 - __builtin_clz(s);
          tmp.pb(f[idx]);
          dfs(r ^ s, b - 1);
          tmp.pop_back();
        }
      };

      dfs(full, bins);
      auto &out = tbl[n][h];
      out.reserve(bs.size());
      for (const auto &v : bs)
        out.pb(v);
    }
  }
}

void sol()
{
  int n, m;
  sc("%d %d", &n, &m);
  std::vector<std::array<int, 3>> bx(m);
  FOR(i, 0, m)
    sc("%d%d%d", &bx[i][0], &bx[i][1], &bx[i][2]);

  std::vector<int> fn(n);
  fn[0] = 1;
  if (n >= 2)
    fn[1] = 2;
  FOR(i, 2, n)
    fn[i] = fn[i - 1] + fn[i - 2];

  int fm = fn[n - 1];
  char res[m + 1];
  res[m] = '\0';

  FOR(i, 0, m)
  {
    int d[3] = {bx[i][0], bx[i][1], bx[i][2]};
    bool ok = false;
    FOR(hi, 0, 3)
    {
      if (ok)
        break;
      int h = d[hi];
      if (h < fm)
        continue;
      int w1 = d[(hi + 1) % 3];
      int w2 = d[(hi + 2) % 3];
      const auto &bl = tbl[n][h];
      if (bl.empty())
        continue;
      for (const auto &b : bl)
      {
        if (cp(b, w1, w2) || cp(b, w2, w1))
        {
          ok = true;
          break;
        }
      }
    }
    res[i] = ok ? '1' : '0';
  }

  pr("%s\n", res);
}

int main()
{
  pc();
  int t;
  sc("%d", &t);
  while (t--)
    sol();
  return 0;
}
