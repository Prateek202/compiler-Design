#include <stdio.h>
#include <string.h>

#define STATES 10
#define SYMBOLS 2   // assuming input symbols = {0,1}

int nfa[STATES][SYMBOLS][STATES];  // NFA transition table
int n, finalState;

// Function to print DFA state set
void printSet(int set[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++)
        printf("q%d ", set[i]);
    printf("}");
}

int main() {
    int i, j, k, t, dfaStates = 1;
    int dfa[STATES][SYMBOLS][STATES];
    int dfaSize[STATES][SYMBOLS];
    int visited[STATES] = {0};
    
    printf("Enter number of NFA states: ");
    scanf("%d", &n);

    printf("Enter final state of NFA: ");
    scanf("%d", &finalState);

    // Input NFA transitions
    printf("\nEnter transitions (for each state and symbol, enter -1 to stop):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < SYMBOLS; j++) {
            printf("From q%d on symbol %d: ", i, j);
            k = 0;
            while (1) {
                scanf("%d", &t);
                if (t == -1) break;
                nfa[i][j][k++] = t;
            }
        }
    }

    // Start DFA construction
    printf("\nDFA transitions:\n");
    printf("State\tInput=0\tInput=1\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < SYMBOLS; j++) {
            k = 0;
            for (t = 0; nfa[i][j][t] != 0; t++) {
                dfa[i][j][k++] = nfa[i][j][t];
            }
            dfaSize[i][j] = k;

            printf("q%d\t", i);
            printSet(dfa[i][j], dfaSize[i][j]);
            printf("\t");
        }
        printf("\n");
    }

    return 0;
}


INPUT 1:

Enter number of NFA states: 3
Enter final state of NFA: 2

Enter transitions (for each state and symbol, enter -1 to stop):
From q0 on symbol 0: 1 -1
From q0 on symbol 1: 2 -1
From q1 on symbol 0: 2 -1
From q1 on symbol 1: -1
From q2 on symbol 0: -1
From q2 on symbol 1: -1

Input 2 :

Enter number of NFA states: 3
Enter final state of NFA: 1

From q0 on symbol 0: 1 2 -1
From q0 on symbol 1: 1 -1
From q1 on symbol 0: -1
From q1 on symbol 1: 2 -1
From q2 on symbol 0: 2 -1
From q2 on symbol 1: -1


    Input 3
Enter number of NFA states: 2
Enter final state of NFA: 1

From q0 on symbol 0: 1 -1
From q0 on symbol 1: 1 -1
From q1 on symbol 0: -1
From q1 on symbol 1: 1 -1
