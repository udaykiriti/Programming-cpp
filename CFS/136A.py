

"""
Problem: Presents
Little Petya very much likes gifts. Recently he has received a gift from each of his n friends.
Each friend has delivered exactly one gift to Petya. Now Petya wants to know who gave him which gift.

As you know, friends are numbered with integers from 1 to n. The gifts are numbered with integers
from 1 to n as well. Petya remembers that his friend number i gave him a gift number p[i].
He asked you to help him restore the permutation p.

Input:
The first line contains a single integer n (1 ≤ n ≤ 100) — the number of friends (and gifts).
The second line contains n integers: p[1], p[2], ..., p[n].

Output:
Print n integers: the permutation q where q[i] is the number of the friend who gave the i-th gift.

Example:
Input:
4
2 3 4 1
Output:
4 1 2 3
"""

def main():
    # Read the number of friends
    n = int(input())
    
    # Read the gift array
    arr = list(map(int, input().split()))
    
    # Create an array to store the permutation
    parr = [0] * n
    
    # Map gifts to friends
    for i in range(n):
        parr[arr[i] - 1] = i + 1
    
    # Print the permutation
    print(" ".join(map(str, parr)))

if __name__ == "__main__":
    main()