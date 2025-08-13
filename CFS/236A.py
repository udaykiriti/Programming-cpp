"""
Problem: Boy or Girl (Codeforces 236A)
Link: https://codeforces.com/problemset/problem/236/A

Description:
  Those days, many boys use beautiful girls' photos as avatars in forums.
  So it is pretty hard to tell the gender of a user at first glance.
  Last year, our hero went to a forum and had a nice chat with a beauty (he thought so).
  After that, they talked very often and eventually became a couple online.

  But yesterday, he came to see "her" in the real world and found out "she" is actually a very strong man!
  Our hero is very sad and he is too tired to love again now. So he came up with a way to recognize users' genders by their usernames.

  This is his method: if the number of distinct characters in one's username is odd, then he is a male,
  otherwise, she is a female.

Input:
  A non-empty string that contains only lowercase English letters — the username.
  This string contains at most 100 characters.

Output:
  If it is a female by our hero's method, print "CHAT WITH HER!",
  otherwise, print "IGNORE HIM!".

- You are given a string containing only lowercase English letters.
- If the number of distinct characters in the string is even, print "CHAT WITH HER!".
- Otherwise, print "IGNORE HIM!".
"""

def main():
    s = input().strip()
    DC = len(set(s))
    
    if DC % 2 == 0:
        print("CHAT WITH HER!")
    else:
        print("IGNORE HIM!")

if __name__ == "__main__":
    main()
