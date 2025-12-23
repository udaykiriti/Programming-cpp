#include <bits/stdc++.h>
using namespace std;
#define endl '\n';

void solve()
{
  int x1, x2, x3, x4; cin >> x1 >> x2 >> x3 >> x4;
  int arr[4] = {x1, x2, x3, x4};
  sort(arr, arr + 4);
  int sum_abc = arr[3];
  int a = sum_abc - arr[0];
  int b = sum_abc - arr[1];
  int c = sum_abc - arr[2];
  cout << a << " " << b << " " << c << endl;
}
void solve_vectors()
{
  vector<int> arr(4);
  for (int i = 0; i < 4; ++i) cin >> arr[i];
  sort(arr.begin(), arr.end());
  int sum_abc = arr[3];
  int a = sum_abc - arr[0];
  int b = sum_abc - arr[1];
  int c = sum_abc - arr[2];
  cout << a << " " << b << " " << c << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  return 0;
}