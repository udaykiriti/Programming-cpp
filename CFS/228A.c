#include <stdio.h>

int main() {
    int s1, s2, s3, s4; scanf("%d %d %d %d", &s1, &s2, &s3, &s4);
    int colors[4] = {s1, s2, s3, s4};
    int count = 0;
    for (int i = 0; i < 4; i++) {
        int is_unique = 1;
        for (int j = 0; j < i; j++) {
            if (colors[i] == colors[j]) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique) {
            count++;
        }
    }
    printf("%d\n", 4 - count);
    return 0;
}