#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

#define SCREENLENGTH 112
#define SCREENBREADTH 42
//font size: 12x16

void gotoxy(short x, short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void textMiddleOf(char text[], int x1, int x2, int y)
{
    int len = strlen(text);
    int x = x1 + ((x2 - x1)/2) - (len/2);
    gotoxy(x,y);
    printf("%s",text);
}

void drawVerticalLineAt(int y1, int y2, int x)
{
    for(int y = y1; y <= y2; y++)
    {
        gotoxy(x,y);
        printf("|");
    }
}

void drawHorizontalLineAt(int x1, int x2, int y)
{
    for(int x = x1; x <= x2; x++)
    {
        gotoxy(x,y);
        printf("-");
    }
}

void wipeArea(int x1, int y1, int x2, int y2)
{
    for(int x = x1; x <= x2; x++)
    {
        for(int y = y1; y <= y2; y++)
        {
            gotoxy(x,y);
            printf(" ");
        }
    }
}

void wipeLine(int y)
{
    for(int x = 2; x <= (SCREENLENGTH - 1); x++)
    {
        gotoxy(x,y);
        printf(" ");
    }
}

void wipeScreen()
{
    for(int x = 0; x <= SCREENLENGTH; x++)
    {
        for(int y = 0; y <= SCREENBREADTH; y++)
        {
            gotoxy(x,y);
            printf(" ");
        }
    }
}

void textMiddle(char text[], int y)
{
    int len = strlen(text);
    int x = (SCREENLENGTH/2) - (len/2);

    gotoxy(x,y);
    printf("%s",text);
}

void drawVerticalLine(int x)
{
    for(int y = 2; y <= (SCREENBREADTH-1); y++)
    {
        gotoxy(x,y);
        printf("|");
    }
}

void drawHorizontalLine(int y)
{
    for(int x = 2; x <= (SCREENLENGTH-1); x++)
    {
        gotoxy(x,y);
        printf("-");
    }
}

void drawBorder()
{
    for(int x = 1; x <= SCREENLENGTH; x++)
    {
        gotoxy(x,1);
        printf("-");
        gotoxy(x,SCREENBREADTH);
        printf("-");
    }
    for(int y = 1; y <= SCREENBREADTH; y++)
    {
        gotoxy(1,y);
        printf("|");
        gotoxy(SCREENLENGTH,y);
        printf("|");
    }
}


