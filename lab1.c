
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char *str) {
    char keywords[][10] = {"if", "else", "while", "for", "return"};
    for (int i = 0; i < 5; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char ch, str[20];
    int i = 0;

    FILE *fp = fopen("input.txt", "r");

    if (!fp) {
        printf("Cannot open file.\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (isalnum(ch)) {
            str[i++] = ch;
        } else if ((ch == ' ' || ch == '\n' || ch == '\t') && i > 0) {
            str[i] = '\0';
            i = 0;

            if (isKeyword(str))
                printf("KEYWORD: %s\n", str);
            else if (isdigit(str[0]))
                printf("NUMBER: %s\n", str);
            else
                printf("IDENTIFIER: %s\n", str);
        }

        if (ch == '<' || ch == '>' || ch == '=' || ch == '+' || ch == '-' || ch == '*') {
            printf("OPERATOR: %c\n", ch);
        }

        if (ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == ';') {
            printf("SYMBOL: %c\n", ch);
        }
    }

    fclose(fp);
    return 0;
}
