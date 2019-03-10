#include "funkcje.h"

void dodaj_arg(dane *lista,int nr_arg,char* argv)
{
    dane *wsk,*nowy;
    wsk=lista;

    while(wsk->next != NULL)
        wsk=wsk->next;

    nowy=malloc(sizeof(dane));
    if(nowy==NULL)
        exit(EXIT_FAILURE);

    nowy->nr_arg=nr_arg;
    strcpy(nowy->arg_napis,argv);
    nowy->next=NULL;
    wsk->next=nowy;
}

void wypisz_arg(dane *lista)
{
    dane *wsk;
    wsk=lista;

    while(wsk->next!=NULL)
        {
            if(wsk->nr_arg==1)//pomijam pierwszy element, który jest nazwa programu
                {
                puts("Witaj!!!\n");
                wsk=wsk->next;
                }
        printf("Numer argumentu:%d  Tresc argumentu: %s\n",wsk->nr_arg,wsk->arg_napis);
        wsk=wsk->next;
        }
    printf("Numer argumentu:%d  Tresc argumentu: %s\n\nWyniki:\n",wsk->nr_arg,wsk->arg_napis);
}

void spr_arg(int argc)
{
    if(argc<2)
        {
            printf("Nie podano argumentow!!!");
            exit(EXIT_FAILURE);
        }
}

int* otworz_plik(dane* lista)
{
    dane* wsk;
    FILE* pom=NULL;//zmienna pomocnicza
    char buf[20];

    while(wsk->next!=NULL)
        wsk=wsk->next;
    strcpy(buf,wsk->arg_napis);

    if((buf[0]>=65&&buf[0]<=90)||(buf[0]>=97&&buf[0]<=122))
    {
        FILE* fp=fopen(buf,"r");
        pom=fp;
    }
        else
        {
            puts("Podano niewlasciwie nazwe pliku.\nPodaj nazwe pliku jako ostatni argument.");
            exit(EXIT_FAILURE);
        }

    if(pom==NULL)
    {
        puts("Podany plik nie istnieje lub nastapil blad otwracia pliku.\nPodaj nazwe pliku jako ostatni argument.");
        exit(EXIT_FAILURE);
    }
    return pom;
}

void szukaj_w_lini(FILE* fp, dane* lista)
{
    char buf_line[MAX_LINE]={0};//przechowuje jeden wiersz
    char buf_word[MAX_WORD]={0};//przechowuje slowo
    int str_length;//dlugosc napisu buf_line[MAX_LINE]
    int i=0;
    int p=0;
    int a;
    bool logic=false;
    bool negative=false;
    dane* wsk;
    wsk=lista->next;


    while((fgets(buf_line,MAX_LINE-1,fp))!=NULL)
    {
        str_length=strlen(buf_line);
        while(p!=str_length-1)
          {
            spr_spacje(&p,buf_line);
            while(buf_line[p]!=32&&buf_line[p]!='\n'&&spr_spacje(&p,buf_line)!=true)
                {
                buf_word[i]=buf_line[p];
                ++i;++p;
                }

            wsk=lista->next;
            while(wsk!=NULL)
                {
                    if(wsk->znak==true)
                    {
                        if(!strcmp(&(wsk->arg_napis[1]),buf_word))
                        logic=true;
                    }
                    if(wsk->znak==false)
                        {
                            if(!strcmp(&(wsk->arg_napis[1]),buf_word))
                            {
                                logic=false;
                                negative=true;
                                break;
                            }
                        }
                    wsk=wsk->next;
                }
            for(a=0;a<=i;++a)//zerowanie tablicy
            buf_word[a]=0;

            i=0;

            if(negative==true)
                break;
            }

            if(logic==true)
                {
                    printf("\n%sLiczba znakow: %d\n",buf_line,str_length-1);
                }
            logic=false;
            negative=false;
            p=0;
    }

    fclose(fp);
}

bool spr_znak(dane* lista)
{
    dane* wsk=lista->next;
    bool wsk_x=false;

    while(wsk->next!=NULL)
    {
        if(wsk->arg_napis[0]=='+')
            {
                wsk->znak=true;
                wsk_x=true;
            }
        if(wsk->arg_napis[0]=='-')
            {
                wsk->znak=false;
                wsk_x=true;
            }
        if(wsk_x==false)
            {
                puts("Wprowadzony argumenty nie jest poprzedzony znakiem '+' lub '-'\nWprowadz  poprawnie argumenty\n");
                exit(EXIT_FAILURE);
            }
        wsk=wsk->next;
        wsk_x=false;
    }
    if(wsk->arg_napis[0]=='+'||wsk->arg_napis[0]=='-')
        {
            if(wsk->arg_napis[0]=='+')
                wsk->znak=true;
            if(wsk->arg_napis[0]=='-')
                wsk->znak=false;
            puts("Czytam ze standardowego wejscia. Wprowadz linie tekstu i zatwierdz enterem.");
            return false;
        }
        else
        {
            return true;
        }
}

bool spr_spacje(int* p,char* tab)
{

    if(tab[*p]>=32&&tab[*p]<=47||tab[*p]>=58&&tab[*p]<=64||tab[*p]>=91&&tab[*p]<=96||tab[*p]>=123)
        {
            ++(*p);
            return true;
        }
    return false;
}
