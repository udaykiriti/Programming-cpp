#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while (t--)
  {
    int n, m; cin >> n >> m;
    string carpet[n];
    for (int i = 0; i < n; i++) cin >> carpet[i];
    string vika = "vika";
    int k = 0;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (carpet[j][i] == vika[k])
        {
          k++;
          break;
        }
      }
    }

    if (k >= 4) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}