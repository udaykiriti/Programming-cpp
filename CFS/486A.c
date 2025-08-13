#include <stdio.h>
#define ll long long

int main() {
    ll n; scanf("%lld", &n); 
    ll evn = n / 2;
    ll oddn = (n % 2 == 0) ? (n / 2) : (n / 2 + 1);  
    ll sumevn = evn * (evn + 1);
    ll sumoddn = oddn * oddn;
    ll sum = sumevn - sumoddn;
    printf("%lld\n", sum); 
    return 0;
}