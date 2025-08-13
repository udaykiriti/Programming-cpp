"""
Problem: Codeforces 2A - Winner
--------------------------------
In the end of the competition, each participant has a total score, which is the sum of points he earned during all rounds.
Your task is to find the name of the participant who won the competition. 
If there are multiple participants with the maximum score, the winner is the one who reached that score first.

Input:
- The first line contains an integer n (1≤n≤1000) — the number of rounds.
- The next n lines contain a player's name and the score he earned in that round.

Output:
- Output the name of the winner.

Example:
Input:
3
Mike 3
Andrey 5
Mike 2

Output:
Mike
"""
from collections import defaultdict

def main():
    n = int(input())
    rounds = []
    total_scores = defaultdict(int)
    for _ in range(n):
        name, score = input().split()
        score = int(score)
        rounds.append((name, score))
        total_scores[name] += score

    max_score = max(total_scores.values())

    running_scores = defaultdict(int)
    for name, score in rounds:
        running_scores[name] += score
        if total_scores[name] == max_score and running_scores[name] >= max_score:
            print(name)
            break

main()
