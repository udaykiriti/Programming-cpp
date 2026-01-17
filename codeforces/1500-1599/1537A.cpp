#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IO()                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(NULL)
int main(int argc, char const *argv[])
{
  IO();
  int t, length, x, sum = 0; cin >> t;
  while (t--)
  {
    cin >> length;
    sum = 0;
    for (int i = 0; i < length; i++)
    {
      cin >> x;
      sum += x;
    }
    if (sum < length)
      cout << 1 << "\n";
    else
      cout << sum - length << "\n";
  }
  return 0;
}