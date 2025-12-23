#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef vector<int> vi;//using vi=vector<int> || #define vi vector<int>

void solve()
{
    int x1, x2, x3; cin >> x1 >> x2 >> x3;
    vector<int> points = {x1, x2, x3};
    sort(points.begin(), points.end());
    int a = points[1];
    int result = abs(a - points[0]) + abs(a - points[1]) + abs(a - points[2]);
    cout << result << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin>>t;
  while(t--) solve();
  return 0;
}