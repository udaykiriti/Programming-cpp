#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n; cin >> n;
  string result = "";
  FOR(i, 0, n)
  {
    if (i % 2 == 0)
      result += "I hate";
    else
      result += "I love";
    if (i != n - 1)
      result += " that ";
  }
  result += " it";
  cout << result << endl;
  return 0;
}