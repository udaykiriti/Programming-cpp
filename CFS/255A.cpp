#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int chest_sum = 0, biceps_sum = 0, back_sum = 0;

  for (int i = 0; i < n; i++)
  {
    if (i % 3 == 0)
      chest_sum += a[i];
    else if (i % 3 == 1)
      biceps_sum += a[i];
    else
      back_sum += a[i];
  }

  if (chest_sum >= biceps_sum && chest_sum >= back_sum)
    cout << "chest" << endl;
  else if (biceps_sum >= chest_sum && biceps_sum >= back_sum)
    cout << "biceps" << endl;
  else
    cout << "back" << endl;
  return 0;
}