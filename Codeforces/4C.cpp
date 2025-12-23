/*
Problem: 4C - Registration System (Codeforces)
Link: https://codeforces.com/problemset/problem/4/C

Description:
A new e-mail service "Berlandesk" is being developed. The system should be able to process requests for registration of new users.
Each request has a name. If the name is not yet registered, the system should register it and respond with "OK".
If the name is already taken, the system should append the smallest integer such that the new name is not taken, and respond with this new name.
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
void solve()
{
  int n; cin >> n;
  unordered_map<string, int> usernames;
  while (n--)
  {
    string name; cin >> name;
    if (usernames.count(name) == 0)
    {
      cout << "OK" << endl;
      usernames[name] = 1;
    }
    else
    {
      string new_name = name + to_string(usernames[name]);
      while (usernames.count(new_name))
      {
        usernames[name]++;
        new_name = name + to_string(usernames[name]);
      }
      cout << new_name << endl;
      usernames[new_name] = 1;
      usernames[name]++;
    }
  }
}

int32_t main(int argc , char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}