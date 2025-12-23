/*
--------------------------------------------
Codeforces Problem 3A - "Shortest path of the king"
--------------------------------------------

Chess is a game played on a square board of 8×8 cells. Every cell has a unique coordinate,
which is identified by a string consisting of two characters. The first character is a letter 
from 'a' to 'h' (denoting the column), and the second one is a digit from '1' to '8' (denoting the row).

The king can move one square in any direction — horizontally, vertically, or diagonally.

Given the starting and ending position of the king, your task is to determine the minimum number
of moves needed for the king to reach the destination. Also, you must output any one sequence of moves
that leads the king from the start to the destination in the minimum number of moves.

Each move must be printed as a string:
- "R" (right),
- "L" (left),
- "U" (up),
- "D" (down),
- "RU", "LU", "RD", "LD" (combinations for diagonal moves).

--------------------------------------------
Input
--------------------------------------------
Two strings in the format described above:
- The first is the initial position of the king.
- The second is the target position.

--------------------------------------------
Output
--------------------------------------------
First, print a single integer k — the minimum number of moves.

Then print k lines, each line containing one move of the king.

If there are multiple possible sequences of moves, print any.

--------------------------------------------
Example
--------------------------------------------
Input:
a1
h8

Output:
7
RU
RU
RU
RU
RU
RU
RU
--------------------------------------------
*/


#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INPUT(s, t) cin >> s >> t
#define OUTPUT(x) cout << x << endl
#define MOVE_X(c1, c2, move1, move2) \
    if (c1 < c2) { cout << move1; c1++; } \
    else if (c1 > c2) { cout << move2; c1--; }

int main()
{
    string s, t; cin>>s>>t;
    OUTPUT(max(abs(s[0] - t[0]), abs(s[1] - t[1])));

    while (s != t)
    {
        MOVE_X(s[0], t[0], "R", "L");
        MOVE_X(s[1], t[1], "U", "D");
        cout << endl;
    }
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
// #define endl '\n'

// int main()
// {
//   string s, t;
//   cin >> s >> t;
//   cout << max(abs(s[0] - t[0]), abs(s[1] - t[1])) << endl;
//   while (s != t)
//   {
//     if (s[0] < t[0])
//     {
//       cout << "R";
//       s[0] += 1;
//     }
//     else if (s[0] > t[0])
//     {
//       cout << "L";
//       s[0] -= 1;
//     }

//     if (s[1] < t[1])
//     {
//       cout << "U";
//       s[1] += 1;
//     }
//     else if (s[1] > t[1])
//     {
//       cout << "D";
//       s[1] -= 1;
//     }

//     cout << endl;
//   }
//   return 0;
// }