#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char x) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

int isBalanced(char str[]) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (top == -1) {
                return 0;
            }
            char popped = pop();
            if ((str[i] == ')' && popped != '(') ||
                (str[i] == '}' && popped != '{') ||
                (str[i] == ']' && popped != '[')) {
                return 0;
            }
        }
    }
    return (top == -1);
}
int main() {
    char str[MAX_SIZE];
    printf("Enter the expression: ");
    scanf("%s", str);
    
    if (isBalanced(str)) {
        printf("Balanced\n");
    } else {
        printf("Unbalanced\n");
    }
    return 0;
} 