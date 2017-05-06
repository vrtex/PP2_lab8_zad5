#ifndef KROWA_H_INCLUDED
#define KROWA_H_INCLUDED

int irandom(int, int);

double drandom(double, double);

float frandom(float, float);

void read_variable(char *, int *, char *);

void merge1(int *, int, int ,int);
////scalanie 1 z dwoma posortowanymi ciagami


int * merge2(int *, int, int *, int);
//scalanie dwoch tablic
//1,2: tablica 1 i jej rozmiar,
//3,4: tablica 2 i jej rozmiar

void mergesort(int [], int , int);

#endif // KROWA_H_INCLUDED
