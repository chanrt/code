#define LENGTH 110
#define BREADTH 40

#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<time.h>

void drawHorizontal(int y, int x1 = 2, int x2 = LENGTH - 1);
void drawVertical(int x, int y1 = 2, int y2 = BREADTH - 1);
void drawBox(int x1 = 1,int y1 = 1, int x2 = LENGTH, int y2 = BREADTH);

void textMiddle(char *s, int y, int x1 = 1, int x2 = LENGTH);
void textLeft(char *s, int y, int left = 1);
void textRight(char *s, int y, int right = LENGTH);

void textSmooth(char *s, int x, int y, float f);

void wipeArea(int x1 = 1, int y1 = 1, int x2 = LENGTH, int y2 = BREADTH);
void wipeLine(int y, int x1 = 2, int x2 = LENGTH - 1);

void graphicDelay(float f);
void delay(float milli_seconds = 1.0);

void circleLoad(int x, int y, int t, float d);
void sidewayLoad(int x, int y, int t, float d);

void gotoxy(short x, short y)
{
    COORD p = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}

void drawLayout()
{
    drawBox();
    drawHorizontal(3);
    gotoxy(45,2);
    printf("Linked list simulator");

    drawHorizontal(29);
    gotoxy(3,30);
    printf("Console:");
}

void delay(float n_seconds)
{
    int milli = 1000 * n_seconds;

    clock_t start = clock();

    while(clock() < start + milli);
}

void drawHorizontal(int y, int x1, int x2)
{
    for(int i = x1; i <= x2; i++)
    {
        gotoxy(i,y);
        printf("-");
    }
}

void drawVertical(int x, int y1, int y2)
{
    for(int i = y1; i <= y2; i++)
    {
        gotoxy(x,i);
        printf("|");
    }
}

void drawBox(int x1, int y1, int x2, int y2)
{
    drawHorizontal(y1,x1+1,x2-1);
    drawHorizontal(y2,x1+1,x2-1);
    drawVertical(x1,y1+1,y2-1);
    drawVertical(x2,y1+1,y2-1);

    gotoxy(x1,y1);
    printf("+");
    gotoxy(x2,y1);
    printf("+");
    gotoxy(x1,y2);
    printf("+");
    gotoxy(x2,y2);
    printf("+");
}

void textMiddle(char s[], int y, int x1, int x2)
{
    int len = strlen(s);
    int mid = (x2 - x1) / 2;

    int x;
    x = x1 + mid - (len / 2);

    gotoxy(x,y);
    printf("%s",s);
}

void textLeft(char s[], int y, int left)
{
    gotoxy(left+1,y);
    printf("%s",s);
}

void textRight(char s[], int y, int right)
{
    int len = strlen(s);
    int x = LENGTH - len - right;

    gotoxy(x-1,y);
    printf("%s",s);
}

int findFit(char *s, int str_index, int line_length, int string_length)
{
    int max = 0;

    for(int i = str_index; i < string_length; i++)
    {
        if(s[i] == ' ' && (i - str_index) < line_length) max = i;
        if((i - str_index) >= line_length) return max;
    }
}

void textFit(char s[], int y, int x1, int x2)
{
    int y_pos = y;
    int len = strlen(s);
    int prev_str_index = 0;
    int next_str_index ;
    int line_index = 1;
    int line_length = x2 - x1;

    gotoxy(x1+1,y_pos);
    for(;prev_str_index < (len - 1);)
    {
        
        next_str_index = findFit(s, prev_str_index, line_length, len);

        for(int j = prev_str_index; j <= next_str_index; j++)
        {
            printf("%c",s[j]);
        }
        
        prev_str_index = next_str_index;
        y_pos++;
        gotoxy(x1,y_pos);
    }
}

void textSmooth(char *s, int x, int y, float d)
{
    gotoxy(x,y);
    for(int i = 0; s[i] != '\0'; i++) 
    {
        printf("%c",s[i]);
        graphicDelay(d);
    }
}

void wipeArea(int x1, int y1, int x2, int y2)
{
    if(x1 == 1 && y1 == 1 && x2 == LENGTH && y2 == BREADTH) system("cLs");

    else
    {
        for(int i = x1; i <= x2; i++)
        {
            for(int j = y1; j <= y2; j++)
            {
                gotoxy(i,j);
                printf(" ");
            }
        }
    }
}

void wipeLine(int y, int x1, int x2)
{
    for(int i = x1; i <= x2; i++)
    {
        gotoxy(i,y);
        printf(" ");
    }
}

void graphicDelay(float n_seconds)
{
    int milli = 1000 * n_seconds;

    clock_t start = clock();

    while(clock() < start + milli);
}

void sidewayLoad(int x, int y, int t, float d)
{
    for(int i = 0; i < t; i++)
    {
        gotoxy(x,y);
        printf("/");
        graphicDelay(d);
        gotoxy(x,y);
        printf("\\");
        graphicDelay(d);
    }
}

void circleLoad(int x, int y, int t, float d)
{
    for(int i = 0; i < t; i++)
    {
        gotoxy(x,y);
        printf("/");
        graphicDelay(d);
        gotoxy(x,y);
        printf("-");
        graphicDelay(d);
        gotoxy(x,y);
        printf("\\");
        graphicDelay(d);
        gotoxy(x,y);
        printf("|");
        graphicDelay(d);
        gotoxy(x,y);
        printf("/");
        graphicDelay(d);
        gotoxy(x,y);
        printf("-");
        graphicDelay(d);
        gotoxy(x,y);
        printf("\\");
        graphicDelay(d);
    }
}