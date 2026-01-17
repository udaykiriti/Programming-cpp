#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n; cin >> n;
  vector<string> names = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
  int i = 0, groupSZ = 1;

  while (n > groupSZ * 5)
  {
    n -= groupSZ * 5;
    groupSZ *= 2;
  }

  int index = (n - 1) / groupSZ;
  cout << names[index] << endl;
  return 0;
}
