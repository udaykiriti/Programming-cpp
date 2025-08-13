"""
Problem: IQ test
Bob is preparing to pass an IQ test. The most frequent task in this test is to find out which one of the given n numbers differs from the others. Bob observed that one number usually differs from the others in evenness. Help Bob — to check his answers, he needs a program that among the given n numbers finds one that is different in evenness.

Input:
The first line contains a single integer n (3 ≤ n ≤ 100) — the number of numbers in the task.
The second line contains n space-separated integers a1, a2, ..., an (1 ≤ ai ≤ 100).

Output:
Output the 1-based index of the number that differs from the others in evenness.

Example:
Input:
5
2 4 7 8 10
Output:
3

Input:
4
1 2 1 1
Output:
2
"""

def main():
    n = int(input())    
    nums = list(map(int, input().split()))    
    even_count = sum(1 for num in nums if num % 2 == 0)    
    for i in range(n):
        if (even_count > 1 and nums[i] % 2 != 0) or (even_count == 1 and nums[i] % 2 == 0):
            print(i + 1)
            break

if __name__ == "__main__":
    main()