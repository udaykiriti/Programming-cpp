/*
    Codeforces - 1030A - In Search of an Easy Problem
    Problem link: https://codeforces.com/problemset/problem/1030/A

    ---------------------------------------------------------------
    Problem description:

    When preparing a tournament, Codeforces coordinators try their best to make the first problem as easy as possible.
    This time the coordinator had chosen some problem and asked n people about their opinions.
    Each person answered whether this problem is easy or hard.

    If at least one of these n people has answered that the problem is hard, the coordinator decides to change the problem.
    For the given responses, check if the problem is easy enough.

    Input:
    The first line contains a single integer n (1≤n≤100) — the number of people who were asked to give their opinions.
    The second line contains n integers, each integer is either 0 or 1.
    If i-th integer is 0, then i-th person thinks that the problem is easy; if it is 1, then i-th person thinks that the problem is hard.

    Output:
    Print one word: "EASY" if the problem is easy according to all responses, or "HARD" if there is at least one person who thinks the problem is hard.

    You may print every letter in any register: "EASY", "easy", "EaSY" and "eAsY" all will be processed correctly.

    Example:
    Input:
    3
    0 0 1
    Output:
    HARD

    Input:
    1
    0
    Output:
    EASY
    ---------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n, m, r = 0; cin >> n;
  FOR(i, 0, n)
  {
    cin >> m;
    r |= m;
    if (r == 1)
    {
      cout << "HARD";
      return 0;
    }
  }
  cout << "EASY";
  return 0;
}