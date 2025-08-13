"""
Problem Number: 734A
Problem Name: A. Anton and Danik
Problem Link: https://codeforces.com/problemset/problem/734/A

Problem Statement:
Anton likes to play chess, and so does his friend Danik.

Once they have played n games in a row. For each game it's known who was the winner — Anton or Danik. None of the games ended with a tie.

Now Anton wonders, who won more games, he or Danik? Help him determine this.

Input:
- The first line of the input contains a single integer n (1 ≤ n ≤ 100,000) — the number of games played.
- The second line contains a string s, consisting of n uppercase English letters 'A' and 'D' — the outcome of each of the games.
  The i-th character of the string is equal to 'A' if Anton won the i-th game and 'D' if Danik won the i-th game.

Output:
- If Anton won more games than Danik, print "Anton" (without quotes) in the only line of the output.
- If Danik won more games than Anton, print "Danik" (without quotes) in the only line of the output.
- If Anton and Danik won the same number of games, print "Friendship" (without quotes).

Examples:
Input:
6
ADAAAA
Output:
Anton

Input:
7
DDDAADA
Output:
Danik

Input:
6
DADADA
Output:
Friendship

Explanation:
In the first sample, Anton won 6 games, while Danik won only 1. Hence, the answer is "Anton".
In the second sample, Anton won 3 games and Danik won 4 games, so the answer is "Danik".
In the third sample, both Anton and Danik won 3 games, so the answer is "Friendship".
"""

def solve():
    n = int(input())  
    s = input() 
    
    a, d = 0, 0   
    for game in s:
        if game == 'A':
            a += 1
        elif game == 'D':
            d += 1
    if a > d:
        print("Anton")
    elif a < d:
        print("Danik")
    else:
        print("Friendship")

solve()