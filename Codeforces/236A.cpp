/*  
  Problem: Boy or Girl (Codeforces 236A)
  Link: https://codeforces.com/problemset/problem/236/A

  Description:
    Those days, many boys use beautiful girls' photos as avatars in forums.
  So it is pretty hard to tell the gender of a user at first glance.
  Last year, our hero went to a forum and had a nice chat with a beauty (he thought so).
  After that, they talked very often and eventually became a couple online.

  But yesterday, he came to see "her" in the real world and found out "she" is actually a very strong man!
  Our hero is very sad and he is too tired to love again now. So he came up with a way to recognize users' genders by their usernames.

  This is his method: if the number of distinct characters in one's username is odd, then he is a male,
  otherwise, she is a female.

  Input:
  A non-empty string that contains only lowercase English letters — the username.
  This string contains at most 100 characters.

  Output:
  If it is a female by our hero's method, print "CHAT WITH HER!",
  otherwise, print "IGNORE HIM!".



  - You are given a string containing only lowercase English letters.
  - If the number of distinct characters in the string is even, print "CHAT WITH HER!".
  - Otherwise, print "IGNORE HIM!".

  Author: Polymath__
  GitHub: https://github.com/udaykiriti
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
#define YES cout << "CHAT WITH HER!"
#define NO cout << "IGNORE HIM!"

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  string s; cin>>s;
  sort(s.begin(), s.end());
  int count = 1;
  char elem = s[0];
  FOR(i, 0, s.size() - 1)
  if (s[i] != elem)
    elem = s[i], count++;

  (count % 2 == 0) ? YES : NO;
  return 0;
}