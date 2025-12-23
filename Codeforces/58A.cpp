/* Problem: Chat room
Vasya has recently learned to type and log on to the Internet. He immediately entered a chat room and decided to say hello to everybody.
Vasya typed the word s. It is considered that Vasya managed to say hello if several letters can be deleted from the typed word so that
it results in the word "hello". For example, if Vasya types the word "ahhellllloou", it will be considered that he said hello, and if
he types "hlelo", it will be considered that Vasya got misunderstood and he didn't manage to say hello.

You are required to determine whether Vasya managed to say hello by the given word s.

Input:
The first and the only line contains the word s, which Vasya typed. This word only consists of lowercase English letters and its length
is no more than 100 letters.

Output:
If Vasya managed to say hello, print "YES", otherwise print "NO".

Example:
Input:
ahhellllloou
Output:
YES

Input:
hlelo
Output:
NO
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define debug(n) cout << (n) << endl;
const ll INF = 2e18 + 99;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  string s, r = ""; cin >> s;
  // Check if the word contains "hello" in order
  for (auto i : s)
  {
    if (i == 'h' && r == "")
      r += i;
    else if (i == 'e' && r[r.length() - 1] == 'h')
      r += i;
    else if (i == 'l' && r[r.length() - 1] == 'e')
      r += i;
    else if (i == 'l' && r[r.length() - 2] == 'e' && r[r.length() - 1] == 'l')
      r += i;
    else if (i == 'o' && r[r.length() - 1] == 'l' && r[r.length() - 2] == 'l' && r[r.length() - 3] == 'e')
      r += i;
  }
  // If the resulting string is "hello", print "YES", otherwise print "NO"
  (r == "hello") ? cout << "YES" << endl : cout << "NO" << endl;
  return 0;
}