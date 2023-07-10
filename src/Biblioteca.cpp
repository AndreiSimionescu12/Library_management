#include "Biblioteca.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>

using namespace std;



Biblioteca::Biblioteca():nr_pagini_carte(0)
{
    strcpy(nume_carte,"Necunoscuta");
    strcpy(nume_autor,"Necunoscut");
    strcpy(editura,"Necunoscuta");
}

Biblioteca::Biblioteca(char* a,char* b,char* c,int d):nr_pagini_carte(d)
{
    strcpy(nume_carte,a);
    strcpy(nume_autor,b);
    strcpy(editura,c);
}

ostream& operator<<(ostream& afisare,Biblioteca a)
{
    afisare<<"Nume carte: "<<a.nume_carte<<", Nume autor: "<<a.nume_autor<<", Nume editura: "<<a.editura<<", numar pagini: "<<a.nr_pagini_carte;

    return afisare;
}

istream& operator>>(istream& citire,Biblioteca& b)
{
    char a[30];
    cout<<"\nNume carte: ";
    fflush(stdin);
    cin.getline(b.nume_carte,30);
    cout<<"Nume autor: ";
    cin.getline(b.nume_autor,30);
    cout<<"Nume editura: ";
    cin.getline(b.editura,30);
    cout<<"Numar pagini carte: ";
    cin>>b.nr_pagini_carte;

    return citire;
}

char* Biblioteca::get_numecarte()
{
    return this->nume_carte;
}


void Biblioteca::editare_nume_carte(char *a)
{
    strcpy(this->nume_carte,a);
}

void Biblioteca::editare_nume_autor(char *b)
{
    strcpy(this->nume_autor,b);
}

void Biblioteca::editare_editura(char *c)
{
    strcpy(this->editura,c);
}

void Biblioteca::editare_numar_pagini(int d)
{
    nr_pagini_carte=d;
}

char* Biblioteca::get_numeautor()
{
    return this->nume_autor;
}

char* Biblioteca::get_editura()
{
    return this->editura;
}

int Biblioteca::get_numarpagini()
{
    return this->nr_pagini_carte;
}






