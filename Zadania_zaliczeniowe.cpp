#include <iostream>
#include <map>
#include <math.h>

using namespace std;

class Bryla_z_Prostokata
{
protected:
	int a1, a2;
	double pole = 0;
public:
	
	Bryla_z_Prostokata()
	{

	}
	Bryla_z_Prostokata(int a1,int a2)
	{
		this->a1 = a1;
		this->a2 = a2;
	}
	virtual double oblicz_pole()
	{
		return pole;
	}
	int get_a1()
	{
		return a1;
	}
	int get_a2()
	{
		return a2;
	}
	~Bryla_z_Prostokata()
	{

	}
};

class Walec_przez_Obrot : Bryla_z_Prostokata
{
public:
	bool obrot;
	int a1,a2;
	Walec_przez_Obrot(bool obrot)
	{
		this->obrot = obrot;
	}

	void info()
	{
		cout << "pierwszy bok " << a1  << " drugi bok " << a2 << " ktory bok " << obrot << " pole " << oblicz_pole()<<endl;
	}

	virtual double oblicz_pole()
	{
		double pi = atan(1) * 4; //liczę pi ze wzoru arcustangens(1) * 4
		if (obrot) //obracamy przez dłuższy bok
		{
			if (a1 > a2) //który jest dłuższy
			{
				return 2 * pi * this->a1 * this->a1 + 2 * pi * this->a1 * this->a2;
			}
			else
			{
				return 2 * pi * this->a2 * this->a2 + 2 * pi * this->a1 * this->a2;
			}
		}
		else
		{
			if (a1 > a2) //który jest dłuższy
			{
				return 2 * pi * this->a2 * this->a2 + 2 * pi * this->a1 * this->a2;
			}
			else
			{
				return 2 * pi * this->a1 * this->a1 + 2 * pi * this->a1 * this->a2;
			}
		}
		
	}

	Walec_przez_Obrot& operator*(const double& x)
	{
		this->a2 *= x; //zakładam że a2 to wysokość, ponieważ nie jest sprecyzowane który bok to wysokość
		return *this;
	}

	~Walec_przez_Obrot()
	{

	}

};

class Pojemnik_Bryl
{
private:
	map<int,Walec_przez_Obrot> kolekcja;
public:
	Pojemnik_Bryl()
	{

	}
	~Pojemnik_Bryl()
	{

	}
	void DodajDoKolekcji(Walec_przez_Obrot walec)
	{
		int pole = floor(walec.oblicz_pole());
		map<int, Walec_przez_Obrot>::iterator iter = kolekcja.find(pole); //blokada dodania dwóch takich samych elementów do mapy
		if (iter == kolekcja.end())
		{
			kolekcja.insert(pair<int, Walec_przez_Obrot>(pole, walec));
		}
	}
	bool PolePowierzchniWieksze()
	{
		map<int, Walec_przez_Obrot>::iterator iter;

		for (iter = kolekcja.begin(); iter != kolekcja.end(); iter++) //iteracja przez mapę
		{
			if (iter->first > 300)
			{
				return true;
			}
		}
		return false;
	}
	void ZwiekszWysokosci()
	{
		map<int, Walec_przez_Obrot>::iterator iter;

		for (iter = kolekcja.begin(); iter != kolekcja.end(); iter++)//iteracja przez mapę
		{
			iter->second.operator*(1.5); //zwiększenie wysokości
			iter->second.info();
		}
	}

};

void zadanie3_4()
{
	//ZADANIE 3//
	cout << "ZADANIE 3" << endl;
	Pojemnik_Bryl pojemnik;
	int dane[4][3]; //przepisanie danych
	dane[0][0] = 4;
	dane[0][1] = 5;
	dane[0][2] = 1;
	dane[1][0] = 3;
	dane[1][1] = 3;
	dane[1][2] = 0;
	dane[2][0] = 3;
	dane[2][1] = 6;
	dane[2][2] = 0;
	dane[3][0] = 4;
	dane[3][1] = 8;
	dane[3][2] = 1;
	for (int i = 0; i < 4; i++)
	{
		int a1 = dane[i][0]; //załadowanie danych
		int a2 = dane[i][1];
		bool obrot = dane[i][2];
		Bryla_z_Prostokata bzp(a1, a2);
		Walec_przez_Obrot wpo(obrot);
		wpo.a1 = bzp.get_a1(); //ustawienie pierwszego boku w walcu z bryły
		wpo.a2 = bzp.get_a2(); //ustawienie drugiego boku w walcu z bryły
		pojemnik.DodajDoKolekcji(wpo);
		wpo.info(); //wypisanie informacji o walcach
	}
	//ZADANIE 4//
	cout << "ZADANIE 4" << endl;
	if (pojemnik.PolePowierzchniWieksze()) //czy jakiś walec ma pole większe niż 300
	{
		pojemnik.ZwiekszWysokosci(); //zwiększanie wysokości
	}
}
int main()
{
	zadanie3_4();
}

