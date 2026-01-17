#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

ll scoreBoard[10][10] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
    {1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
    {1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
    {1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
    {1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
    {1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
    {1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
    {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

void solve()
{
  ll score = 0;
  FOR(i, 0, 10)
  {
    FOR(j, 0, 10)
    {
    char ch; cin >> ch;
    if (ch == 'X')
      score += scoreBoard[i][j];
    }
  }
  cout << score << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  ll t = 1; cin >> t;
  while (t--) solve();
}