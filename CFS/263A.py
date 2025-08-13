

"""
Problem: 263A - Beautiful Matrix
Link: https://codeforces.com/problemset/problem/263/A

Description:
You've got a 5x5 matrix that is filled with zeros and contains a single number one (1).
Your task is to perform a series of moves to bring the 1 to the center of the matrix (position (3,3) or (2,2) in 0-based indexing).
A move is defined as swapping two neighboring rows or two neighboring columns.

Input:
Five lines, each containing five integers (0 or 1). There is exactly one number one in the entire matrix.

Output:
Print the minimum number of moves needed to bring the 1 to the center.

Example:
Input:
0 0 0 0 0
0 0 0 0 0
0 0 1 0 0
0 0 0 0 0
0 0 0 0 0

Output:
0
"""

def main():
    CENTER = 2  # Center index in 0-based (i.e., position 3 in 1-based)
    m = n = 0

    for i in range(5):
        row = list(map(int, input().split()))
        for j in range(5):
            if row[j] == 1:
                m, n = i, j

    moves = abs(m - CENTER) + abs(n - CENTER)
    print(moves)

if __name__ == "__main__":
    main()
