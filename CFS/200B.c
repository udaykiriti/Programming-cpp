#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
 
    float x, sum = 0.0;
    for (int i = 0; i < n; i++) {
        scanf("%f", &x);
        sum += x;
    }
    float avg = sum / n;
    printf("%f\n", avg); 
    return 0;
}