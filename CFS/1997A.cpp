#include <bits/stdc++.h>
using namespace std;

int typing_time(const string &s)
{
  int time = 2;
  for (int i = 1; i < s.size(); i++)
    time += (s[i] == s[i - 1]) ? 1 : 2;
  return time;
}

int main()
{
  int t; cin >> t;
  while (t--)
  {
    string s; cin >> s;
    string best;
    int max_time = 0;

    for (int i = 0; i <= s.size(); i++)
    {
      for (char c = 'a'; c <= 'z'; c++)
      {
        string temp = s.substr(0, i) + c + s.substr(i);
        int time = typing_time(temp);
        if (time > max_time)
        {
          max_time = time;
          best = temp;
        }
      }
    }
    cout << best << '\n';
  }
  return 0;
}