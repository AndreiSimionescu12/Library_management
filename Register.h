#ifndef REGISTER_H_INCLUDED
#define REGISTER_H_INCLUDED
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Register
{
private:
    char nume_prenume[50];
    char password[30];
public:
    Register()
    {
        strcpy(this->nume_prenume,"Necunoscut");
        strcpy(this->password,"Necunoscuta");
    }

    Register(char *a, char *b)
    {
        strcpy(this->nume_prenume,a);
        strcpy(this->password,b);
    }

    friend ofstream& operator<<(ofstream&,Register&);
    friend istream& operator>>(istream&,Register&);
    void setare_nume_prenume(char c[50])
    {
        strcpy(this->nume_prenume,c);
    }

    void setare_password(char d[30])
    {
        strcpy(this->password,d);
    }

    char* get_nume_prenume()
    {
        return nume_prenume;
    }

    char* get_password()
    {
        return password;
    }

};

ofstream& operator<<(ofstream &afisare,Register &a)
{
    afisare.open("date.in",ios::app);
    if(afisare)
        afisare<<a.get_nume_prenume()<<","<<a.get_password()<<"\n";

    afisare.close();
    return afisare;
}

istream& operator>>(istream& citire,Register& b)
{
    cout<<"\nNume si prenume: ";
    fflush(stdin);
    citire.getline(b.nume_prenume,50);
    cout<<"Password: ";
    fflush(stdin);
    citire.getline(b.password,30);
    return citire;
}
#endif // REGISTER_H_INCLUDED
