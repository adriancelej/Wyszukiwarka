#include "funkcje.h"

dane *pierwszy;

int main(int argc, char* argv[])
{
    int i; //licznik argumentów funkcji
    FILE* fp;//wskaznik do pliku;

    pierwszy=malloc(sizeof(dane));  //Tworzenie pierwszego elementu listy
    pierwszy->nr_arg=1;
    strcpy(pierwszy->arg_napis,argv);
    pierwszy->next=NULL;

    spr_arg(argc);

    for(i=1;i<argc;++i)//wypelnianie listy argumentami
        dodaj_arg(pierwszy,i,argv[i]);

    wypisz_arg(pierwszy);
    if(spr_znak(pierwszy)==true)
    {
        fp=otworz_plik(pierwszy);
        szukaj_w_lini(fp,pierwszy);
    }
        else
        {
         szukaj_w_lini(stdin,pierwszy);
        }
    return 0;
}
