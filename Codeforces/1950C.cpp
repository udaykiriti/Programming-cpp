#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FastIO()                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(nullptr);                 \
  cout.tie(nullptr);

void solve()
{
  string s; cin >> s;
  int hour = stoi(s.substr(0, 2));
  string minute = s.substr(3, 2);
  string period;

  if (hour == 0)
  {
    hour = 12;
    period = "AM";
  }
  else if (hour < 12)
  {
    period = "AM";
  }
  else if (hour == 12)
  {
    period = "PM";
  }
  else
  {
    hour -= 12;
    period = "PM";
  }
  cout << setw(2) << setfill('0') << hour << ":" << minute << " " << period << endl;
}

int main()
{
  FastIO();
  int t; cin >> t;
  while (t--) solve();
  return 0;
}