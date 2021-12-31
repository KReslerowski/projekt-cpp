#include <iostream>

using namespace std;

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
	cout << "Kolo zamontowane! Waga kola to: " << kolo->get_waga();
}

int main() {
	symulatorOpon();
}