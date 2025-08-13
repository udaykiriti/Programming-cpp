#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long 
#define debug(x) cout<<(x)<<endl
#define FOR(i,a,b) for(int i=(a);i<(b);i++)

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, k; cin >> n >> k;
  vector<int> h(n);
  FOR (i,0,n)
    cin >> h[i];

  int sum = 0;
  FOR (i,0,k)
    sum += h[i];

  int min_sum = sum, min_index = 0;

  FOR (i,k,n)
  {
    sum = sum - h[i - k] + h[i];
    if (sum < min_sum)
    {
      min_sum = sum;
      min_index = i - k + 1;
    }
  }

  cout << min_index + 1 << endl;
  return 0;
}