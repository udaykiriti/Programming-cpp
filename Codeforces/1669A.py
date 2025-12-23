"""
Problem: Division
Codeforces has a rating system that divides participants into divisions based on their ratings.
The divisions are defined as follows:
1. Division 1: rating ≥ 1900
2. Division 2: 1600 ≤ rating < 1900
3. Division 3: 1400 ≤ rating < 1600
4. Division 4: rating < 1400

Input:
The first line contains a single integer t (1 ≤ t ≤ 100) — the number of test cases.
Each of the next t lines contains a single integer rating (−10^9 ≤ rating ≤ 10^9).

Output:
For each test case, print the division the participant belongs to.

Example:
Input:
4
2100
1800
1500
1300
Output:
Division 1
Division 2
Division 3
Division 4
"""

def solve():
    rating = int(input())
    if rating >= 1900:
        print("Division 1")
    elif rating >= 1600:
        print("Division 2")
    elif rating >= 1400:
        print("Division 3")
    else:
        print("Division 4")

def main():
    t = int(input())
    for _ in range(t):
        solve()

main()