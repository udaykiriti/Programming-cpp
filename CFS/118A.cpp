/*
Problem Number: 118A
Contest: Codeforces Beta Round 89 (Div. 2)
Problem Link: https://codeforces.com/problemset/problem/118/A

Problem: A. String Task

Petya started to attend programming lessons. On the first lesson his task was to write a simple program.
The program was supposed to do the following on a given string (containing only uppercase and lowercase Latin letters):

1. Delete all the vowels.
2. Insert a character '.' before each consonant.
3. Replace all uppercase consonants with their lowercase equivalents.

Vowels are letters: "A", "O", "Y", "E", "U", "I".
All other letters are consonants.

Input:
- A single string containing only uppercase and lowercase Latin letters.
- The length of the string is between 1 and 100, inclusive.

Output:
- A single string that results after processing the original string using the three rules mentioned.

Examples:
Input:
tour
Output:
.t.r

Input:
Codeforces
Output:
.c.d.f.r.c.s

Input:
aBAcAba
Output:
.b.c.b
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define debug(n) cout << (n) << endl;
const ll INF = 2e18 + 99;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  string s, r = ""; cin >> s;
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  for (auto i : s)
  {
    if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'y' || i == 'u')
    {
      continue;
    }
    else
    {
      r += ".";
      r += i;
    }
  }
  cout << r << endl;
}