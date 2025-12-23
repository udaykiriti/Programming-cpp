/* Problem: cAPS lOCK
Sometimes people accidentally leave the Caps Lock key on and type words in uppercase.
Let us imagine that this mistake is corrected automatically by a program.
Write a program that applies the following rules:

1. If all characters in the word are uppercase, convert the entire word to lowercase.
2. If all characters except the first one are uppercase, convert the first character to lowercase
   and the rest to lowercase.
3. In all other cases, leave the word unchanged.

Input:
The input consists of a single word s (1 ≤ |s| ≤ 100), consisting of uppercase and lowercase Latin letters.

Output:
Print the corrected word.

Example:
Input:
cAPS
Output:
Caps

Input:
Lock
Output:
Lock
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define debug(n) cout << (n) << endl;
const ll INF = 2e18 + 99;

void FastIO()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
}

int main()
{
  FastIO();
  string s; cin >> s;
  bool check = true;
  // Check if all characters except the first one are uppercase
  for (int i = 1; i < s.length(); i++)
  {
    if (islower(s[i]))
    {
      check = false;
      break;
    }
  }

  // Apply transformations based on the conditions
  if (isupper(s[0]) && check)
  {
    transform(s.begin(), s.end(), s.begin(), ::tolower); // Convert all to lowercase
  }
  else if (islower(s[0]) && check)
  {
    s[0] = toupper(s[0]); // Convert the first character to uppercase
    for (int i = 1; i < s.length(); i++)
    {
      s[i] = tolower(s[i]); // Convert the rest to lowercase
    }
  }

  cout << s << endl;
  return 0;
}