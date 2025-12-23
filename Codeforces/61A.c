#include <stdio.h>
#include <stdlib.h>

int main() {
    const int MAX = 100;
    char *a = (char *)malloc(MAX);
    char *b = (char *)malloc(MAX);
    char *r = (char *)malloc(MAX);
    scanf("%s%s", a,b);
    int i = 0;
    while (a[i] != '\0') {
        r[i] = ((a[i] - '0') ^ (b[i] - '0')) + '0';
        printf("%c", r[i]);
        i++;
    }
    printf("\n");
    free(a); free(b); free(r);
    return 0;
}