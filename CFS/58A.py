"""
Problem: Chat room
Vasya has recently learned to type and log on to the Internet. He immediately entered a chat room and decided to say hello to everybody.
Vasya typed the word s. It is considered that Vasya managed to say hello if several letters can be deleted from the typed word so that
it results in the word "hello". For example, if Vasya types the word "ahhellllloou", it will be considered that he said hello, and if
he types "hlelo", it will be considered that Vasya got misunderstood and he didn't manage to say hello.

You are required to determine whether Vasya managed to say hello by the given word s.

Input:
The first and the only line contains the word s, which Vasya typed. This word only consists of lowercase English letters and its length
is no more than 100 letters.

Output:
If Vasya managed to say hello, print "YES", otherwise print "NO".

Example:
Input:
ahhellllloou
Output:
YES

Input:
hlelo
Output:
NO
"""

def main():
    s = input()
    target = "hello"
    index = 0
    for char in s:
        if char == target[index]:
            index += 1
        if index == len(target):
            break
    print("YES" if index == len(target) else "NO")

if __name__ == "__main__":
    main()