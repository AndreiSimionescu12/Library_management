#ifndef MENIU_H_INCLUDED
#define MENIU_H_INCLUDED

#include <iostream>
#include <stdio.h>


using namespace std;

class Meniu
{
public:

	static void Afisare()
	{
		cout << "\n\n\t\t\t\t\tBIBLIOTECA";
		cout<<"\n\n\nOperatii angajati";
		cout << "\n\t1.Adaugare carti in biblioteca.";
		cout << "\n\t2.Editare carti introduse de catre angajat";
		cout << "\n\t3.Stergere carti introduse de catre angajat";
		cout << "\n\t4.Afisare carti introduse de catre angajat";
		cout<<"\nOperatii administrator";
		cout<<"\n\t5.Salvarea in baza de date a informatiilor introduse de catre angajati.";
		cout<<"\nAlte operatii";
		cout<<"\n\t6.Iesire.";
		cout << "\n\n\nIntroduceti operatia dorita: ";
	}
};

#endif // MENIU_H_INCLUDED
