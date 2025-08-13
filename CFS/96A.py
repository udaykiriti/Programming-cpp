"""
Problem Number: A. Football
Problem Link: https://codeforces.com/problemset/problem/96/A


Problem Description:

Petya loves football very much. One day, as he was watching a football match,
he was writing the players' current positions on a piece of paper. To simplify
the situation, he depicted it as a string consisting of zeroes and ones. A zero
corresponds to players of one team, and a one corresponds to players of another team.

If there are at least 7 players of some team standing one after another,
then the situation is considered dangerous.

For example, the situation 00100110111111101 is dangerous, and 11110111011101 is not.

You are given the current situation. Determine whether it is dangerous or not.

Input:
- The first input line contains a non-empty string consisting of characters "0" and "1",
  which represents players. The length of the string does not exceed 100 characters.
  There's at least one player from each team present on the field.

Output:
- Print "YES" if the situation is dangerous. Otherwise, print "NO".

Examples:
1. Input:
   001001
   Output:
   NO

2. Input:
   1000000001
   Output:
   YES

Constraints:
- The length of the string is at most 100 characters.
- There's at least one "0" and one "1" in the string.
"""

def main():
    s = input().strip()   
    elem = '2'  
    maxi = 0 
    count = 0  
    
    for i in s:
        if i != elem:
            elem = i
            count = 1  
            continue
        count += 1
        maxi = max(maxi, count)  
        if maxi == 7: 
            print("YES")
            return 
    
    print("NO")


if __name__ == "__main__":
    main()