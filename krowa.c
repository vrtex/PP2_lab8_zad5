#include <stdlib.h>
#include <stdio.h>
#include <time.h>




void merge1(int *tab, int poczatek, int srodek, int koniec)
{
    int i, j, a;
    int t[koniec - poczatek + 1];
    for(i = poczatek; i <= koniec; ++i)
    {
        t[i - poczatek] = tab[i];
    }
    a = poczatek;
    i = 0;
    j = srodek + 1 - poczatek;
    while((i <= srodek - poczatek) && (j <= koniec - poczatek))
    {
        if(t[i] <= t[j])
        {
            tab[a++] = t[i++];
        }
        else
        {
            tab[a++] = t[j++];
        }
    }
    while(i <= srodek - poczatek)
    {
        tab[a++] = t[i++];
    }
    while(j <= koniec - poczatek)
    {
        tab[a++] = t[j++];
    }
}


int * merge2(int *tab1, int l1, int *tab2, int l2)
{
    int *tab3 = calloc(l1 + l2, sizeof(int));
    int j1 = 0, j2 = 0, j3 = 0;
    do
    {
        if((*(tab1 + j1)) < (*(tab2 + j2)))
        {
            *(tab3 + j3) = *(tab1 + j1);
            ++j1;
            ++j3;
        }
        else
        {
            *(tab3 + j3) = *(tab2 + j2);
            ++j2;
            ++j3;
        }
    }while((j1 < l1) && (j2 < l2));
    if (j1 == 0)
    {
        do
        {
            *(tab3 + j3) = *(tab2 + j2);
            ++j2;
            ++j3;
        }while(j2 < l2);
    }
    else
    {
        do
        {
            *(tab3 + j3) = *(tab1 + j1);
            ++j1;
            ++j3;
        }while(j1 < l1);
    }
    return tab3;
}


void mergesort(int *tab, int poczatek, int koniec)
{
    int srodek;
    if (poczatek < koniec)
    {
        srodek = (poczatek + koniec)/2;

        mergesort(tab, poczatek, srodek);
        mergesort(tab, srodek + 1, koniec);

        merge1(tab, poczatek, srodek, koniec);
    }
}

void read_variable(char *prompt, int *p, char *format)
{
    int i;
    do
    {
        printf("enter %s ", prompt);
        i = scanf(format,p);
        fflush(stdin);
        if (i == 0)
            printf("invalid variable\n\n");
    }while(!i);
}

int irandom(int a, int b)
{
    //srand(time(0));
    return rand()%(b+1-a)+a;
}

double drandom(double a, double b)
{
    //srand(time(0));
    return a+(float)rand()/RAND_MAX*(b-a);
}

float frandom(float a, float b)
{
    //srand(time(0));
    return a+(float)rand()/RAND_MAX*(b-a);
}
