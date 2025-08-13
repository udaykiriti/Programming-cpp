def area(lx, rx, ly, ry):
    return (rx - lx + 1) * (ry - ly + 1)

def solve(t):
    for _ in range(t):
        n = int(input())
        p = []
        x = []
        y = []

        for _ in range(n):
            xi, yi = map(int, input().split())
            p.append((xi, yi))
            x.append(xi)
            y.append(yi)

        sx = sorted(x)
        sy = sorted(y)

        mnx, mxx = sx[0], sx[-1]
        cmnx, cmxx = x.count(mnx), x.count(mxx)
        nmnx = sx[cmnx] if cmnx < n else mnx
        nmxx = sx[n - 1 - cmxx] if cmxx < n else mxx

        mny, mxy = sy[0], sy[-1]
        cmny, cmxy = y.count(mny), y.count(mxy)
        nmny = sy[cmny] if cmny < n else mny
        nmxy = sy[n - 1 - cmxy] if cmxy < n else mxy

        init_area = area(mnx, mxx, mny, mxy)
        ans = float('inf')

        for i in range(n):
            xi, yi = p[i]

            l = mnx if xi != mnx or cmnx > 1 else nmnx
            r = mxx if xi != mxx or cmxx > 1 else nmxx
            d = mny if yi != mny or cmny > 1 else nmny
            u = mxy if yi != mxy or cmxy > 1 else nmxy

            dx = r - l + 1
            dy = u - d + 1
            a = dx * dy

            if a > n - 1:
                ans = min(ans, a)
            else:
                ans = min(ans, min((dx + 1) * dy, dx * (dy + 1)))

        print(min(init_area, ans))

if __name__ == "__main__":
    t = int(input())
    solve(t)
