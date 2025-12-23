/* Problem: Word Capitalization
Petya has a string `s` of lowercase and uppercase Latin letters.
Your task is to capitalize the first character of this string.
If the first character is already uppercase, leave it as it is.

Input:
The first line contains a single string `s` (1 ≤ |s| ≤ 1000) — the string that needs capitalization.

Output:
Print the capitalized string.

Example:
Input:
hello
Output:
Hello

Input:
Hello
Output:
Hello
*/

#include <bits/stdc++.h>
using namespace std;
#define BYE return 0

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  string s; cin >> s;
  // Capitalize the first character if it is lowercase
  if (s[0] >= 'a' && s[0] <= 'z')
    s[0] = s[0] - ('a' - 'A'); // Convert to uppercase
  cout << s << endl;
  BYE;
}