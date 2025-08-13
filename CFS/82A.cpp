#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n; cin >> n;
  vector<string> names = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
  int i = 0, group_size = 1;

  while (n > group_size * 5)
  {
    n -= group_size * 5;
    group_size *= 2;
  }

  int index = (n - 1) / group_size;
  cout << names[index] << endl;
  return 0;
}