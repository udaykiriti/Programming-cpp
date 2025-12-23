"""
Problem: Insert Digit
You are given a positive integer n and a digit d (0 ≤ d ≤ 9). You are also given a string s of length n, consisting of digits.
You need to insert the digit d into the string s in such a way that the resulting number is as large as possible.

Input:
The first line contains a single integer t (1 ≤ t ≤ 1000) — the number of test cases.
Each test case consists of two lines:
- The first line contains two integers n and d (1 ≤ n ≤ 100, 0 ≤ d ≤ 9).
- The second line contains a string s of length n.

Output:
For each test case, print the resulting string after inserting d to maximize the number.
"""

def solve():
    n, d = input().split()
    n = int(n)
    s = input()
    inserted = False
    for i in range(n):
        if not inserted and s[i] < d:
            print(d, end='')
            inserted = True
        print(s[i], end='')
    if not inserted:
        print(d, end='')
    print()

def main():
    t = int(input())
    for _ in range(t):
        solve()

main()