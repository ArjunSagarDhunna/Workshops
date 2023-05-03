/*
*****************************************************************************
                          Workshop - #7 (P2)
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
#include <stdio.h>
#define max_live 10
#define max_moves 15


struct GameInfo
{
    int max_MOVE, path, bombs[70], treasure[70];
};
struct PlayerInfo
{
    int live, treasureFound, move;
    char symbol, his[70];
};

int main(void)
{
    int i, j, storage = 0, temp;
    struct PlayerInfo player;
    struct GameInfo game;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");

    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.symbol);
    do
    {
        printf("Set the number of lives: ");
        scanf("%d", &player.live);

        if (1 <= player.live && player.live <= max_live)
        {
            storage = 1;
        }
        else
        {
            printf("     Must be between 1 and %d!\n", max_live);
        }
    } while (storage == 0);
    for (i = 0; i < 70; i++)
    {
        player.his[i] = '-';
    }
    if (storage == 1)
    {
        printf("Player configuration set-up is complete\n\n");
        storage = 0;
    }

    printf("GAME Configuration\n");
    printf("------------------\n");
    do
    {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &game.path);

        if (game.path % 5 == 0 && 10 <= game.path && game.path <= 70)
        {
            do
            {
                printf("Set the limit for number of moves allowed: ");
                scanf("%d", &game.max_MOVE);
                if (3 <= game.max_MOVE && game.max_MOVE <= max_moves)
                {
                    storage = 1;
                }
                else
                {
                    printf("    Value must be between 3 and %2d\n", max_moves);
                }
            } while (storage == 0);
        }
        else
        {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
    } while (storage == 0);
    storage = 0;
    printf("\n");
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.path);
    for (i = 0; i < game.path; i = i + 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 1 + 4);
        for (j = i; j <= i + 4; j++)
        {
            scanf("%d", &game.bombs[j]);
        }
    }
    printf("BOMB placement set\n");
    printf("\n");
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.path);
    for (i = 0; i < game.path; i = i + 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 1 + 4);
        for (j = i; j <= i + 4; j++)
        {
            scanf("%d", &game.treasure[j]);
        }
    }
    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.symbol);
    printf("   Lives      : %d\n", player.live);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");
    printf("\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", game.path);
    printf("   Bombs      : ");
    for (i = 0; i < game.path; i++)
    {
        printf("%d", game.bombs[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < game.path; i++)
    {
        printf("%d", game.treasure[i]);
    }
    printf("\n");
    printf("\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    player.move = 0;
    player.treasureFound = 0;
    do
    {
        if (player.move != 0)
        {
            printf("  ");
            for (i = 0; i < player.move - 1; i++)
            {
                printf(" ");
            }
            printf("%c", player.symbol);
        }
        printf("\n  ");
        for (i = 0; i < game.path; i++)
        {
            printf("%c", player.his[i]);
        }
        printf("\n  ");
        for (i = 1; i <= game.path; i++)
        {
            if (i % 10 == 0)
            {
                printf("%d", (i / 10));
            }
            else
            {
                printf("|");
            }
        }
        printf("\n  ");
        for (i = 1; i <= game.path; i++)
        {
            if (i % 10 == 0)
            {
                printf("0");
            }
            else
            {
                if (i < 10)
                {
                    printf("%d", i);
                }
                else
                {
                    printf("%d", (i % 10));
                }
            }
        }
        printf("\n");
        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.live, player.treasureFound, game.max_MOVE);
        printf("+---------------------------------------------------+\n");

        temp = 0;
        do
        {
            printf("Next Move [1-%2d]: ", game.path);
            scanf("%d", &player.move);
            if (1 <= player.move && player.move <= game.path)
            {
                temp = 1;
            }
            else
            {
                printf("  Out of Range!!!\n");
            }
        } while (temp == 0);

        if (player.his[player.move - 1] == '.')
        {
            printf("\n===============> Dope! You've been here before!\n");
        }
        else
        {
            game.max_MOVE--;
            if (game.bombs[player.move - 1] == 1 && game.treasure[player.move - 1] == 1)
            {
                player.live--;
                player.treasureFound++;
                player.his[player.move - 1] = '&';
                printf("\n===============> [&] !!! BOOOOOM !!! [&]\n===============> [&] $$$ Life Insurance Payout!!! [&]\n");
            }
            else if (game.bombs[player.move - 1] == 1)
            {
                player.live--;
                player.his[player.move - 1] = '!';
                printf("\n===============> [!] !!! BOOOOOM !!! [!]\n");
            }
            else if (game.treasure[player.move - 1] == 1)
            {
                player.treasureFound++;
                player.his[player.move - 1] = '$';
                printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n");
            }
            else
            {
                player.his[player.move - 1] = '.';
                printf("\n===============> [.] ...Nothing found here... [.]\n");
            }
        }
        printf("\n");

        if (player.live == 0)
        {
            printf("No more LIVES remaining!\n");
            storage = 1;
        }
        else if (game.max_MOVE == 0)
        {
            printf("No more MOVES remaining!\n");
            storage = 1;
        }
    } while (storage == 0);

    printf("\n");

    if (player.move != 0)
    {
        printf("  ");
        for (i = 0; i < player.move - 1; i++)
        {
            printf(" ");
        }
        printf("%c", player.symbol);
    }
    printf("\n  ");
    for (i = 0; i < game.path; i++)
    {
        printf("%c", player.his[i]);
    }
    printf("\n  ");
    for (i = 1; i <= game.path; i++)
    {
        if (i % 10 == 0)
        {
            printf("%d", (i / 10));
        }
        else
        {
            printf("|");
        }
    }
    printf("\n  ");
    for (i = 1; i <= game.path; i++)
    {
        if (i % 10 == 0)
        {
            printf("0");
        }
        else
        {
            if (i < 10)
            {
                printf("%d", i);
            }
            else
            {
                printf("%d", (i % 10));
            }
        }
    }
    printf("\n");
    printf("+---------------------------------------------------+\n");
    printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.live, player.treasureFound, game.max_MOVE);
    printf("+---------------------------------------------------+\n");
    printf("\n");
    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n\n");

    printf("You should play again and try to beat your score!\n");

    return 0;
}