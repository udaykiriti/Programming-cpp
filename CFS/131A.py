

"""
Problem: cAPS lOCK
Sometimes people accidentally leave the Caps Lock key on and type words in uppercase. 
Let us imagine that this mistake is corrected automatically by a program. 
Write a program that applies the following rules:
 
1. If all characters in the word are uppercase, convert the entire word to lowercase.
2. If all characters except the first one are uppercase, convert the first character to uppercase 
   and the rest to lowercase.
3. In all other cases, leave the word unchanged.
 
Input:
The input consists of a single word s (1 ≤ |s| ≤ 100), consisting of uppercase and lowercase Latin letters.
 
Output:
Print the corrected word.
 
Example:
Input:
cAPS
Output:
Caps
 
Input:
Lock
Output:
Lock
"""

def main():
    # Read the input word
    s = input()

    # Check if all characters are uppercase
    if s.isupper():
        print(s.lower())  # Convert the entire word to lowercase
    # Check if all characters except the first one are uppercase
    elif s[0].islower() and s[1:].isupper():
        print(s[0].upper() + s[1:].lower())  # Convert the first character to uppercase and the rest to lowercase
    # Handle the case where the input is a single lowercase letter
    elif len(s) == 1 and s.islower():
        print(s.upper())  # Convert the single lowercase letter to uppercase
    else:
        print(s)  # Leave the word unchanged

if __name__ == "__main__":
    main()