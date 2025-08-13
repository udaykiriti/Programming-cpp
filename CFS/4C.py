

"""
Problem: 4C - Registration System (Codeforces)
Link: https://codeforces.com/problemset/problem/4/C

Description:
A new e-mail service "Berlandesk" is being developed. The system should be able to process requests for registration of new users.
Each request has a name. If the name is not yet registered, the system should register it and respond with "OK".
If the name is already taken, the system should append the smallest integer such that the new name is not taken, and respond with this new name.
"""

def solve():
    n = int(input())
    usernames = {}

    for _ in range(n):
        name = input()
        if name not in usernames:
            print("OK")
            usernames[name] = 1
        else:
            new_name = name + str(usernames[name])
            while new_name in usernames:
                usernames[name] += 1
                new_name = name + str(usernames[name])
            print(new_name)
            usernames[new_name] = 1
            usernames[name] += 1

if __name__ == "__main__":
    solve()
