// Created by Sanket Koirala on 3/25/23. ID: 1002068130


#include <stdio.h>
#include "DrawTool.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define PHRASELEN 20
int main(void)
{
    char map[MAXMAPSIZE][MAXMAPSIZE] ={};
    int MyMapSize;
    int *MyMapSizePtr = &MyMapSize;

    InitializeMap(map, MyMapSizePtr);
    PrintInstructions();
    PrintMap(map, MyMapSize);


    char UserInput[PHRASELEN];
    char Delimeters[] = "(),";
    char *Token = NULL;
    char DoThis[PHRASELEN] = {};
    char symbol[PHRASELEN];
    char mark;
    int x_index;
    int y_index;
    int length;
    char DrawCommand;

    printf("Enter draw command (enter Q to quit) q ");
    fgets(UserInput, PHRASELEN-1, stdin);
    UserInput[strlen(UserInput)-1]='\0';

    Token = strtok(UserInput, Delimeters);
    strcpy(DoThis, Token);
    DrawCommand = toupper(DoThis[0]);

    if ((((DrawCommand != 'H' && DrawCommand != 'h') && (DrawCommand != 'V' && DrawCommand != 'v'))
        && (DrawCommand != 'Q' && DrawCommand != 'q')) && (DrawCommand != 'P' && DrawCommand != 'p'))
    {
        printf("That draw command is unknown.");
    }

    if (DrawCommand == 'P')
    {
            map[x_index][y_index] = mark;

    }


while  (((DrawCommand== 'H' || DrawCommand=='V') ||  (DrawCommand== 'P')) && (DrawCommand!='Q'))
{

    Token = strtok(NULL, Delimeters);
    x_index = atoi(Token);

    Token = strtok(NULL, Delimeters);
    y_index = atoi(Token);

    Token = strtok(NULL, Delimeters);
    length = atoi(Token);

    Token = strtok(NULL, Delimeters);
    strcpy(symbol, Token);
//    if (*Token=='\\')
//    {
//     mark ='X';
//    }
//    else
    mark = symbol[0];

    if ((x_index>=MyMapSize || y_index>=MyMapSize) || (((x_index+length-1)>MyMapSize) || ((y_index+length-1)>MyMapSize)))
    {
        printf("That draw command is out of range.");
    }


    if (DrawCommand == 'P')
    {
        map[x_index][y_index] = mark;
    }
    else
        DrawLine(map, x_index, y_index, DrawCommand, length, mark);

    PrintMap(map, MyMapSize);

    printf("Enter draw command (enter Q to quit) q ");
    fgets(UserInput, PHRASELEN-1, stdin);
    UserInput[strlen(UserInput)-1]='\0';

    Token = strtok(UserInput, Delimeters);
    strcpy(DoThis, Token);
    DrawCommand = toupper(DoThis[0]);
    if ((((DrawCommand != 'H' && DrawCommand != 'h') && (DrawCommand != 'V' && DrawCommand != 'v'))
         && (DrawCommand != 'Q' && DrawCommand != 'q')) && (DrawCommand != 'P' && DrawCommand != 'p'))
    {
        printf("That draw command is unknown.");
    }

}

    return 0;
}

