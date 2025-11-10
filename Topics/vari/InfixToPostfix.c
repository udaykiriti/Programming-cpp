#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    if (top == MAX - 1) {
        printf("\nThe Stack is Full");
        return;
    }
    stack[++top] = item;
}

char pop() {
    if (top == -1) {
        printf("Stack is empty");
        return ' ';
    }
    return stack[top--];
}

int prec(char ch) {
    if (ch == '(')
        return 1;
    else if (ch == ')')
        return 2;
    else if (ch == '+' || ch == '-')
        return 3;
    else if (ch == '/' || ch == '*' || ch == '%')
        return 4;
    else if (ch == '^')
        return 5;
    else
        return 0;
}

void infix_postfix(char infix[]) {
    int len = strlen(infix);
    top = -1; 
    push('(');
    infix[len++] = ')';
    infix[len] = '\0';
    char postfix[MAX];
    char ch;
    int i, j = 0;
    for (i = 0; i < len; i++) {
        int p = prec(infix[i]);
        if (p == 1) {
            push(infix[i]);
        } else if (p == 2) { 
            ch = pop();
            while (ch != '(') {
                postfix[j++] = ch;
                ch = pop();
            }
        } else if (p == 3) { 
            ch = pop();
            while (prec(ch) >= 3) {
                postfix[j++] = ch;
                ch = pop();
            }
            push(ch);
            push(infix[i]);
        } else if (p == 4) { 
            ch = pop();
            while (prec(ch) >= 4) {
                postfix[j++] = ch;
                ch = pop();
            }
            push(ch);
            push(infix[i]);
        } else if (p == 5) { // ^
            ch = pop();
            while (prec(ch) >= 5) {
                postfix[j++] = ch;
                ch = pop();
            }
            push(ch);
            push(infix[i]);
        } else {
            postfix[j++] = infix[i];
        }
    }
    printf("Postfix Expression is : \n");
    for (i = 0; i < j; i++) {
        printf("%c", postfix[i]);
    }
}

int main() {
    char infix[MAX];
    printf("Enter infix Notation : ");
    gets(infix);
    infix_postfix(infix);
    return 0;
}