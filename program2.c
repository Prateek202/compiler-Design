#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char expr[100];
    int i = 0;

    printf("Enter arithmetic expression: ");
    fgets(expr, sizeof(expr), stdin);

    printf("\nTokens:\n");

    while (expr[i] != '\0') {
        // Skip spaces
        if (expr[i] == ' ') {
            i++;
            continue;
        }

        // Number
        if (isdigit(expr[i])) {
            printf("NUMBER      : ");
            while (isdigit(expr[i])) {
                printf("%c", expr[i]);
                i++;
            }
            printf("\n");
            continue;
        }

        // Identifier (variables)
        if (isalpha(expr[i])) {
            printf("IDENTIFIER  : ");
            while (isalnum(expr[i])) {
                printf("%c", expr[i]);
                i++;
            }
            printf("\n");
            continue;
        }

        // Parentheses
        if (expr[i] == '(' || expr[i] == ')') {
            printf("Symbol : %c\n", expr[i]);
            i++;
            continue;
        }

        // Operators
        if (strchr("+-*/", expr[i])) {
            printf("OPERATOR    : %c\n", expr[i]);
            i++;
            continue;
        }

        // Invalid symbols
        printf("INVALID     : %c\n", expr[i]);
        i++;
    }

    return 0;
}