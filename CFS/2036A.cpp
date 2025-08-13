#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i,a,b) for(int i=a;i<b;i++)

void solve()
{
  int n; cin >> n;
  vector<int> notes(n);
  FOR (i , 0, n) 
    cin >> notes[i];

  FOR (i,1, n)
  {
    int diff = abs(notes[i] - notes[i - 1]);
    if (diff != 5 && diff != 7)
    {
      cout << "NO"<<endl;
      return;
    }
  }
  cout << "YES"<<endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}