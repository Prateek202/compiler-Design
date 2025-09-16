#include <stdio.h>
#include <string.h>

char stack[50], input[50];
int top = -1;

void push(char c) {
    stack[++top] = c;
    stack[top+1] = '\0';
}

void pop() {
    if (top >= 0) {
        stack[top] = '\0';
        top--;
    }
}

int check() {
    // Apply reductions based on grammar rules
    // E -> id
    if (top >= 1 && stack[top] == 'd' && stack[top-1] == 'i') {
        pop(); pop();
        push('E');
        return 1;
    }
    // E -> (E)
    if (top >= 2 && stack[top] == ')' && stack[top-2] == '(' && stack[top-1] == 'E') {
        pop(); pop(); pop();
        push('E');
        return 1;
    }
    // E -> E+E
    if (top >= 2 && stack[top] == 'E' && stack[top-1] == '+' && stack[top-2] == 'E') {
        pop(); pop(); pop();
        push('E');
        return 1;
    }
    // E -> E*E
    if (top >= 2 && stack[top] == 'E' && stack[top-1] == '*' && stack[top-2] == 'E') {
        pop(); pop(); pop();
        push('E');
        return 1;
    }
    return 0;
}

int main() {
    int i=0, len;

    printf("Shift Reduce Parsing\n");
    printf("---------------------\n");
    printf("Grammar Used:\n");
    printf("1. E → E+E\n");
    printf("2. E → E*E\n");
    printf("3. E → (E)\n");
    printf("4. E → id\n\n");

    printf("Enter the input string (use id for identifiers): ");
    scanf("%s", input);

    len = strlen(input);
    printf("\nSTACK\tINPUT\tACTION\n");
    printf("-----\t-----\t------\n");

    while (i < len) {
        // Shift
        push(input[i]);
        i++;
        printf("%s\t%s\tShift\n", stack, input+i);

        // Try reductions repeatedly
        while (check()) {
            printf("%s\t%s\tReduce\n", stack, input+i);
        }
    }

    // Final check
    if (strcmp(stack, "E") == 0 && i == len) {
        printf("\nString Accepted!\n");
    } else {
        printf("\nString Rejected!\n");
    }

    return 0;
}

