#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n; cin >> n;
  int x, minindex, maxindex, maxi = 0, mini = 1000;
  FOR(i, 0, n)
  {
    cin >> x;
    if (x > maxi)
    {
      maxindex = i;
      maxi = x;
    }
    if (x <= mini)
    {
      minindex = i;
      mini = x;
    }
  }

  if (maxindex > minindex)
    cout << (maxindex - 1) + (n - minindex) - 1;
  else
    cout << (maxindex - 1) + (n - minindex);
}