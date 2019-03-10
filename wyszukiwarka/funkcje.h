#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_LINE 200//maksymalna dlugosc wiersza
#define MAX_WORD 20//maksymalna dlugosc slowa

//plik nag³ówkowy, zawiera funkcje i typy wykorzystywane w programie

typedef struct element //przechowuje argumenty i ich liczbê
{
    int nr_arg;
    char arg_napis[20];
    bool znak;
    struct element *next;
}dane;

void dodaj_arg(dane *lista,int nr_arg,char* argv); // dodaje argument do listy

void wypisz_arg(dane *lista);//wypisuje argumenty

void spr_arg(int argc);//sprawdza czy podano argumenty

int* otworz_plik(dane *lista);//otwiera plik do przeszukania i zwraca wskaznik do niego

void szukaj_w_lini(FILE* fp,dane *lista);//pobiera linie tekstu z pliku i porownuje ciagi znakowe

bool spr_znak(dane *lista);//sprawdza znak argumentu

bool spr_spacje(int* p,char* tab);//sprawdza czy znak nie jest spacjom, przecinkiem itp.
