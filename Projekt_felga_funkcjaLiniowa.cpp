#include<iostream>
#include<string>
#include<cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

class Shape
{
	string name;
public:
	Shape(string name_): name(name_)
	{
		cout << "Konstruktor klasy Shape" << endl;
	}
	~Shape()
	{
		cout << "Destruktor klasy Shape" << endl;
	}

	void setName(string name_)
	{
		cin >> name_;
		name = name_;
	}
	string getName()
	{
		return name;
	}

	double area()
	{
		return 0;
	}
};

class Rectangle : public Shape
{
	double width, height;
public:

	Rectangle(string name_, double width_, double height_): Shape(name_), width(width_), height(height_)
	{
		cout << "Konstruktor klasy Rectangle" << endl;
	}
	~Rectangle()
	{
		cout << "Destruktor klasy Rectangle" << endl;
	}
	double area()
	{
		return width * height;
	}
};

class Square : public Rectangle
{
public:
	Square(string name_, double width_): Rectangle(name_, width_, width_)
	{
		cout << "Konstruktor klasy Square" << endl;
	}
	~Square()
	{
		cout << "Destruktor klasy Square" << endl;
	}
	double area()
	{
		return Rectangle::area();
	}
};

class Circle : public Shape
{
public:
	double diameter;
		Circle(string name_, double diameter_) : Shape(name_), diameter(diameter_) {}
		double area()
		{
			return diameter * diameter*3.14;
		}
};

class Cylinder : public Circle
{
public:
	double height;
	Cylinder(string name_, double diameter_, double height_) : Circle(name_, diameter_), height(height_) {}
	double volume()
	{
		return height * area();
	}
};

class Funkcja {
    float x;
public:
    virtual float oblicz(float x) = 0;
    Funkcja() {
        cout << "Konstruktor klasy Funkcja" << endl;
 
    }
    ~Funkcja() {
        cout << "Destruktor klasy Funkcja" << endl;
    }
};
 
class FunkcjaLiniowa : public Funkcja{
    float a;
    float b;
public:
    FunkcjaLiniowa(float a, float b) {
        this->a = a;
        this->b = b;
        cout << "Konstruktor klasy FunkcjaLiniowa" << endl;
    }
 
    ~FunkcjaLiniowa() {
        cout << "Destruktor klasy FunkcjaLiniowa" << endl;
    }
 
    virtual float oblicz(float x) {
        return (a*x + b);
    }
 
};

double bisekcja(FunkcjaLiniowa* linia, double p, double k, double d)
{
	double yP = linia->oblicz(p);
	double yK = linia->oblicz(k);

	if(yP == yK || yP > 0 && yK > 0 || yP < 0 && yK < 0)
		return -13332.72; // zwróć obojętnie co

	double aux = 0;

	while(abs(p - k) > d)
	{
		aux = (p + k) / 2;

		if(abs(linia->oblicz(aux)) <= d) break;
		else if ((linia->oblicz(aux))*(linia->oblicz(p)) < 0) k = aux;
		else p = aux;
	}
	return (p + k) / 2;
}

class Felga {
	double waga;
	double szereokosc_felgi;
	double zewnetrzna_srednica_felgi;
public:
	Felga(double waga_, double _szerokosc_felgi, double _zewnetrzna_srednica_felgi):waga(waga_),szereokosc_felgi(_szerokosc_felgi),zewnetrzna_srednica_felgi(_zewnetrzna_srednica_felgi){}
	Felga() {};
	double get_waga() { return waga; }
	double get_szerokosc_felgi() { return szereokosc_felgi; }
	double get_zewnetrzna_srednica_felgi(){ return zewnetrzna_srednica_felgi; }
};

class Opona {
	double waga;
	double szereokosc_opony;
	double srednica_osadzenia_na_feldze;
public:
	Opona(double waga_, double _szerokosc_opony, double _srednica_osadzenia_na_feldze):waga(waga_),szereokosc_opony(_szerokosc_opony),srednica_osadzenia_na_feldze(_srednica_osadzenia_na_feldze){}
	Opona(){}
	double get_waga() { return waga; }
	double get_szerokosc_opony() { return szereokosc_opony; }
	double get_srednica_osadzenia_na_feldze() { return srednica_osadzenia_na_feldze; }
};


class Kolo {
	Felga* zamontowana_felga = new Felga;
	Opona* zamontowana_opona = new Opona;
	double waga;
public:
	Kolo():zamontowana_felga(nullptr),zamontowana_opona(nullptr),waga(0){}
	~Kolo() { delete zamontowana_felga;delete zamontowana_opona; }

	void zamontuj_felge(Felga *nowa_felga) {
		zamontowana_felga = nowa_felga;
		waga += nowa_felga->get_waga();
		delete nowa_felga;
	}

	void zamontuj_opone(Opona* nowa_opona) {
		zamontowana_opona = nowa_opona;
		waga += nowa_opona->get_waga();
		delete nowa_opona;
	}
	double get_waga() { return waga; }
};

void symulatorOpon(){
	Kolo* kolo = new Kolo;
	cout << "=========WSTAWIANIE Kol========="<<endl;
	cout << "Podaj parametry felgi: " << endl;
	cout << "Waga w kg: ";
	double waga;
	cin >> waga;
	cout << "Szerokosc felgi w mm: ";
	double szerokosc_felgi;
	cin >> szerokosc_felgi;
	cout << "Zewnetrzna srednice felgi w mm: ";
	double zewnetrzna_srednica_felgi;
	cin >> zewnetrzna_srednica_felgi;

	Felga *felga = new Felga(waga,szerokosc_felgi,zewnetrzna_srednica_felgi);
	kolo->zamontuj_felge(felga);
	bool check=true;
	while (check) {
		cout << "Podaj parametry opony: " << endl;
		cout << "Waga w kg: ";
		double waga;
		cin >> waga;
		cout << "Szerokosc opony w mm: ";
		double szerokosc_opony;
		cin >> szerokosc_opony;
		cout << "Srednica osadzenia na feldze w calach: ";
		double szerokosc_osadzenia_na_feldze;
		cin >> szerokosc_osadzenia_na_feldze;

		if (szerokosc_opony > szerokosc_felgi - 10 and szerokosc_opony<szerokosc_felgi + 10 and (szerokosc_osadzenia_na_feldze * 25.4)>zewnetrzna_srednica_felgi - 10 and (szerokosc_osadzenia_na_feldze * 25.4) < zewnetrzna_srednica_felgi + 10) {
			Opona* opona = new Opona(waga, szerokosc_opony, szerokosc_osadzenia_na_feldze);
			kolo->zamontuj_opone(opona);
			check = false;
		}
		else {
			cout << "Niestety podana opona nie pasuje do felgi, wprowadź dane opony jeszcze raz" << endl;
		}
	}
	cout << "Kolo zamontowane! Waga kola to: " << kolo->get_waga(); cout << "kg";
}

int main() {
	int wybor;
	do
	{
		cout << endl << "Wybierz numer zadania od 1 do 5. Wybor 0 powoduje zamkniecie programu" << endl;
		cin >> wybor;
		switch (wybor)
		{
		case 1:
		{
			cout << "Zadanie 1" << endl;
			Rectangle prostokat("prostokat", 2, 4);
			Square kwadrat("kwadrat", 4);
			cout << prostokat.area() << endl;
			cout << kwadrat.area() << endl;

			Shape &prostokatRef = prostokat;
			Rectangle &kwadratRef = kwadrat;

			cout << prostokatRef.area() << endl;
			cout << kwadratRef.area() << endl;

			Shape* prostokatWsk = &prostokat;
			Rectangle* kwadratWsk = &kwadrat;

			cout << prostokatWsk ->area() << endl;
			cout << kwadratWsk -> area() << endl;

			break;

		}
		case 2:
		{
			cout << "Zadanie 2" << endl;
			Cylinder c1("cylinder", 3, 5);
			cout << c1.volume() << endl;
			break;
		}
		case 3:
		{
			cout << "Zadanie 3" << endl;
			FunkcjaLiniowa myFunction(1,2);
    		cout << "Dla x = 3 wartosc funkcji jest rowna: " << myFunction.oblicz(3) << endl;
			break;
		}
		case 4:
		{
			cout << "Zadanie 4" << endl;

			double p,k,d;
			double a,b;

			cout << "Podaj p: "; cin >> p;
			cout << "Podaj k: "; cin >> k;
			cout << "Podaj d: "; cin >> d;
			cout << "Podaj a: "; cin >> a;
			cout << "Podaj b: "; cin >> b;

			FunkcjaLiniowa myFunction2(a,b);
			cout << bisekcja(&myFunction2,p,k,d) << endl;

			break;
		}
		case 5:
		{
			cout << "Zadanie 5" << endl;
			symulatorOpon();
			break;
		}
		}
	} while (wybor != 0);
	return 0;
}

