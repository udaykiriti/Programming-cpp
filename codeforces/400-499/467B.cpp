#include <bits/stdc++.h>
using namespace std;

int countSetBits(int x)
{
  int count = 0;
  while (x)
  {
    x &= (x - 1);
    count++;
  }
  return count;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(nullptr);
  int n, m, k; cin >> n >> m >> k;
  vector<int> armies(m + 1);
  for (int i = 0; i <= m; ++i) cin >> armies[i];

  int fedor = armies[m];
  int count = 0;

  for (int i = 0; i < m; ++i)
  {
    int diff = countSetBits(armies[i] ^ fedor);
    if (diff <= k) count++;
  }
  cout << count << endl;
  return 0;
}