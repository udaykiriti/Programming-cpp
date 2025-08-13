#include <bits/stdc++.h>
using namespace std;
#define endl '\n';

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<int> home(n), away(n);
  for (int i = 0; i < n; ++i)
    cin >> home[i] >> away[i];

  int count = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (i != j && home[i] == away[j])
        ++count;

  cout << count << endl;
  return 0;
}