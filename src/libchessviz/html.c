#include "chess.h"

void addStartHTML(FILE* file)
{
    char str[]
            = "<!DOCTYPE html>\n\
<html>\n\
<head>\n\
  <meta charset=\"utf-8\">\n\
  <title>chessviz</title>\n\
  <style type=\"text/css\">\n\
    table.chessboard {\n\
      border: 5px solid #333;\n\
      border-collapse: collapse;\n\
      height: 320px;\n\
      margin: 20px;\n\
      width: 320px;\n\
    }\n\
    table.chessboard caption {\n\
      text-align: left;\n\
    }\n\
    table.chessboard td {\n\
      background-color: #fff;\n\
      font-size: 25px;\n\
      height: 40px;\n\
      text-align: center;\n\
      vertical-align: middle;\n\
      width: 40px;\n\
    }\n\
    table.chessboard tr:nth-child(odd) td:nth-child(even),\n\
    table.chessboard tr:nth-child(even) td:nth-child(odd) {\n\
      background-color: #999;\n\
    }\n\
    table.chessboard .K:before   { content: \"\\2654\"; }\n\
    table.chessboard .Q:before  { content: \"\\2655\"; }\n\
    table.chessboard .R:before   { content: \"\\2656\"; }\n\
    table.chessboard .B:before { content: \"\\2657\"; }\n\
    table.chessboard .N:before { content: \"\\2658\"; }\n\
    table.chessboard .P:before   { content: \"\\2659\"; }\n\
    table.chessboard .k:before   { content: \"\\265A\"; }\n\
    table.chessboard .q:before  { content: \"\\265B\"; }\n\
    table.chessboard .r:before   { content: \"\\265C\"; }\n\
    table.chessboard .b:before { content: \"\\265D\"; }\n\
    table.chessboard .n:before { content: \"\\265E\"; }\n\
    table.chessboard .p:before   { content: \"\\265F\"; }\n\
  </style>\n\
</head>\n\
<body>\n";
    fputs(str, file);
}

void addEndHTML(FILE* file)
{
    char str[] = "\t</body>\n</html>";
    fputs(str, file);
}

void addChessHTML(FILE* file, char chess[8][8], char* move)
{
    fputs("\t<table class=\"chessboard\">\n", file);
    fprintf(file, "\t\t<caption> %s </caption>\n", move);

    for (int i = 0; i < 8; ++i) {
        fputs("\t\t\t<tr>\n", file);
        for (int j = 0; j < 8; ++j) {
            fputs("\t\t\t\t<td>", file);
            if (chess[i][j] != ' ') {
                fprintf(file, "<span class=\"%c\"></span>", chess[i][j]);
            }
            fputs("\t\t\t\t</td>\n", file);
        }
        fputs("\t\t\t</tr>\n", file);
    }
    fputs("\t</table>\n", file);
}
