#include <stdio.h>
#include <ctype.h>

int main() {
    char input[100];
    int i = 0;

    printf("Enter an arithmetic expression:\n");
    gets(input);   // unsafe but simple for demo

    printf("\nLexical Analysis:\n");
    while (input[i] != '\0') {
        if (isspace(input[i])) {
            i++;
            continue;
        }

        // Identifiers (variables like x, y, abc)
        if (isalpha(input[i])) {
            printf("%c : Identifier\n", input[i]);
            i++;
        }
        // Numbers
        else if (isdigit(input[i])) {
            printf("%c : Number\n", input[i]);
            i++;
        }
        // Arithmetic operators
        else if (input[i] == '+' || input[i] == '-' || 
                 input[i] == '*' || input[i] == '/' || input[i] == '%') {
            printf("%c : Operator\n", input[i]);
            i++;
        }
        // Parentheses
        else if (input[i] == '(' || input[i] == ')') {
            printf("%c : Parenthesis\n", input[i]);
            i++;
        }
        // Anything else
        else {
            printf("%c : Unknown Symbol\n", input[i]);
            i++;
        }
    }
    return 0;
}
