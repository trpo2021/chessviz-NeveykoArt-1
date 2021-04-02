#include "libchessviz/chess.h"

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("./exe file_move\n");
        return -1;
    }

    char chess[8][8];
    createChess(chess);

    FILE* fileHTML = fopen("chess.html", "w+");
    addStartHTML(fileHTML);
    addChessHTML(fileHTML, chess, "");

    FILE* fileMoves = fopen(argv[1], "r");

    printf("Start chess table:\n");
    printChess(chess);

    int n = 30;
    char moves[n];
    bool flag_cmate = false;

    while (fgets(moves, n, fileMoves) != NULL)
    {
        char * first_word = strtok(moves, " ");

        if(!checkNumberMove(first_word))
        {
            printf("Error first_word\n");
            return -1;
        }

        enum BlackWhite color = White;

        for(int i = 0; i < 2; i++)
        {
            char * move_string = strtok(NULL, " ");

            motion the_motion = initMotion();
            bool res = checkMove(move_string, &the_motion, color);

            if(res == false)
            {
                printf("Error move_string _%s_\n", move_string);
                return -1;
            }

            printf("%s\n", move_string);
            if (switchMove(the_motion, chess))
            {
                addChessHTML(fileHTML, chess, move_string);
                printChess(chess);
            }
            else
            {
                printf("Error switchMove White\n");
                return -1;
            }

            if (the_motion.flag_cmate == true) {
                //конец партии
                //printf("White win!\n");
                flag_cmate = true;
                break;
            }

            color = Black;
        }

        if(flag_cmate)
        {
            break;
        }
    }
    printf("\n\n\t\tThe end\n");


    addEndHTML(fileHTML);
    fclose(fileHTML);
    fclose(fileMoves);

    return 0;
}
