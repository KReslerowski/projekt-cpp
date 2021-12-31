#include <math.h>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

#define RESET "\033[0m";
#define RED "\033[31m"

void zad3a();
void zad3b();
void zad4a();
void zad4b();

// zadanie 1

class no_real_solution : public runtime_error {
   public:
    no_real_solution(const string& what) : runtime_error(what) {}
    virtual const char* what() const throw() {
        return "no roots for this arguments";
    }
} except("no roots");

class BinomialSolver {
   private:
    double a, b, c;
    double x0, x1, x2;

   public:
    BinomialSolver(double aToAssign, double bToAssign, double cToAssign) {
        cout << aToAssign << " " << bToAssign << " " << cToAssign << "\n";
        a = aToAssign;
        b = bToAssign;
        c = cToAssign;

        findRoots();
    }

    void findRoots() {
        const double delta = (b * b) - 4 * a * c;

        if (delta > 0) {
            cout << sqrt(delta) << "\n";
            x1 = (-b - sqrt(delta)) / (2 * a);
            x2 = (-b + sqrt(delta)) / (2 * a);
        } else if (delta == 0) {
            x0 = -b / 2 * a;
        } else
            throw except;
    }

    double getA() const { return a; }

    double getB() const { return b; }

    double getC() const { return c; }

    double getX0() const { return x0; }

    double getX1() const { return x1; }

    double getX2() const { return x2; }

    double f(double x) { return (a * (x * x)) + (b * x) + c; }
};

void zad1() {
    cout << "Podaj a, b i c \n";
    double a, b, c;
    cin >> a >> b >> c;
    try {
        BinomialSolver* equation = new BinomialSolver(a, b, c);
        cout << equation->f(2) << "\n";
    } catch (exception& e) {
        cout << e.what() << "\n";
    }
}

// zadanie 2

class Doskonala {
   public:
    int value;
    int kol;
    Doskonala() {}
    Doskonala(int value_) : value(value_) {}
    virtual ~Doskonala() {}
    int returnValue() { return value; }
    virtual void Dowod();
};

void Doskonala::Dowod() {
    string temp = "";
    for (int p = 1; p < value; p++) {
        if (value % p == 0) {
            string liczba = to_string(p);
            temp += liczba;
            temp += " + ";
        }
    }
    for (int i = 1; i <= 3; i++) {
        temp.erase(temp.end() - 1);
    }
    cout << temp << endl;
}

class Liczby_doskonale : public Doskonala {
   public:
    vector<Doskonala*> dosk;
    Liczby_doskonale() {}
    ~Liczby_doskonale() {
        for (Doskonala* f : dosk) {
            delete f;
        }
        dosk.clear();
    }
    int pierwsza_dosk();
    int iloscPrzed(int n);
    bool czy_podzielnik(int p, int l);
    bool czy_doskonala(int l);
    void znajdzDoskonale(int n, int m);
    int ktoraWKolejnosci();

    void Kolejnosc() {
        for (Doskonala* f : dosk) {
            cout << f->kol << " liczba w kolejnosci: " << f->value << ": ";
            f->Dowod();
        }
    }
    void Dowod() {
        for (Doskonala* f : dosk) {
            cout << f->value << ": ";
            f->Dowod();
        }
    }
};

bool Liczby_doskonale::czy_podzielnik(int p, int l) {
    if (l % p == 0) {
        return true;
    }
    return false;
}

bool Liczby_doskonale::czy_doskonala(int l) {
    int suma = 1;
    for (int p = 2; p * p <= l; p++) {
        if (czy_podzielnik(p, l)) {
            if ((p * p) != l) {
                suma = suma + p + l / p;
            } else {
                suma += p;
            }
        }
    }
    if (suma == l && l != 1) {
        return true;
    }
    return false;
}

int Liczby_doskonale::pierwsza_dosk() {
    int i = 1;
    do {
        czy_doskonala(i);
        i++;
    } while (!czy_doskonala(i));
    return i;
}

int Liczby_doskonale::iloscPrzed(int n) {
    int licznik = 1;
    for (int i = pierwsza_dosk(); i < n; i++) {
        bool temp = czy_doskonala(i);
        if (temp) {
            licznik++;
        }
    }
    return licznik;
}

void Liczby_doskonale::znajdzDoskonale(int n, int m) {
    int licznik = iloscPrzed(n);
    for (int i = n; i <= m; i++) {
        bool temp = czy_doskonala(i);
        if (temp) {
            Doskonala* liczba = new Doskonala(i);
            liczba->kol = licznik;
            dosk.push_back(liczba);
            licznik++;
        }
    }
}

class Stos1 {
    static const int rozmiar = 3;
    int stos[rozmiar] = {0};

   public:
    Stos1(){};
    ~Stos1(){};

    void pokaz();

    bool pusty();
    bool pelny();
    void dodaj(int);
    void usun();
    void szczytowy();
    void oproznij();
    virtual void pojemnosc();
};

void Stos1::pokaz() {
    for (int i = rozmiar - 1; i >= 0; i--) cout << stos[i] << endl;
}
bool Stos1::pusty() {
    if (stos[0] == 0)
        return true;
    else
        return false;
}
bool Stos1::pelny() {
    if (stos[rozmiar - 1] == 0)
        return false;
    else
        return true;
}
void Stos1::dodaj(int x) {
    if (pelny()) {
        throw "nie mozna dodac elementu do stosu pelnego";
    }

    for (int i = 0; i < rozmiar; i++) {
        if (stos[i] == 0) {
            stos[i] = x;
            return;
        }
    }
}
void Stos1::usun() {
    if (pusty()) {
        throw "stos jest pusty";
    }

    for (int i = rozmiar - 1; i >= 0; i--) {
        if (stos[i] != 0) {
            cout << "Zdjety: " << stos[i] << endl;
            stos[i] = 0;
            return;
        }
    }
}
void Stos1::szczytowy() {
    if (pusty()) {
        throw "nie mozna odczytac elementu szczytowego z pustego stosu";
    }

    for (int i = rozmiar - 1; i >= 0; i--) {
        if (stos[i] != 0) {
            cout << "Element szczytowy: " << stos[i] << endl;
            return;
        }
    }
}
void Stos1::oproznij() {
    for (int i = rozmiar - 1; i >= 0; i--) {
        if (stos[i] != 0) {
            stos[i] = 0;
        }
    }
}
void Stos1::pojemnosc() {
    int licznik = 0;
    for (int i = rozmiar - 1; i >= 0; i--) {
        if (stos[i] != 0) {
            licznik++;
        }
    }
    cout << "Pojemnosc stosu: " << licznik << endl;
}

// b

class Stos2 {
    vector<int> stos;

   public:
    Stos2(){};
    ~Stos2(){};

    void pokaz() {
        for (int i = stos.size() - 1; i >= 0; i--) {
            cout << stos[i];
        }
    }

    bool pusty() { return stos.empty(); }

    void dodaj(int x) { stos.push_back(x); }

    void usun() {
        if (pusty()) {
            throw "stos jest pusty";
        }

        cout << "Zdjeto: " << stos[stos.size() - 1] << endl;
        stos.pop_back();
    }

    void szczytowy() {
        if (pusty()) {
            throw "nie mozna odczytac elementu szczytowego z pustego stosu";
        }

        cout << "Element szczytowy: " << stos[stos.size() - 1] << endl;
    }

    void oproznij() { stos.clear(); }

    virtual void pojemnosc() { cout << "Pojemnosc stosu: " << stos.size(); }
};

// zadanie 4a

class Dwa_stosy1 : public Stos1 {
    static const int rozmiar = 5;
    int stos1[rozmiar] = {0};
    int stos2[rozmiar] = {0};

   public:
    Dwa_stosy1() {}
    ~Dwa_stosy1() {}

    void usun_pare(int* tab1, int* tab2) {
        usun(tab1);
        usun(tab2);
    }
    void dodaj_pare(int x1, int* tab1, int x2, int* tab2) {
        dodaj(x1, tab1);
        dodaj(x2, tab2);
    }
    void szczytowe() {
        bool flaga1 = true, flaga2 = true;

        if (!pusty(stos1)) {
            flaga1 = false;
            for (int i = rozmiar - 1; i >= 0; i--) {
                if (stos1[i] != 0) {
                    cout << "Element szczytowy stosu1: " << stos1[i] << endl;
                    break;
                }
            }
        }
        if (!pusty(stos2)) {
            flaga2 = false;
            for (int i = rozmiar - 1; i >= 0; i--) {
                if (stos2[i] != 0) {
                    cout << "Element szczytowy stosu2: " << stos2[i] << endl;
                    break;
                }
            }
        }

        if (flaga1 || flaga2) throw "jedne ze stosow jest pusty";
    }
    virtual void pojemnosc(int* tab) {
        int licznik = 0;
        for (int i = rozmiar - 1; i >= 0; i--) {
            if (tab[i] != 0) {
                licznik++;
            }
        }
        cout << "Pojemnosc stosu: " << licznik << endl;
    }

    // przeciazenia
    bool pusty(int* tab) {
        if (tab[0] == 0)
            return true;
        else
            return false;
    }
    bool pelny(int* tab) {
        if (tab[rozmiar - 1] != 0)
            return true;
        else
            return false;
    }
    void dodaj(int x, int* tab) {
        if (pelny(tab)) {
            throw "nie mozna dodac elementu do stosu pelnego";
        }

        for (int i = 0; i < rozmiar; i++) {
            if (tab[i] == 0) {
                tab[i] = x;
                return;
            }
        }
    }
    void usun(int* tab) {
        if (pusty(tab)) {
            throw "stos jest pusty";
        }

        for (int i = rozmiar - 1; i >= 0; i--) {
            if (tab[i] != 0) {
                cout << "Zdjety: " << tab[i] << endl;
                tab[i] = 0;
                return;
            }
        }
    }

    // wyswietlanie stosow
    void pokaz1() {
        for (int i = rozmiar - 1; i >= 0; i--) {
            cout << stos1[i] << endl;
        }
    }
    void pokaz2() {
        for (int i = rozmiar - 1; i >= 0; i--) {
            cout << stos2[i] << endl;
        }
    }

    // gettery
    int* getStos1() { return stos1; }
    int* getStos2() { return stos2; }
};

// zadanie 4b

class Dwa_stosy2 : public Stos2 {
    vector<int> stos1;
    vector<int> stos2;

   public:
    Dwa_stosy2() {}
    ~Dwa_stosy2() {}

    void usun_pare(vector<int>& tab1, vector<int>& tab2) {
        usun(tab1);
        usun(tab2);
    }
    void dodaj_pare(int x1, vector<int>& tab1, int x2, vector<int>& tab2) {
        dodaj(x1, tab1);
        dodaj(x2, tab2);
    }
    void szczytowe() {
        bool flaga1 = true, flaga2 = true;

        if (!pusty(stos1)) {
            flaga1 = false;
            cout << "Element szczytowy: " << stos1[stos1.size() - 1] << endl;
        }

        if (!pusty(stos2)) {
            flaga2 = false;
            cout << "Element szczytowy: " << stos2[stos2.size() - 1] << endl;
        }

        if (flaga1 || flaga2) throw "jedne ze stosow jest pusty";
    };
    virtual void pojemnosc(vector<int>& tab) {
        cout << "Pojemnosc stosu: " << tab.size();
    }

    // przeciazenia
    void dodaj(int x, vector<int>& tab) { tab.push_back(x); }
    void usun(vector<int>& tab) {
        if (pusty(tab)) {
            throw "stos jest pusty";
        }

        cout << "Zdjeto: " << tab[tab.size() - 1] << endl;
        tab.pop_back();
    }
    bool pusty(vector<int>& tab) { return tab.empty(); }

    // wyswietlanie stosow
    void pokaz1() {
        for (auto i : stos1) {
            cout << i << endl;
        }
    }
    void pokaz2() {
        for (auto i : stos2) {
            cout << i << endl;
        }
    }

    // gettery
    vector<int>& getStos1() { return stos1; }
    vector<int>& getStos2() { return stos2; }
};

void zad3a() {
    Stos1 stos;
    int var;

    for (int i = 0; i < 2; i++) {
        cout << "Podaj liczbe do dodania na stos: ";
        cin >> var;
        try {
            stos.dodaj(var);
        } catch (const char* e) {
            cout << "Blad: " << e << endl;
        }
    }

    try {
        stos.szczytowy();
    } catch (const char* e) {
        cout << "Blad: " << e << endl;
    }

    try {
        stos.usun();
    } catch (const char* e) {
        cout << "Blad: " << e << endl;
    }

    for (int i = 0; i < 3; i++) {
        cout << "Podaj liczbe do dodania na stos: ";
        cin >> var;
        try {
            stos.dodaj(var);
        } catch (const char* e) {
            cout << "Blad: " << e << endl;
        }
    }

    for (int i = 0; i < 4; i++) {
        try {
            stos.usun();
        } catch (const char* e) {
            cout << "Blad: " << e << endl;
        }
    }

    try {
        stos.szczytowy();
    } catch (const char* e) {
        cout << "Blad: " << e << endl;
    }
}

void zad3b() {
    Stos2 stos;
    int var;

    for (int i = 0; i < 2; i++) {
        cout << "Podaj liczbe do dodania na stos: ";
        cin >> var;
        stos.dodaj(var);
    }

    try {
        stos.szczytowy();
    } catch (const char* e) {
        cout << "Blad: " << e << endl;
    }

    try {
        stos.usun();
    } catch (const char* e) {
        cout << "Blad: " << e << endl;
    }

    for (int i = 0; i < 3; i++) {
        cout << "Podaj liczbe do dodania na stos: ";
        cin >> var;
        stos.dodaj(var);
    }

    for (int i = 0; i < 5; i++) {
        try {
            stos.usun();
        } catch (const char* e) {
            cout << "Blad: " << e << endl;
        }
    }

    try {
        stos.szczytowy();
    } catch (const char* e) {
        cout << "Blad: " << e << endl;
    }
}

void zad4a() {
    Dwa_stosy1 stosy;
    int x;

    for (int i = 0; i < 3; i++) {
        cout << "Podaj wartosc do dodania, do stosu1: ";
        cin >> x;
        try {
            stosy.dodaj(x, stosy.getStos1());
        } catch (const char* e) {
            cout << "Blad: " << e << endl;
        }
    }

    for (int i = 0; i < 2; i++) {
        cout << "Podaj wartosc do dodania, do stosu2: ";
        cin >> x;
        try {
            stosy.dodaj(x, stosy.getStos2());
        } catch (const char* e) {
            cout << "Blad: " << e << endl;
        }
    }

    try {
        stosy.usun(stosy.getStos2());
    } catch (const char* e) {
        cout << "Blad: " << e << endl;
    }

    try {
        stosy.usun_pare(stosy.getStos1(), stosy.getStos2());
    } catch (const char* e) {
        cout << "Blad: " << e << endl;
    }

    try {
        stosy.szczytowe();
    } catch (const char* e) {
        cout << "Blad: " << e << endl;
    }

    try {
        stosy.usun(stosy.getStos2());
    } catch (const char* e) {
        cout << "Blad: " << e << endl;
    }

    cout << "Zawartosc stosu 1: " << endl;
    stosy.pokaz1();
    cout << endl;

    cout << "Zawartosc stosu 2: " << endl;
    stosy.pokaz2();
    cout << endl;

    try {
        stosy.usun(stosy.getStos2());
    } catch (const char* e) {
        cout << "Blad: " << e << endl;
    }
}

void zad4b() {
    Dwa_stosy2 stosy;
    int x;

    for (int i = 0; i < 3; i++) {
        cout << "Podaj wartosc do dodania, do stosu1: ";
        cin >> x;
        try {
            stosy.dodaj(x, stosy.getStos1());
        } catch (const char* e) {
            cout << "Blad: " << e << endl;
        }
    }

    cout << "Zawartosc stosu 1: " << endl;
    stosy.pokaz1();
    cout << endl;

    cout << "Zawartosc stosu 2: " << endl;
    stosy.pokaz2();
    cout << endl;

    for (int i = 0; i < 2; i++) {
        cout << "Podaj wartosc do dodania, do stosu2: ";
        cin >> x;
        try {
            stosy.dodaj(x, stosy.getStos2());
        } catch (const char* e) {
            cout << "Blad: " << e << endl;
        }
    }

    try {
        stosy.usun(stosy.getStos2());
    } catch (const char* e) {
        cout << "Blad: " << e << endl;
    }

    try {
        stosy.usun_pare(stosy.getStos1(), stosy.getStos2());
    } catch (const char* e) {
        cout << "Blad: " << e << endl;
    }

    try {
        stosy.szczytowe();
    } catch (const char* e) {
        cout << "Blad: " << e << endl;
    }

    try {
        stosy.usun(stosy.getStos2());
    } catch (const char* e) {
        cout << "Blad: " << e << endl;
    }

    cout << "Zawartosc stosu 1: " << endl;
    stosy.pokaz1();
    cout << endl;

    cout << "Zawartosc stosu 2: " << endl;
    stosy.pokaz2();
    cout << endl;
}

// zadanie 5

class BST {
    struct node {
        int data;
        node* left;
        node* right;
    };

    node* root;

    node* makeEmpty(node* t) {
        if (t == NULL) return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

    node* insert(int x, node* t) {
        if (t == NULL) {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        } else if (x < t->data)
            t->left = insert(x, t->left);
        else if (x > t->data)
            t->right = insert(x, t->right);
        return t;
    }

    node* findMin(node* t) {
        if (t == NULL)
            return NULL;
        else if (t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node* remove(int x, node* t) {
        node* temp;
        if (t == NULL)
            return NULL;
        else if (x < t->data)
            t->left = remove(x, t->left);
        else if (x > t->data)
            t->right = remove(x, t->right);
        else if (t->left && t->right) {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        } else {
            temp = t;
            if (t->left == NULL)
                t = t->right;
            else if (t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }

    void inorder(node* t) {
        if (t == NULL) return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

    node* find(node* t, int x) {
        if (t == NULL)
            return NULL;
        else if (x < t->data)
            return find(t->left, x);
        else if (x > t->data)
            return find(t->right, x);
        else
            return t;
    }

   public:
    BST() { root = NULL; }
    ~BST() { root = makeEmpty(root); }

    void AddElement(int x) {
        try {
            if (find(root, x) != NULL) throw "element jest juz w drzewie";
        } catch (const char* e) {
            cout << RED;
            cout << e << "\n";
        }

        root = insert(x, root);
    }
    void DeleteElement(int x) {
        try {
            if (root == NULL) throw "drzewo jest puste";
            if (find(root, x) == NULL) throw "brak elementu w drzewie";
        } catch (const char* e) {
            cout << RED;
            cout << e << "\n";
        }

        root = remove(x, root);
    }
    void PrintTree() {
        inorder(root);
        cout << endl;
    }
};

void zad5() {
    BST drzewo;
    int x, choice;

    do {
        cout << RESET;

        cout << "Wybierz  zadanie \n";

        cout << "dodaj do drzewa - 1 \n";
        cout << "usun z drzewa - 2 \n";
        cout << "wyswietl drzewo - 3 \n";
        cout << "wyjscie - 0 \n";

        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Podaj wartosc do dodania: ";
                cin >> x;
                drzewo.AddElement(x);
                break;
            }
            case 2: {
                cout << "Podaj wartosc do usuniecia: ";
                cin >> x;
                drzewo.DeleteElement(x);
                break;
            }
            case 3: {
                cout << "Drzewo: ";
                drzewo.PrintTree();
                break;
            }
            default:
                break;
        }

    } while (choice != 0);
}

// main

int main() {
    int choice;

    do {
        cout << RESET;
        cout << "Wybierz  zadanie \n";

        cout << "zadanie 1 - 1 \n";
        cout << "zadanie 2 - 2 \n";
        cout << "zadanie 3a - 31 \n";
        cout << "zadanie 3b - 32 \n";
        cout << "zadanie 4a - 41 \n";
        cout << "zadanie 4b - 42 \n";
        cout << "zadanie 5 - 5 \n";
        cout << "wyjscie - 0 \n";

        cin >> choice;

        switch (choice) {
            case 1: {
                zad1();
                break;
            }
            case 31: {
                zad3a();
                break;
            }
            case 32: {
                zad3b();
                break;
            }
            case 41: {
                zad4a();
                break;
            }
            case 42: {
                zad4b();
                break;
            }
            case 5: {
                zad5();
                break;
            }
            default:
                break;
        }

    } while (choice != 0);

    return 1;
}