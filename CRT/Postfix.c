#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if (top >= MAX - 1) {
        printf("Stack OverFlow\n");
        exit(1);
    }
    stack[++top] = val;
}

int pop() {
    if (top < 0) {
        printf("Stack UnderFlow\n");
        exit(1);
    }
    return stack[top--];
}

int main() {
    char str[100];
    printf("Enter Postfix expression: ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            push(str[i] - '0');
        } else {
            int b = pop();
            int a = pop();
            if (str[i] == '+') {
                push(a + b);
            } else if (str[i] == '-') {
                push(a - b);
            } else if (str[i] == '*') {
                push(a * b);
            } else if (str[i] == '/') {
                push(a / b);
            } else {
                printf("Invalid operator: %c\n", str[i]);
                exit(1);
            }
        }
    }
    printf("Result : %d\n", stack[top]);
    return 0;
}