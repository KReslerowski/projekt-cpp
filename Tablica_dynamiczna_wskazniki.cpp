#include <iostream>

using namespace std;

class Ksztalt {
    public:
        virtual int oblicz_obwod() = 0;
    virtual string wyswietl_atrybuty() = 0;
    virtual int wprowadzDane() = 0;
};

class Prostokat: public Ksztalt {
    private: 
    string nazwa;
    float bok_a;
    float bok_b;

    public: 
    Prostokat() {};
    Prostokat(string nazwa_, float bok_a_, float bok_b_) : nazwa(nazwa_), bok_a(bok_a_), bok_b(bok_b_) {};
    ~Prostokat() {};

    virtual int wprowadzDane() {
        cin >> nazwa;
        cin >> bok_a;
        cin >> bok_b;
    }
    string getNazwa() {
        return nazwa;
    }
    float getBokA() {
        return bok_a;
    }
    float getBokB() {
        return bok_b;
    }
    virtual int oblicz_obwod() {
        return 2 * bok_a + 2 * bok_b;
    }
    virtual int oblicz_pole() {
        return bok_a * bok_b;
    }
    virtual string wyswietl_atrybuty() {
        cout << getNazwa() << " " << getBokA() << " " << getBokB() << " " << oblicz_pole() << " " << oblicz_obwod() << " ";
    }
};

class Kolo: public Ksztalt {
    private: string nazwa;
    float promien;
    public: 
    Kolo() {};
    Kolo(string nazwa_, float promien_) : nazwa(nazwa_), promien(promien_) {};
    ~Kolo() {};

    virtual int wprowadzDane() {
        cin >> promien;
        cin >> nazwa;
    }
    string getNazwa() {
        return nazwa;
    }
    float getPromien() {
        return promien;
    }
    virtual int oblicz_obwod() {
        return 2 * 3.14 * promien;
    }
    virtual int oblicz_pole() {
        return 3.14 * promien * promien;
    }
    virtual string wyswietl_atrybuty() {
        cout << getNazwa() << " " << getPromien() << " " << oblicz_obwod() << " " << oblicz_pole() << " ";
    }
};
int main() {
    int liczba_wierszy = 0;
    cin >> liczba_wierszy;
    int liczba_kolumn = 0;
    cin >> liczba_kolumn;

    Ksztalt ***tablica;
    tablica = new Ksztalt **[liczba_wierszy];
    for (int i = 0; i < liczba_wierszy; i++) {
        tablica[i] = new Ksztalt *[liczba_kolumn];
        for (int j = 0; j < liczba_kolumn; j++) {
            if (i % 2 == 0) { //parzyste
                tablica[i][j] = new Kolo;
                tablica[i][j] -> wprowadzDane();
            } else if (i % 2 == 1) { // nie parzyste
                tablica[i][j] = new Prostokat;
                tablica[i][j] -> wprowadzDane();
            }
        }
    }
    short int wartoscW = 0;
    cin >> wartoscW;
    short int wartoscK = 0;
    cin >> wartoscK;

    /*for (int i = 0; i < liczba_wierszy; i++) {
        for (int j = 0; j < liczba_wierszy; j++) {
            tablica[i][j];
        }
    }*/

    tablica[wartoscW][wartoscK] -> wyswietl_atrybuty();
     
    return 0;
}
// Przykład: Wejście: 2 3 k1 1 k2 8 k3 4 p1 1 2 p2 3 4 p3 4 5 1 1  Wyjście: p2 3 4 