/*
*****************************************************************************
                          Workshop - #7 (P1)
Full Name  :
Student ID#:
Email      :
Section    :

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX_pathl 70
#include <stdio.h>
struct playerinfo
{
    int lives;
    char symbol;
    int number_of_treasures;
    int hpositions[MAX_pathl];
};
struct gameinfo
{
    int path_length;
    int max_moves;
    int bombs[MAX_pathl];
    int treasure[MAX_pathl];
};
int main(void)
{
    struct playerinfo player1;
    int i, j = 0, k, b, c, d = 0;
    printf("================================\n"
           "         Treasure Hunt!\n"
           "================================\n");
    printf("\n");
    printf("PLAYER Configuration\n"
           "--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player1.symbol);
    printf("Set the number of lives: ");
    scanf("%d", &player1.lives);
    while (player1.lives < 1 || player1.lives>10) {
        printf("     Must be between 1 and 10!\n");
        printf("Set the number of lives: ");
        scanf("%d", &player1.lives);
    }
    printf("Player configuration set-up is complete\n");
    printf("\n");
    struct gameinfo player;
    printf("GAME Configuration\n"
        "------------------\n");
    printf("Set the path length (a multiple of 5 between 10-70): ");
    scanf("%d", &player.path_length);
    while ((player.path_length % 5) != 0) {
        printf("     Must be a multiple of 5 and between 10-70!!!\n");
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &player.path_length);
    }

    printf("Set the limit for number of moves allowed: ");
    scanf("%d", &player.max_moves);
    while ((player.max_moves < player1.lives) || (player.max_moves > (int)(0.75 * player.path_length))) {
        printf("    Value must be between %d and %d\n", player1.lives, (int)(0.75 * player.path_length));
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &player.max_moves);
    }
    printf("\n");
    printf("BOMB Placement\n"
        "--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n"
        "of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n"
        "(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");
    for (i = 0; i < player.path_length / 5; i++) {
        printf("   Positions [%2d-%2d]: ", (i * 5) + 1, 5 * (i + 1));
        for (k = 0; k < 5; k++) {
            scanf("%d", &player.bombs[j]);
            j++;
        }
    }
    printf("BOMB placement set\n");
    printf("\n");
    printf("TREASURE Placement\n"
        "------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n"
        "of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n"
        "(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");
    for (b = 0; b < player.path_length / 5; b++) {
        printf("   Positions [%2d-%2d]: ", (b * 5) + 1, 5 * (b + 1));
        for (c = 0; c < 5; c++) {
            scanf("%d", &player.treasure[d]);
            d++;
        }
    }
    printf("TREASURE placement set\n");
    printf("\n");
    printf("GAME configuration set-up is complete...\n");
    printf("\n");
    printf("------------------------------------\n"
        "TREASURE HUNT Configuration Settings\n"
        "------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player1.symbol);
    printf("   Lives      : %d\n", player1.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");
    printf("\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", player.path_length);
    printf("   Bombs      : ");
    for (i = 0; i < player.path_length; i++) {
        printf("%d", player.bombs[i]);
    }
    printf("\n   Treasure   : ");
    for (b = 0; b < player.path_length; b++) {
        printf("%d", player.treasure[b]);
    }
    printf("\n");
    printf("\n");
    printf("====================================\n"
        "~ Get ready to play TREASURE HUNT! ~\n"
        "====================================\n");
    printf("\n");
    return 0;
}