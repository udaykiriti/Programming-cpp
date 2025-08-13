

"""
Problem: I_love_%username%
Petya loves competitive programming and participates in contests regularly. His friend Vasya admires Petya's progress and keeps track of his performance. Over time, Vasya noticed that Petya's performance is sometimes extraordinary, breaking his previous records (either the highest or the lowest score).

Your task is to count how many times Petya breaks his records.

Input:
The first line contains a single integer n (1 ≤ n ≤ 1000) — the number of contests.
The second line contains n integers a1, a2, ..., an (0 ≤ ai ≤ 10000) — the scores Petya achieved in each contest.

Output:
Print a single integer — the number of times Petya breaks his records.

Example:
Input:
4
100 50 200 150
Output:
2

Input:
10
4664 6496 5814 7010 5762 5736 6944 4850 3698 7242
Output:
4
"""

def main():
    # Read the number of contests
    n = int(input())
    
    # Read the scores
    scores = list(map(int, input().split()))
    
    # Initialize counters and records
    count = 0
    max_score = scores[0]
    min_score = scores[0]
    
    # Count the number of record-breaking performances
    for score in scores[1:]:
        if score > max_score:
            count += 1
            max_score = score
        elif score < min_score:
            count += 1
            min_score = score
    
    # Print the result
    print(count)

if __name__ == "__main__":
    main()