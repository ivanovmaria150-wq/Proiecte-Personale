#include <iostream>
#include <string>
using namespace std;

class Cartus
{
private:
	string producator;
	int nrTotalPagini;
public:
	//9
	int getNrTotalPagini() const { return nrTotalPagini; }
	void setNrTotalPagini(int nr) { nrTotalPagini = nr; }
	string getProducator() const { return producator; }
	void setProducator(string prod) { producator = prod; }
};

class Imprimanta
{
private:
	const int serialNumber = 0;
	char* producator;//la pointer trb alocare dinamica
	int nrPaginiPrintate;
	static string tipImprimanta;

//1
public:
	Cartus cartus;
	Imprimanta():serialNumber(1),nrPaginiPrintate(0)
	{
		producator = new char[1];
		producator[0] = '\0'; 
	}
//2
	Imprimanta(int serialNumber, char* producator, int nrPaginiPrintate):serialNumber(serialNumber),nrPaginiPrintate(nrPaginiPrintate)
	{
		if (producator != nullptr) {
			this->producator = new char[strlen(producator) + 1];
			strcpy_s(this->producator, strlen(producator) + 1, producator);
		}
		else
		{
			this->producator = new char[1];
			this->producator[0] = '\0';
		}
	}
	//3
	~Imprimanta()
	{
		delete[] producator;
	}
	//4
	Imprimanta(const Imprimanta& orice):serialNumber(orice.serialNumber),nrPaginiPrintate(orice.nrPaginiPrintate) 
	{
		producator = new char[strlen(orice.producator) + 1];
		strcpy_s(this->producator, strlen(orice.producator) + 1, orice.producator);
	}
	//5
	Imprimanta& operator=(const Imprimanta& other)
	{
		if (this != &other) {
			delete[] producator;

			producator = new char[strlen(other.producator) + 1];
			strcpy_s(producator, strlen(other.producator) + 1, other.producator);

			nrPaginiPrintate = other.nrPaginiPrintate;
			cartus = other.cartus;
		}
		return *this;
	}
	//11
	bool operator<(Imprimanta & t)const
	{
		return this->nrPaginiPrintate<t.nrPaginiPrintate;
	}
   //7
	static string getTipImprimanta()
	{
		return tipImprimanta;
	}

	static void setTipImprimanta(string tip)
	{
		tipImprimanta = tip;
	}
	//8
	static long getTotalPaginiPerProducator(Imprimanta* imprimante, int nrImprimante, char* producator)
	{
		long total = 0;
		for (int i = 0; i < nrImprimante; ++i) {
			if (strcmp(imprimante[i].producator, producator) == 0) {
				total += imprimante[i].nrPaginiPrintate;
			}
		}
		return total;
	}
    //9
	void setCartus(Cartus c)
	{
		cartus = c;
	}

	Cartus getCartus() const
	{
		return cartus;
	}
	//10
	int getNumarPaginiRamase() const
	{
		int ramase = cartus.getNrTotalPagini() - nrPaginiPrintate;
		return ramase > 0 ? ramase : 0;
	}

	void serialize(string fileName)
	{

	}

	void deserialize(string fileName)
	{

	}
	
//12	
friend ostream& operator<<(ostream& out,const Imprimanta & i)
{
	out << "Serial number: " << i.serialNumber << endl;
	out << "Producator: " << i.producator << endl;
	out << "Numar pagini printate: " << i.nrPaginiPrintate << endl;
	return out;
}

friend istream& operator>>(istream& in, Imprimanta)
{
	return in;
}
};
//6
string Imprimanta::tipImprimanta = "Cerneala";

//ATENTIE!!!
//Sunt punctate doar solutiile originale si individuale
//Orice incercare de frauda va duce la pierderea intregului punctaj de la seminar
//!!! Signatura anumitor operatori poate fi modificata pentru a permite functionarea lor conform specificatiilor

//1. Modificati constructorul implicit din clasa Imprimanta de mai sus
//acesta va initializa producatorul cu un sir de caractere vid ("")
//si numarul de pagini printate cu 0

//2. Modificati constructorul cu 3 parametri: serialNumber, producator, nrPaginiPrintate
//acesta va initializa cele 3 atribute cu valorile primite
//atributul constant nu va mai fi initializat la definire
//constructorul implicit va initializa acest atribut cu 1

//3. Adaugati un destructor in clasa pentru a dezaloca
//campul(urile) alocate dinamic

//4. Adaugati clasei un constructor de copiere astfel incat
//sa se realizeze o copie in profunzime (deep copy) a obiectelor
//se va realiza si copierea campului constant

//5. Modificati supraincarcarea pentru operator=
//aceasta va realiza o copie in profunzime (deep copy) a obiectelor
//operatorul accepta apeluri in cascada

//6. Initializati membrul static tipImprimanta cu valoarea "Cerneala"

//7. Modificati metodele de acces pentru campul static
//astfel incat acestea sa permita modificarea si obtinerea valorii acestui camp

//8. Modificati metoda getTotalPaginiPerProducator pentru a returna numarul total de pagini
//printate de toate imprimantele din vectorul de imprimante primit ca parametru
//care sunt produse de producatorul primit drept parametru
//De ex daca avem 3 imprimante: "Dell" - 120 de pagini, "HP" - 150 de pagini, "Dell" - 170 de pagini
//functia va returna 290 de pagini daca primeste ca parametru producatorul "Dell"
//si 150 de pagini daca primeste ca parametru producatorul "HP"
//pentru orice alt producator functia va returna 0

//9. Modelati o relatie de compunere intre clasa Cartus si clasa Imprimanta
//astfel incat sa reiasa faptul ca Imprimanta are (foloseste) un Cartus
//Modificati metoda setCartus astfel incat sa puteti schimba cartusul curent al imprimantei
//cu cel primit drept parametru si metoda getCartus pentru a returna cartusul curent

//10. Modificati metoda getNumarPaginiRamase astfel incat sa returneze numarul de pagini
//pe care imprimanta respectiva la mai poate printa avand in vedere ca stim 
//cate pagini se pot printa maxim cu cartusul curent si cate pagini au fost printate pana acum
//functia nu poate returna o valoare negativa, asa ca daca numarul curent de pagini il
//depaseste pe cel maxim, va returna 0

//11. Modificati supraincarcarea operatorului <
//acesta va compara numarul de pagini al celor doi operanzi de tip Imprimanta

//12. Modificati operatorul de scriere la consola pentru a afisa informatiile despre Imprimanta
//se pot folosi functii friend sau getteri
//afisarea va fi de forma:
//Serial number: serialNumber
//Producator: producator
//Numar pagini printate: nrPaginiPrintate

//13. Modificati operatorul de citire de la consola pentru a citi informatii despre Imprimanta
//se vor citi in ordine urmatoarele informatii (fiecare pe o linie noua)
//producator
//nrPaginiPrintate
//se pot folosi setteri sau functii friend
//operatorul trebuie sa poata citi siruri de caractere ce contin spatii

//14. Supraincarcati operatorii de scriere si citire din fisiere text
//operatorii functioneaza pe fisiere text deschise deja

//15. Modificati metodele serialize si deserialize pentru a scrie
//si a citi obiectul curent de clasa Imprimanta intr-un/dintr-un fisier binar
//se vor serializa toate campurile (ordinea nu conteaza)
//cu exceptia celor constante si statice
//numele fisierului este primit drept parametru
//metodele deschid si inchid fisierele specificate

int main()
{
	// 1
	Imprimanta i1;
	cout << "Test constructor implicit:\n" << i1 << endl;

	// 2
	char prod[] = "HP";
	Imprimanta i2(101, prod, 120);
	cout << "Test constructor cu parametri:\n" << i2 << endl;

	// 4
	Imprimanta i3 = i2;
	cout << "Test copy constructor (copie din i2):\n" << i3 << endl;

	// 5
	Imprimanta i4;
	i4 = i2;
	cout << "Test operator= (copie in i4 din i2):\n" << i4 << endl;

	// 6
	cout << "Tip imprimanta (initial): " << Imprimanta::getTipImprimanta() << endl;
	Imprimanta::setTipImprimanta("Laser");
	cout << "Tip imprimanta (modificat): " << Imprimanta::getTipImprimanta() << endl;

	// 8
	Imprimanta imprimante[] = {
		Imprimanta(1, (char*)"Dell", 100),
		Imprimanta(2, (char*)"HP", 150),
		Imprimanta(3, (char*)"Dell", 200)
	};
	cout << "Total pagini Dell: " << Imprimanta::getTotalPaginiPerProducator(imprimante, 3, (char*)"Dell") << endl;
	cout << "Total pagini HP: " << Imprimanta::getTotalPaginiPerProducator(imprimante, 3, (char*)"HP") << endl;

	// 9
	Cartus c;
	c.setProducator("Canon");
	c.setNrTotalPagini(300);
	i2.setCartus(c);
	cout << "Cartus setat pe i2. Pagini ramase: " << i2.getNumarPaginiRamase() << endl;

	// 10
	cout << "Pagini ramase i2 (dupa 120 printate din 300): " << i2.getNumarPaginiRamase() << endl;

	// 11
	cout << "i1 < i2 ? " << (i1 < i2 ? "DA" : "NU") << endl;

	// 12
	cout << "Afisare i2 cu operator << :\n" << i2 << endl;

	return 0;
	//Se vor testa in  main TOATE FUNCTIILE IMPLEMENTATE!!!!!
	//Veti incarca pe TEAMS o arhiva care va contine solutia MS-VisualStudio 2019!
}