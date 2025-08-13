/* Problem: Division
Codeforces has a rating system that divides participants into divisions based on their ratings.
The divisions are defined as follows:
1. Division 1: rating ≥ 1900
2. Division 2: 1600 ≤ rating < 1900
3. Division 3: 1400 ≤ rating < 1600
4. Division 4: rating < 1400

Input:
The first line contains a single integer t (1 ≤ t ≤ 100) — the number of test cases.
Each of the next t lines contains a single integer rating (−10^9 ≤ rating ≤ 10^9).

Output:
For each test case, print the division the participant belongs to.

Example:
Input:
4
2100
1800
1500
1300
Output:
Division 1
Division 2
Division 3
Division 4
*/

#include <bits/stdc++.h>
using namespace std;
#define FastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define BYE return 0;

void solve()
{
  int rating; cin >> rating;
  if (rating >= 1900) cout << "Division 1" << endl;
  else if (rating >= 1600) cout << "Division 2" << endl;
  else if (rating >= 1400) cout << "Division 3" << endl;
  else cout << "Division 4" << endl;
}

int main()
{
  FastIO;
  int t;cin >> t;
  while (t--) solve();
  BYE;
}