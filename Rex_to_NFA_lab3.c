#include <stdio.h>
#include <string.h>

// Function to display transition
void addTransition(char from, char to, char symbol) {
    printf("  %c -- %c --> %c\n", from, symbol, to);
}

int main() {
    char regex[20];
    printf("Enter a simple regular expression (a, ab, a|b, a*): ");
    scanf("%s", regex);

    printf("\nNFA Construction:\n");

    // Case 1: Single symbol
    if (strlen(regex) == 1) {
        addTransition('q0', 'q1', regex[0]);
        printf("Start state: q0\nFinal state: q1\n");
    }
    // Case 2: Concatenation (e.g., ab)
    else if (strlen(regex) == 2 && regex[0] != '|' && regex[1] != '|') {
        addTransition('q0', 'q1', regex[0]);
        addTransition('q1', 'q2', regex[1]);
        printf("Start state: q0\nFinal state: q2\n");
    }
    // Case 3: Union (e.g., a|b)
    else if (regex[1] == '|') {
        printf("  q0 -- e --> q1\n");
        addTransition('q1', 'q2', regex[0]);
        printf("  q0 -- e --> q3\n");
        addTransition('q3', 'q4', regex[2]);
        printf("  q2 -- e --> qf\n");
        printf("  q4 -- e --> qf\n");
        printf("Start state: q0\nFinal state: qf\n");
    }
    // Case 4: Kleene star (e.g., a*)
    else if (regex[1] == '*') {
        printf("  q0 -- e --> q1\n");
        addTransition('q1', 'q2', regex[0]);
        printf("  q2 -- e --> q1\n");
        printf("  q1 -- e --> qf\n");
        printf("  q0 -- e --> qf\n");
        printf("Start state: q0\nFinal state: qf\n");
    }
    else {
        printf("Currently, only simple expressions (a, ab, a|b, a*) are supported.\n");
    }

    return 0;
}
