#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cout<<(x)<<endl

int strDiff(string x, string y)
{
  int sum = 0; int N = x.size();
  for (int i = 0; i < N; i++)
    sum += abs(x[i] - y[i]);
  return sum;
}

void FastIO()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
}

int main()
{
  FastIO();
  int t; cin >> t;
  while (t--)
  {
    int n, m; cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; i++)
      cin >> s[i];
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (i != j)
          mini = min(mini, strDiff(s[i], s[j]));
    cout << mini << endl;
  }
}