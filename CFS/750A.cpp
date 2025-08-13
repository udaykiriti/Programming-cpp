#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(NULL);
  int n, k; cin >> n >> k;
  int timeLeft = 240 - k;
  int timeSpent = 0;
  int count = 0;

  for (int i = 1; i <= n; ++i)
    if ((timeSpent += 5 * i) <= timeLeft)
      count++;
    else
      break;

  cout << count << endl;
  return 0;
}