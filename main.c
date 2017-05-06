#include <stdio.h>
#include <stdlib.h>
#include "krowa.h"
#include <conio.h>

void rect();
void triangle();
void diamond();
void menu();



//Task author: Anna Fabijañska
//Program author: Jakub Czaja

//using table of function pointers to run different functions

void rect()
{
    int i, j;
    int height;
    read_variable("height", &height, "%d");
    int width;
    read_variable("width", &width, "%d");
    for(i = 0; i < height; ++i)
    {
        for(j = 0; j < width; ++j)
        {
            if((i == 0) || (i == height - 1) || (j == 0) || (j == width - 1))
            {
                printf("*");
            }
            else printf(" ");
        }
        printf("\n");
    }
}

void triangle()
{
    int i, j;
    int height;
    read_variable("height", &height, "%d");
    int a = 1;
    for(i = 0; i < height; ++i)
    {
        for(j = 0; j < a; ++j)
        {
            if((i == 0) || (i == height - 1) || (j == 0) || (j == a - 1))
            {
                printf("*");
            }
            else printf(" ");
        }
        ++a;
        printf("\n");
    }
}

void diamond()
{
    int i, j;
    int height;
    read_variable("height", &height, "%d");
    int width;
    read_variable("width", &width, "%d");
    for(i = 0; i < height; ++i)
    {
        for(j = 0; j < height - i - 1; ++j)
        {
            printf(" ");
        }
        for(j = 0; j < width; ++j)
        {
            if((i == 0) || (i == height - 1) || (j == 0) || (j == width - 1))
            {
                printf("*");
            }
            else printf(" ");
        }
        printf("\n");
    }
}

void menu()
{
    system("cls");
    printf(" 1: draw rectangle\n 2: draw triangle\n 3: draw diamond\n h: print this menu\n esc: exit program\n");
}
int main()
{
    menu();
    void (*foos[])() = {rect, triangle, diamond, menu};
    while(1)
    {
        char a = getch();
        if(a == 27)
            break;
        switch(a)
        {
        case 'h':
            foos[3]();
            break;
        default:
            if((a > '0') && (a < '4'))
                foos[a - '0' - 1]();
            else
                printf("wrong option\n");
            break;
        }
    }
    return 0;
}
