/* Problem: Way Too Long Words
Sometimes some words like "localization" or "internationalization" are so long that writing them many times in one text is quite tiresome.

Let's consider a word too long, if its length is strictly more than 10 characters. All too long words should be replaced with a special abbreviation.

This abbreviation is made like this: we write down the first and the last letter of a word and between them we write the number of letters between the first and the last letters. That number is in decimal system and doesn't contain any leading zeroes.

Thus, "localization" will be spelt as "l10n", and "internationalization" will be spelt as "i18n".

You are suggested to automatize the process of changing the words with abbreviations. At that all too long words should be replaced by the abbreviation and the words that are not too long should not undergo any changes.

Input:
The first line contains an integer n (1 ≤ n ≤ 100). Each of the following n lines contains one word. All the words consist of lowercase Latin letters and possess the lengths of from 1 to 100 characters.

Output:
Print n lines. The i-th line should contain the result of replacing of the i-th word from the input data.

Example:
Input:
4
word
localization
internationalization
pneumonoultramicroscopicsilicovolcanoconiosis

Output:
word
l10n
i18n
p43s
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int t; cin >> t;
  string s[t];

  FOR(i, 0, t) 
     cin >> s[i];

  FOR(i, 0, t)
  if (s[i].size() > 10)
    cout << s[i][0] << s[i].size() - 2 << s[i][s[i].size() - 1] << endl;
  else
    cout << s[i] << endl;
  return 0;
}