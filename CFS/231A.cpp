/*
Codeforces Round #143 (Div. 2) - Problem A: Team

One day three best friends Petya, Vasya and Tonya decided to form a team
and take part in programming contests. Participants are usually offered several
problems during programming contests. Long before the start the friends decided
that they will implement a problem if at least two of them are sure about the solution.
Otherwise, the friends won't write the problem's solution.

This contest offers n problems to the participants. For each problem we know,
which friend is sure about the solution.

Input:
- The first input line contains a single integer n (1 ≤ n ≤ 1000) —
  the number of problems in the contest.
- Then n lines follow, each containing three integers (0 or 1).
  The first integer represents Petya's confidence, the second Vasya's,
  and the third Tonya's.

Output:
- Print a single integer — the number of problems the friends will implement.

Example:
Input:
3
1 1 0
1 1 1
1 0 0

Output:
2
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FastIO                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n; cin>>n;
  int count = 0;
  FOR(i, 0, n)
  {
    int sure = 0, surity;
    FOR(j, 0, 3)
    {
      cin >> surity;
      sure += surity;
    }
    if (sure >= 2)
      count++;
  }
  cout<<count<<endl;
  return 0;
}