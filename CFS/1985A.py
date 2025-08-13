def solve():
    a, b = input().split()

    s1 = b[0] + a[1:]
    s2 = a[0] + b[1:]

    print(s1, s2)

def main():
    t = int(input())
    for _ in range(t):
        solve()
main()
