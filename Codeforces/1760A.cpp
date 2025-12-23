#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int a, b, c; cin >> a >> b >> c;
  int arr[3] = {a, b, c};
  sort(arr, arr + 3);
  cout << arr[1] << endl;
  // int a, b, c;
  // cin >> a >> b >> c;

  // int mid;
  // if ((a >= b && a <= c) || (a <= b && a >= c))
  //     mid = a;
  // else if ((b >= a && b <= c) || (b <= a && b >= c))
  //     mid = b;
  // else
  //     mid = c;

  // cout << mid << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}