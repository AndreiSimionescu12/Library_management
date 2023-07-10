#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

class Biblioteca
{
private:
    char nume_carte[30];
    char nume_autor[30];
    char editura[30];
    int nr_pagini_carte;
public:
    Biblioteca();
    Biblioteca(char*,char*,char*,int);
    friend ostream& operator<<(ostream&,Biblioteca);
    friend istream& operator>>(istream&,Biblioteca&);
    char* get_numecarte();
    char* get_numeautor();
    char* get_editura();
    int get_numarpagini();
    void editare_nume_carte(char*);
    void editare_nume_autor(char*);
    void editare_editura(char*);
    void editare_numar_pagini(int);
};



#endif // BIBLIOTECA_H
