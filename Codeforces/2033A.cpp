#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define stop_sync ios::sync_with_stdio(false)
#define untie_ios cin.tie(nullptr)
#define BYE return 0
using i64 = long long;
using vi = vector<int>;

void solve()
{
  int n; cin >> n;
  int x = 0, move = 1, turn = 0;
  while (abs(x) <= n)
  {
    if (turn == 0)
      x -= move;

    else
      x += move;

    move += 2;
    turn = 1 - turn;
  }

  if (turn == 0)
    cout << "Kosuke" << endl;

  else
    cout << "Sakurako" <<endl;
}

int main()
{
  stop_sync; untie_ios;
  int t; cin>>t;
  while(t--) solve();
  BYE;
}