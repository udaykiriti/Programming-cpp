#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cout<<(x)<<endl

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<int> a(n);
  int totalOnes = 0;
  for (int i = 0; i < n; ++i){
    cin >> a[i];
    if (a[i] == 1)
      totalOnes++;
  }

  int maxGain = -1; int current = 0;
  for (int i = 0; i < n; ++i){
    int val = (a[i] == 0 ? 1 : -1);
    current = max(val, current + val);
    maxGain = max(maxGain, current);
  }

  if (totalOnes == n) cout << n - 1 << endl;
  else cout << totalOnes + maxGain << endl;
  return 0;
}