def solve():
    s1, s2, s3, s4 = map(int, input().split())
    unq = {s1, s2, s3, s4}
    print(4 - len(unq))

solve()
