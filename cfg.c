#include <stdio.h>
#include <ctype.h> // Include ctype.h for tolower function

void print_state(int chicken, int fox, int grain, int boat, int moves) {
    printf("***************************************\n");
    printf("            Current State              \n");
    printf("***************************************\n");
    printf("Chicken: %s\n", chicken ? "Left" : "Right");
    printf("Fox: %s\n", fox ? "Left" : "Right");
    printf("Grain: %s\n", grain ? "Left" : "Right");
    printf("Boat: %s\n", boat ? "Left" : "Right");
    printf("Total Moves: %d\n", moves);
    printf("***************************************\n\n");

    printf("***************************************\n");
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            if (row == 0 && col == (chicken ? 0 : 3)) printf(" C ");
            else if (row == 1 && col == (fox ? 0 : 3)) printf(" F ");
            else if (row == 2 && col == (grain ? 0 : 3)) printf(" G ");
            else if (row == 3 && col == (boat ? 0 : 3)) printf(" B ");
            else if (col == 1 || col == 2) printf(" ~ ");
            else printf(" . ");
        }
        printf("\n");
    }
    printf("***************************************\n\n");
}

int main() {
    int chicken = 1, fox = 1, grain = 1, boat = 1; // All start on the left bank
    int moves = 0; // Initialize move counter

    printf("Welcome to the Chicken, Fox, and Grain Game!\n");

    while (1) {
        print_state(chicken, fox, grain, boat, moves);

        // Check win condition
        if (chicken == 0 && fox == 0 && grain == 0) {
            printf("Congratulations! You've successfully transported all!\n");
            break;
        }

        // Check for game over (unacceptable state)
        if ((chicken == fox && chicken != boat) || (chicken == grain && chicken != boat)) {
            printf("Game over! You left the chicken with the fox or grain!\n");
            break;
        }

        // Get user input for the next move
        char move;
        printf("Choose your move (c: transport chicken, f: transport fox, g: transport grain, n: do nothing): ");
        scanf(" %c", &move);
        move = tolower(move); // Convert input to lowercase

        // Process the move
        int* item = NULL; // Pointer to the item being moved
        if (move == 'c') item = &chicken;
        else if (move == 'f') item = &fox;
        else if (move == 'g') item = &grain;

        // Check if a valid item was selected
        if (item != NULL) {
            if (boat == 1) { // Boat is on the left bank
                *item = 0; // Move the item to the right bank
            } else {
                *item = 1; // Move the item to the left bank
            }
            boat = !boat; // Move the boat
            moves++; // Increment the move counter
        } else if (move == 'n') {
            boat = !boat; // Move the boat without transporting anything
        } else {
            printf("Invalid move. Please try again.\n");
            continue; // Skip the rest of the loop and prompt for input again
        }

        // Check for unacceptable state after the move
        if ((chicken == fox && chicken != boat) || (chicken == grain && chicken != boat)) {
            printf("Game over! You left the chicken with the fox or grain!\n");
            break;
        }
    }

    printf("***************************************\n");
    printf("               Game Over               \n");
    printf("***************************************\n");

    return 0;
}
