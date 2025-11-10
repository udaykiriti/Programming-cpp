#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void permutation(char *str, int l, int r) {
    if (l == r) {
        printf("%s\n", str);
    } else {
        for (int i = l; i <= r; i++) {
            char temp = str[l];
            str[l] = str[i];
            str[i] = temp;
            permutation(str, l + 1, r);
            temp = str[l];
            str[l] = str[i];
            str[i] = temp;
        }
    }
}

int main(void){
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    
    int n = strlen(str);
    printf("All permutations of the string are:\n");
    permutation(str, 0, n - 1);
  return 0;
}