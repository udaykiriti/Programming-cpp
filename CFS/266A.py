"""
Problem Number: 266A
Contest: Codeforces Round 163 (Div. 2)
Problem Link: https://codeforces.com/problemset/problem/266/A


Problem: A. Stones on the Table

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
"""

def main():
    n = int(input())
    s = input()

    count = 0
    for i in range(n - 1):
        if s[i] == s[i + 1]:
            count += 1

    print(count)

if __name__ == "__main__":
    main()
