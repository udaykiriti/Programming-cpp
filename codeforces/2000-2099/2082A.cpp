#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i < b; i++)

void solve()
{
  int n, m; cin >> n >> m;
  vector<string> matrix(n);
  FOR (i, 0, n)
    cin >> matrix[i];
  vector<int> rowXOR(n, 0), colXOR(m, 0);

  FOR (i, 0, n)
  {
    FOR ( j ,0, m)
    {
      int val = matrix[i][j] - '0';
      rowXOR[i] ^= val;
      colXOR[j] ^= val;
    }
  }

  int oddRows = count(rowXOR.begin(), rowXOR.end(), 1);
  int oddCols = count(colXOR.begin(), colXOR.end(), 1);
  cout << max(oddRows, oddCols) << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}