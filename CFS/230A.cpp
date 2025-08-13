/* Problem: Dragons
Kirito is stuck in a video game and needs to defeat dragons to progress. Each dragon has a strength and a bonus.
Kirito starts with an initial strength `s`. If Kirito's strength is greater than a dragon's strength, he defeats it
and gains the bonus. Otherwise, he loses the game.

Input:
The first line contains two integers `s` and `n` (1 ≤ s ≤ 10^4, 1 ≤ n ≤ 10^3) — Kirito's initial strength and the number of dragons.
The next `n` lines each contain two integers `a` and `b` (1 ≤ a, b ≤ 10^4) — the strength of a dragon and the bonus Kirito gains after defeating it.

Output:
Print "YES" if Kirito can defeat all dragons, otherwise print "NO".

Example:
Input:
2 2
1 99
100 0
Output:
YES

Input:
10 1
100 100
Output:
NO
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define FastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define PRINT_YES cout << "YES" << endl
#define PRINT_NO cout << "NO" << endl
#define FOR(i, a, b) for (int i = a; i < b; i++)

int main()
{
  FastIO;
  int s, n; cin >> s >> n;
  multimap<int, int> dragons;
  FOR(i, 0, n)
  {
    int a, b; cin >> a >> b;
    dragons.insert({a, b});
  }

  // Check if Kirito can defeat all dragons
  for (auto dragon : dragons)
  {
    if (s > dragon.first)
    {
      s += dragon.second; // Gain bonus after defeating the dragon
    }
    else
    {
      PRINT_NO;
      return;
    }
  }

  PRINT_YES;
  return 0;
}