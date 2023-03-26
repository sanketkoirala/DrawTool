// Created by Sanket Koirala on 3/25/23.


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
    mark = symbol[0];


    DrawLine(map, x_index, y_index, DrawCommand, length, mark);
    PrintMap(map, MyMapSize);

    printf("Enter draw command (enter Q to quit) q ");
    fgets(UserInput, PHRASELEN-1, stdin);
    UserInput[strlen(UserInput)-1]='\0';

    Token = strtok(UserInput, Delimeters);
    strcpy(DoThis, Token);
    DrawCommand = toupper(DoThis[0]);

}

    return 0;
}

