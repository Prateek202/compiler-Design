#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char *word) {
    if (strcmp(word, "if") == 0 || strcmp(word, "else") == 0)
        return 1;
    return 0;
}

int main() {
    char input[100];
    char token[20];
    int i = 0, j = 0;

    printf("Enter an IF statement:\n");
    gets(input);  

    printf("\nLexical Analysis:\n");
    while (input[i] != '\0') {
        if (isspace(input[i])) {
            i++;
            continue;
        }

        // identifiers/keywords
        if (isalpha(input[i])) {
            j = 0;
            while (isalnum(input[i])) {
                token[j++] = input[i++];
            }
            token[j] = '\0';
            if (isKeyword(token))
                printf("%s : Keyword\n", token);
            else
                printf("%s : Identifier\n", token);
        }

        // numbers
        else if (isdigit(input[i])) {
            j = 0;
            while (isdigit(input[i])) {
                token[j++] = input[i++];
            }
            token[j] = '\0';
            printf("%s : Number\n", token);
        }

        // operators and symbols
        else {
            if (input[i] == '<' || input[i] == '>' || input[i] == '=' || input[i] == '!') {
                if (input[i+1] == '=') {
                    printf("%c%c : Relational Operator\n", input[i], input[i+1]);
                    i += 2;
                } else {
                    printf("%c : Relational Operator\n", input[i]);
                    i++;
                }
            }
            else if (input[i] == '(' || input[i] == ')' || input[i] == '{' || input[i] == '}') {
                printf("%c : Bracket\n", input[i]);
                i++;
            }
            else {
                printf("%c : Unknown Symbol\n", input[i]);
                i++;
            }
        }
    }
    return 0;
}
