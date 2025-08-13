#include<stdio.h>
#include<string.h>
#include<ctype.h>

int number(char s[], int start, int end) {
    int num = 0;
    for (int i = start; i < end; i++) {
        if (!isdigit(s[i])) return -1;
        num = num * 10 + (s[i] - '0');
    }
    return num;
}
int SumOfDigits(char s[]) {
    int sum = 0;
    for (int i = 0; s[i]; i++) {
        if (isdigit(s[i])) sum += s[i] - '0';
    }
    return sum;
}
int ValidDate(char s[]) {
    int l = strlen(s);
    if (l != 10) return 0;
    if (!((s[2] == '/' || s[2] == '-' || s[2] == '.') && (s[2] == s[5]))) return 0;
    int d = number(s, 0, 2);
    int m = number(s, 3, 5);
    int y = number(s, 6, 10);
    if ((d > 0 && d < 32) && (m > 0 && m < 13) && (y > 1899 && y < 3000)) return SumOfDigits(s);
    else return 0;
}
int main() {
    char s[100]; scanf("%s", s);
    int c = ValidDate(s);
    printf("%d", c);
    return 0;
}