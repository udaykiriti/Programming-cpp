#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n; cin >> n;
  vector<int> vec(n);
  for (int i = 0; i < n; i++)
    cin >> vec[i];
  int min_diff = abs(vec[0] - vec[n - 1]);
  int idx1 = 1, idx2 = n;

  for (int i = 0; i < n - 1; ++i)
  {
    int diff = abs(vec[i] - vec[i + 1]);
    if (diff < min_diff)
    {
      min_diff = diff;
      idx1 = i + 1;
      idx2 = i + 2;
    }
  }
  cout << idx1 << " " << idx2 << endl;
  return 0;
}
