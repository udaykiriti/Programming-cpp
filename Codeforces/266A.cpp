/*Problem: A. Stones on the Table
Source: Codeforces Round 163 (Div. 2)

There are n stones on the table in a row, each of them can be red, green or blue.
Count the minimum number of stones to take from the table so that any two
neighboring stones had different colors. Stones are neighboring if there are no
other stones between them.

Input:
- The first line contains an integer n (1 ≤ n ≤ 50) — the number of stones.
- The second line contains a string s of length n, composed of 'R', 'G', and 'B'.

Output:
- Print a single integer — the minimum number of stones to remove.

Examples:
Input:
3
RRG
Output:
1

Input:
5
RRRRR
Output:
4

Input:
4
BRBG
Output:
0
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n; cin>>n;
  string s; cin>>s;
  int count = 0;
  FOR(i, 0, n - 1)
    if(s[i]== s[i + 1]) 
      count++;
  cout<<count<<endl;
  return 0;
}