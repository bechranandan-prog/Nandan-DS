#include <stdio.h>
#include <ctype.h>

char stack[50];
int top = -1;

int priority(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

int main() {
    char infix[50], postfix[50];
    int i, j = 0;

    printf("Enter infix: ");
    scanf("%s", infix);

    for (i = 0; infix[i]; i++) {
        char c = infix[i];

        if (isalnum(c))
            postfix[j++] = c;
        else {
            while (top >= 0 && priority(stack[top]) >= priority(c))
                postfix[j++] = stack[top--];

            stack[++top] = c;
        }
    }

    while (top >= 0)
        postfix[j++] = stack[top--];

    postfix[j] = '\0';

    printf("Postfix: %s", postfix);
    return 0;
}