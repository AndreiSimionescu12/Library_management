#include <iostream>
#include "Biblioteca.h"
#include "Meniu.h"
#include <stdio.h>
#include <stdlib.h>
#include "Meniu_login_register.h"
#include "Register.h"
#include <fstream>
#include "Cont_Admin.h"

using namespace std;

int nr;
int nrelem;


int main()
{


    Cont_Admin cont;

    /**ofstream afisbazadatetitlu("bazadatebiblioteca.in");   ///este declarata pentru a afisa in fiser un titlu

    afisbazadatetitlu<<"\n-------------------------Carti biblioteca----------------------\n\n\n\n";
    afisbazadatetitlu.close();
    **/
    char namefisier[50];   ///pastreaza numele si prenumele de cont al administratorului
    char passwordfisier[40]; /// pastreaza parola administratorului
    bool ok_log_register=true;
    int op_log_register;

    bool validare_cont_admin=false;

    ifstream citirecontadmin("cont.administrator");

    citirecontadmin.getline(namefisier,50);
    citirecontadmin.getline(passwordfisier,40);

    cont.set_numeprenume(namefisier);
    cont.set_parola(passwordfisier);



    ///creare cont si logare
    while(ok_log_register)
    {
        Register r("Necunoscut","Necunoscut");
        Meniu_Register_Login::Inregistrare_Logare();
        cin>>op_log_register;
        if(op_log_register==1)
        {
            cin>>r;
            ofstream afis;
            afis<<r;
            cout<<"\nContul a fost salvat in baza de date 'date.in' ";
        }
        else if(op_log_register==2)
        {
            char liniefisier[100];
            bool cont_gasit=false;
            char a[100];
            char b[50];
            char c[30];
            cout<<"\n-------------------------Va puteti loga cu orice cont creat si salvat in baza de date 'date.in'------------------------";
            cout<<"\n\nNume si prenume: ";
            fflush(stdin);
            cin.getline(b,50);
            cout<<"\Password: ";
            fflush(stdin);
            cin.getline(c,30);
            strcpy(a,b);
            strcat(a,",");
            strcat(a,c);
            ifstream citire("date.in");
            while(citire.getline(liniefisier,100))
            {
                if(strcmp(a,liniefisier)==0)
                {
                    cout<<"\nLogarea s-a facut cu succes.";
                    ok_log_register=false;
                    cont_gasit=true;
                    break;
                }
            }
            if(!cont_gasit)
                cout<<"Contul introdus pentru logare nu a fost gasit in baza de date 'date.in' ";
            citire.close();
        }
        else
        {
            cout<<"\n\nOperatia introdusa este inexistenta.";
        }
        cout<<"\n\nPress any key to continue....";
        fflush(stdin);
        getchar();
        system("cls");
    }


    Biblioteca a[100];   ///declarare vector de biblioteci
    int operatieeditare;
    bool ok = true;
    bool gasire_pentru_stergere=false;
    bool gasire_pentru_editare=false;
    bool validoperatieeditare=true;
    system("cls");
    while (ok)
    {
        Meniu::Afisare();
        int operatie;
        cin >> operatie;
        switch (operatie)
        {
        case 1:
            if(nr!=0)
            {
                cin>>a[nr];
                nr++;
            }
            if(nr==0)
            {
                cin>>a[nr];
                nr++;
            }

            cout<<"\nCartea a fost adaugata in biblioteca.";
            nrelem=nr;
            cout<<"\n\nPress any key to continue....";
            fflush(stdin);
            getchar();
            system("cls");
            break;
        case 2:
            char nume[20];
            cout<<"\nTrebuie sa introduceti numele cartii pe care doriti sa o editati: ";
            fflush(stdin);
            cin.getline(nume,20);
            for(int i=0;i<nrelem;i++)
            {
                if(strcmp(nume,a[i].get_numecarte())==0)
                {
                    gasire_pentru_editare=true;
                    cout<<"\nCartea cautata a fost gasita.";
                    cout<<"\n-----------Alegeti o optiune pe care doriti sa o editati la aceasta carte-------------";
                    cout<<"\n\n1.Nume carte.";
                    cout<<"\n2.Nume autor.";
                    cout<<"\n3.Nume editura.";
                    cout<<"\n4.Numar pagini carte.";
                    cout<<"\nIntroduceti operatia dorita: ";
                    cin>>operatieeditare;


                    if(operatieeditare==1)
                    {

                        char b[30];
                        fflush(stdin);
                        cout<<"\nIntroduceti modificarea: ";
                        cin.getline(b,30);
                        a[i].editare_nume_carte(b);
                        cout<<"\n------------Cartea a fost actualizata----------------";
                        cout<<"\nPress any key to continue...";
                        getchar();
                        system("cls");
                    }
                    else if(operatieeditare==2)
                    {
                        char c[30];
                        fflush(stdin);
                        cout<<"\nIntroduceti modificarea: ";
                        cin.getline(c,30);
                        a[i].editare_nume_autor(c);
                        cout<<"\n------------Cartea a fost actualizata----------------";
                        cout<<"\nPress any key to continue...";
                        getchar();
                        system("cls");
                    }
                    else if(operatieeditare==3)
                    {
                        char d[30];
                        fflush(stdin);
                        cout<<"\nIntroduceti modificarea: ";
                        cin.getline(d,30);
                        a[i].editare_editura(d);
                        cout<<"\n------------Cartea a fost actualizata----------------";
                        cout<<"\nPress any key to continue...";
                        getchar();
                        system("cls");
                    }
                    else if(operatieeditare==4)
                    {
                        int n;
                        fflush(stdin);
                        cout<<"\nIntroduceti modificarea: ";
                        cin>>n;
                        a[i].editare_numar_pagini(n);
                        cout<<"\nPress any key to continue...";
                        getchar();
                        system("cls");
                    }
                    else
                    {
                        cout<<"\nOperatia nu exista.";
                        cout<<"\nPress any key to continue...";
                        fflush(stdin);
                        getchar();
                        system("cls");
                    }
                }
            }
            if(!gasire_pentru_editare)
                cout<<"Cartea cautata pentru editare nu a fost gasita.";


            break;
        case 3:
            char sir[30];
            int nr;

            cout<<"\nIntroduceti numele cartii pe care doriti sa o stergeti: ";
            fflush(stdin);
            cin.getline(sir,30);
            for(int i=0;i<nrelem;i++)
            {
                if(strcmp(sir,a[i].get_numecarte())==0)
                {
                    cout<<"\nCartea a fost gasita.";
                    gasire_pentru_stergere=true;
                    cout<<"\n---------------Date despre carte---------------";
                    cout<<"\n\n";
                    cout<<a[i];
                    nr=i;
                    cout<<"\n\nCartea a fost stearsa.";
                    break;
                }
            }
            if(!gasire_pentru_stergere)
                cout<<"\nCartea cautata pentru stergere nu a fost gasita dupa nume";
            else
            {
                for(int i=nr;i<nrelem-1;i++)
                {
                    a[i]=a[i+1];
                }
                nrelem--;
                nr--;
            }
            cout<<"\nPress any key to continue....";
            getchar();
            system("cls");
            break;
        case 4:
            cout<<"\n\n";
            for(int i=0;i<nrelem;i++)
            {
                cout<<a[i]<<"\n";
            }
            cout<<"\nPress any key to continue....";
            fflush(stdin);
            getchar();
            system("cls");
            break;
        case 5:
            char name1[50];
            char password1[40];
            cout<<"\n\n\tTrebuie sa va conectati cu contul de administrator pentru a efectua aceasta operatie.";
            cout<<"\n\n---------LOGN IN----------";
            cout<<"\n\nNume si prenume: ";
            fflush(stdin);
            cin.getline(name1,50);
            cout<<"Parola: ";
            fflush(stdin);
            cin.getline(password1,40);

            if(strcmp(name1,cont.get_numeprenume())==0 && strcmp(password1,cont.get_parola())==0)
            {
                cout<<"\nLogare cu succes";
                cout<<"\n\nCartile introduse au fost salvate in baza de date 'bazadatebiblioteca'";
                validare_cont_admin=true;
            }
            else
            {
                cout<<"\nLogarea a fost facuta fara succes.\n";

            }

            if(validare_cont_admin)
            {
                fstream afisare_in_baza_de_date("bazadatebiblioteca.in",ios::app);   ///ddeclarare obiect de tip fstream pentru a adauga in fiser informatii despre obiecte
                for(int i=0;i<nrelem;i++)
                    afisare_in_baza_de_date<<"\nNume carte: "<<a[i].get_numecarte()<<", Nume autor: "<<a[i].get_numeautor()<<", Nume editura: "<<a[i].get_editura()<<", Numar pagini: "<<a[i].get_numarpagini()<<"\n";

                afisare_in_baza_de_date.close();
            }
            cout<<"\n\nPress any key to continue...";
            fflush(stdin);
            getchar();
            system("cls");
            break;
        case 6:
            system("cls");
            ok = false;
            break;
        default:
            cout<<"\nOperatia selectata nu exista.";
            cout<<"\n\nPress any key to continue...";
            fflush(stdin);
            getchar();
            system("cls");
        }
    }

    citirecontadmin.close();

    return 0;
}
