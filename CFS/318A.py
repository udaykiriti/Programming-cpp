n, m = map(int, input().split())

if n % 2 == 1:
    if m <= (n // 2 + 1):
        print(2 * m - 1)
    else: 
        print(2 * (m - (n // 2 + 1)))
else:
    if m <= (n // 2):
        print(2 * m - 1)
    else:
        print(2 * (m - (n // 2)))
