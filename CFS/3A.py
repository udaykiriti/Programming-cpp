"""
--------------------------------------------
Codeforces Problem 3A - "Shortest path of the king"
--------------------------------------------

Chess is a game played on a square board of 8x8 cells. Every cell has a unique coordinate,
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
"""

def main():
    s = input()
    t = input()

    x1, y1 = ord(s[0]), int(s[1])
    x2, y2 = ord(t[0]), int(t[1])

    moves = []

    while (x1, y1) != (x2, y2):
        move = ""
        if x1 < x2:
            move += "R"
            x1 += 1
        elif x1 > x2:
            move += "L"
            x1 -= 1

        if y1 < y2:
            move += "U"
            y1 += 1
        elif y1 > y2:
            move += "D"
            y1 -= 1

        moves.append(move)

    print(len(moves))
    for m in moves:
        print(m)

if __name__ == "__main__":
    main()
