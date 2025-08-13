

"""
Problem: Word Capitalization
Petya has a string `s` of lowercase and uppercase Latin letters.
Your task is to capitalize the first character of this string.
If the first character is already uppercase, leave it as it is.

Input:
The first line contains a single string `s` (1 ≤ |s| ≤ 1000) — the string that needs capitalization.

Output:
Print the capitalized string.

Example:
Input:
hello
Output:
Hello

Input:
Hello
Output:
Hello
"""

def main():
    s = input().strip()
    
    # Capitalize the first character
    if s:
        s = s[0].upper() + s[1:]
    print(s)

main()