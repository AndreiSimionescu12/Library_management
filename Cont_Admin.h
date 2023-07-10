#ifndef CONT_ADMIN_H_INCLUDED
#define CONT_ADMIN_H_INCLUDED
#include <iostream>
#include <cstring>

using namespace std;

class Cont_Admin
{
private:
    char numeprenume[50];
    char parola[30];
public:
    Cont_Admin()
    {
        strcpy(this->numeprenume,"Necunoscut.");
        strcpy(this->parola,"Necunoscut.");
    }
    Cont_Admin(char n[50],char m[30])
    {
        strcpy(this->numeprenume,n);
        strcpy(this->parola,m);
    }
    char* get_numeprenume()
    {
        return numeprenume;
    }

    char* get_parola()
    {
        return parola;
    }

    void set_numeprenume(char *a)
    {
        strcpy(numeprenume,a);
    }

    void set_parola(char *b)
    {
        strcpy(parola,b);
    }
};


#endif // CONT_ADMIN_H_INCLUDED
