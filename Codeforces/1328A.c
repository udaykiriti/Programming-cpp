#include <stdio.h>

void solve() {
    int a, b; scanf("%d %d", &a, &b);
    int remainder = a % b;
    if (remainder == 0) printf("0\n");
    else printf("%d\n", b - remainder);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) solve();
    return 0;
}