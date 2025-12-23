/*
Problem Number: 617A
Contest: Codeforces Round 340 (Div. 2)
Problem Link: https://codeforces.com/problemset/problem/617/A


Problem: A. Elephant

An elephant decided to visit his friend. It turned out that the elephant's house is located at point 0
and his friend's house is located at point x (x > 0) on the coordinate line. In one step, the elephant
can move 1, 2, 3, 4, or 5 positions forward. Determine the minimum number of steps he needs to make
to get to his friend's house.

Input:
- A single integer x (1 ≤ x ≤ 1,000,000) — the coordinate of the friend's house.

Output:
- Print the minimum number of steps that the elephant needs to make from point 0 to point x.

Examples:
Input:
5
Output:
1

Input:
12
Output:
3

Note:
- In the first example, the elephant can make one step of length 5.
- In the second, he can take steps of 5, 5, and 2 or 4, 4, 4 — all optimal with 3 steps.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n; cin >> n;
  int steps = n % 5 == 0 ? n / 5 : (n / 5) + 1;
  cout << steps;
  return 0;
}