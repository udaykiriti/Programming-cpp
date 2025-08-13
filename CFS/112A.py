"""
Problem: Petya and Strings
Petya loves comparing strings lexicographically. He has two strings `s1` and `s2` and wants to compare them in a case-insensitive manner.

Input:
The first line contains the string `s1` (1 ≤ |s1| ≤ 100) — the first string.
The second line contains the string `s2` (1 ≤ |s2| ≤ 100) — the second string.

Output:
Print:
- "1" if `s1` is lexicographically greater than `s2`.
- "-1" if `s1` is lexicographically smaller than `s2`.
- "0" if `s1` is equal to `s2`.

Example:
Input:
aaaa
aaaA
Output:
0

Input:
abs
Abz
Output:
-1
"""

def main():
    s1 = input().strip()
    s2 = input().strip()
    s1 = s1.lower()
    s2 = s2.lower()
    
    if s1 > s2:
        print(1)
    elif s1 < s2:
        print(-1)
    else:
        print(0)

main()