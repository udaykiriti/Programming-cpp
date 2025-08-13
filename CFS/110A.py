"""
Problem Number: A. Nearly Lucky Number
Problem Link: https://codeforces.com/problemset/problem/110/A

Problem Description:
Petya loves lucky numbers. We all know that lucky numbers are the positive integers whose decimal representations contain only the lucky digits 4 and 7. 
For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

Unfortunately, not all numbers are lucky. Petya calls a number nearly lucky if the number of lucky digits in it is a lucky number. 
He wonders whether number n is a nearly lucky number.

Input:
The only line contains an integer n (1 ≤ n ≤ 10^18).

Output:
Print on the single line "YES" if n is a nearly lucky number. Otherwise, print "NO" (without the quotes).

Example 1:
Input: 40047
Output: NO
Example 2:
Input: 7747774
Output: YES
Example 3:
Input: 1000000000000000000
Output: NO
"""

def main():
    n = int(input())  
    check = 0  
    
    while n > 0:
        rem = n % 10  
        n //= 10  
        if rem == 7 or rem == 4:  
            check += 1 
    
    if check == 4 or check == 7:
        print("YES") 
    else:
        print("NO")  

if __name__ == "__main__":
    main()