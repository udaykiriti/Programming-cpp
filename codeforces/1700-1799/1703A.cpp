

/* Problem: YES or YES?
You are given a string s consisting of three letters. Your task is to determine if the string matches the word "YES" in any case (uppercase, lowercase, or mixed).

Input:
The first line contains a single integer t (1 ≤ t ≤ 100) — the number of test cases.
Each of the next t lines contains a single string s consisting of exactly three letters.

Output:
For each test case, print "YES" if the string matches "YES" in any case, otherwise print "NO".

Example:
Input:
3
yEs
yes
no
Output:
YES
YES
NO
*/

#include <bits/stdc++.h>
using namespace std;

#define FastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define PRINT_YES cout << "YES" << endl
#define PRINT_NO cout << "NO" << endl
#define BYE return 0
#define Input(x) cin >> x

void solve()
{
  string s;
  Input(s);
  for (char &c : s) c = toupper(c);
  if (s == "YES") PRINT_YES;
  else PRINT_NO;
}

int main()
{
  FastIO; int t;
  Input(t);
  while (t--) solve();
  BYE;
}