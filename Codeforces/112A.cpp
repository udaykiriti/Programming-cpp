/* Problem: Petya and Strings
Petya loves comparing strings lexicographically. He has two strings `s1` and `s2` and wants to compare them in a case-insensitive manner.

Input:
The first line contains the string `s1` (1 ≤ |s1| ≤ 100) — the first string.
The second line contains the string `s2` (1 ≤ |s2| ≤ 100) — the second string.

Output:
Print:
- "1" if `s1` is lexicographically greater than `s2`.
- "-1" if `s1` is lexicographically smaller than `s2`.
- "0" if `s1` is equal to `s2`.

Example:
Input:
aaaa
aaaA
Output:
0

Input:
abs
Abz
Output:
-1
*/

#include <bits/stdc++.h>
using namespace std;
#define FastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define BYE return 0;
#define endl '\n'

int main()
{
  FastIO;
  string s1, s2; cin >> s1 >> s2;

  // Convert both strings to uppercase for case-insensitive comparison
  transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
  transform(s2.begin(), s2.end(), s2.begin(), ::toupper);

  // Compare the strings lexicographically
  if (s1 > s2)
    cout << "1" << endl;
  else if (s1 < s2)
    cout << "-1" << endl;
  else
    cout << "0" << endl;
  return 0;
}