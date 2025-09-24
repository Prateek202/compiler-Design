#include <stdio.h>
#include <string.h>

#define SIZE 20

// precedence table (row: stack top, col: input symbol)
// symbols: +, *, i, $
char table[4][4] = {
/* stack/input   +    *    i    $ */
   /* + */      {'>', '<', '<', '>'},
   /* * */      {'>', '>', '<', '>'},
   /* i */      {'>', '>', ' ', '>'},
   /* $ */      {'<', '<', '<', 'A'}  // A = accept
};

int getIndex(char c) {
    switch(c) {
        case '+': return 0;
        case '*': return 1;
        case 'i': return 2;
        case '$': return 3;
    }
    return -1;
}

int main() {
    char stack[SIZE] = "$";  // stack starts with $
    char input[SIZE];
    int top = 0, i = 0;

    printf("Enter expression (operands as 'i', e.g., i+i*i): ");
    scanf("%s", input);
    strcat(input, "$");  // end marker

    printf("\nHere shift means Push and reduce means Pop\n");
    printf("\nStack\tInput\tAction\n");

    while(1) {
        char a = stack[top];   // top of stack
        char b = input[i];     // current input

        if(a == '$' && b == '$') {
            printf("%s\t%s\tACCEPT\n", stack, input+i);
            break;
        }

        int row = getIndex(a);
        int col = getIndex(b);
        char relation = table[row][col];

        if(relation == '<') {
            // shift
            stack[++top] = b;
            stack[top+1] = '\0';
            i++;
            printf("%s\t%s\tShift\n", stack, input+i);
        }
        else if(relation == '>') {
            // reduce
            stack[top--] = '\0';
            printf("%s\t%s\tReduce\n", stack, input+i);
        }
        else if(relation == 'A') {
            printf("%s\t%s\tACCEPT\n", stack, input+i);
            break;
        }
        else {
            printf("%s\t%s\tERROR\n", stack, input+i);
            break;
        }
    }
    return 0;
}
