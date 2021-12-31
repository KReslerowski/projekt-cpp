#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const double PI = 3.14;
/*Klasa reprezentujaca ksztalt*/
class Shape{
public:
    string name;
    Shape(){}
    Shape(string n_) : name(n_){}
    virtual ~Shape(){}
    /*Funkcja sluzaca do ustawienia nazwy ksztaltu*/
    void setName(string name_){
        name = name_;
    }
    /*Funkcja zwracajaca nazwe ksztaltu*/
    string getName(){
        return name;
    }
    /*Wirtualne funkcje, ktore w klasach pochodnych beda
    sluzyc do obliczania pola oraz objetosci.*/
    virtual double area(){}
    virtual double perimeter(){}
};
/*Klasa reprezentujaca prostokat*/
class Rectangle : public Shape{
protected:
    double width, height;
public:
    Rectangle(string n_, double w_, double h_) : Shape(n_), width(w_), height(h_){}
    ~Rectangle(){}
    /*Funkcja wyliczajaca pole prostokata*/
    virtual double area(){
        return width*height;
    }
    /*Funkcja wyliczajaca objetosc prostokata*/
    virtual double perimeter(){
        return (2*width)+(2*height);
    }
};
/*Klasa reprezentujaca kwadrat*/
class Square : public Rectangle{
public:
    Square(string n_, double w_) : Rectangle(n_, w_, w_){}
    ~Square(){}
    /*Funkcja wyliczajaca pole kwadratu*/
    virtual double area(){
        return width*width;
    }
    /*Funkcja wyliczajaca objetosc kwadratu*/
    virtual double perimeter(){
        return (4*width);
    }
};
/*Klasa reprezentujaca kolo*/
class Circle : public Shape{
public:
    Circle(string n_, double r_) : Shape(n_), r(r_){}
    ~Circle(){}
    double r;
    double getR(){
        return r;
    }
    /*Funkcja wyliczajaca pole kola*/
    virtual double area(){
        return PI*r*r;
    }
    /*Funkcja wyliczajaca objetosc kola*/
    virtual double perimeter(){
        return 2*PI*r;
    }
};
/*Klasa reprezentujaca elipse*/
class Ellipse : public Shape{
public:
    double a,b;
    Ellipse(string n_, double a_, double b_) : Shape(n_), a(a_), b(b_){}
    ~Ellipse(){}
    /*Funkcja wyliczajaca pole elipsy*/
    virtual double area(){
        return PI*a*b;
    }
    /*Funkcja wyliczajaca objetosc elipsy*/
    virtual double perimeter(){
        double per = PI*(1.5*(a+b-sqrt(a*b)));
        return per;
    }
};
/*Klasa sluzaca do przechowywania obiektow klasy Shape*/
class ShapeContainer{
public:
    vector <Shape*> container;
    ShapeContainer(){}
    ~ShapeContainer(){
        for(Shape* f : container){
            delete f;
        }
        container.clear();
    }
    void add(Shape*);
    void displayAll() const;
    double totalArea() const;
    vector<Shape*> getGreaterThan(double area);
};
/*Funkcja dodajaca obiekt klasy Shape do pojemnika*/
void ShapeContainer::add(Shape* shape){
    container.push_back(shape);
}
/*Funkcja wyswietlajaca obiekty klasy Shape znajdujace sie w pojemniku*/
void ShapeContainer::displayAll() const{
    for(Shape* f : container){
        cout<<f->name<<" "<<f->area()<<endl;
    }
}
/*Funkcja zwracajaca sume pol wszystkich figur znajdujacych sie w pojemniku*/
double ShapeContainer::totalArea() const{
    double temp = 0;
    for(Shape* f : container){
        temp+=f->area();
    }
    return temp;
}
/*Funkcja zwracajace liste figur o polu wiekszym niz zadane przez uzytkownika*/
vector<Shape*> ShapeContainer::getGreaterThan(double area){
    vector<Shape*> temp;
    for(Shape* f : container){
        if(f->area()>area){
            temp.push_back(f);
        }
    }
    return temp;
}
/*Zadanie 1*/
void Zadanie1(){
    cout<<"Zadanie 1"<<endl;
    int choice;
    ShapeContainer shapes;
    do{
        /*Uzytkownik wybiera numer operacji, ktora chce wykonac*/
        cout<<"Co chcesz zrobic?\n1.Dodaj nowa figure do bazy\n2.Wyswietl nazwy wszystkich figur i ich pola"<<endl;
        cout<<"3.Wyswietl sume wszystkich pol\n4.Wyswietl liste figur o polu wiekszym niz podane\n0.Wyjdz\nPodaj numer operacji:";
        cin>>choice;
        switch(choice){
            case 1:{
                /*Uzytkownik wybiera jaka figure chce dodac do bazy, po czym wprowadza wartosci charakterystyczne
                dla danej figury, figura dodawana zostaje do kontenera przechowujacego figury.*/
                int choice2;
                cout<<"Jaka figure chcesz dodac?\n1.Kwadrat\n2.Prostokat\n3.Kolo\n4.Elipsa\nWprowadz numer:";
                cin>>choice2;
                switch(choice2){
                    case 1:{
                    string nazwa;
                    double bok;
                    cout<<"Podaj nazwe:";
                    cin>>nazwa;
                    cout<<"Podaj dlugosc boku:";
                    cin>>bok;
                    Shape *kwadrat = new Square(nazwa,bok);
                    shapes.add(kwadrat);
                    break;
                    }
                    case 2:{
                    string nazwa;
                    double h,w;
                    cout<<"Podaj nazwe:";
                    cin>>nazwa;
                    cout<<"Podaj wymiar pierwszego boku:";
                    cin>>h;
                    cout<<"Podaj wymiar drugiego boku:";
                    cin>>w;
                    Shape *prostokat = new Rectangle(nazwa,w,h);
                    shapes.add(prostokat);
                    break;
                    }
                    case 3:{
                    string nazwa;
                    double r;
                    cout<<"Podaj nazwe:";
                    cin>>nazwa;
                    cout<<"Podaj promien:";
                    cin>>r;
                    Shape *kolo = new Circle(nazwa,r);
                    shapes.add(kolo);
                    break;
                    }
                    case 4:{
                    string nazwa;
                    double a,b;
                    cout<<"Podaj nazwe:";
                    cin>>nazwa;
                    cout<<"Podaj dlugosc polosi wielkiej elipsy:";
                    cin>>a;
                    cout<<"Podaj dlugosc polosi malej elipsy:";
                    cin>>b;
                    Shape *elipsa = new Ellipse(nazwa,a,b);
                    shapes.add(elipsa);
                    break;
                    }
                }
                break;
            }
            case 2:{
                /*Wywolana zostaje funkcja wypisujaca wszystkie figury.*/
                shapes.displayAll();
                break;
            }
            case 3:{
                 /*Wypisana zostaje suma wszystkich pol figur znajdujacych sie w bazie.*/
                cout<<"Suma wszystkich pol w bazie wynosi "<<shapes.totalArea()<<"."<<endl;
                break;
            }
            case 4:{
                 /*Uzytkownik wpisuje pole, aby w wyniku otrzymac wypisane wszystkie figury o polu wiekszym
                 niz podal uzytkownik.*/
                double pole;
                cout<<"Wprowadz pole: ";
                cin>>pole;
                ShapeContainer figury;
                figury.container = shapes.getGreaterThan(pole);
                cout<<"Lista figur, ktore maja pole wieksze od podanego: "<<endl;
                figury.displayAll();
                break;
            }
        }
    }while(choice!=0);
}
/*Klasa reprezentujaca liczbe doskonala*/
class Doskonala{
public:
    int value;
    int kol;
    Doskonala(){}
    Doskonala(int value_) : value(value_){}
    virtual ~Doskonala(){}
    /*Funkcja zwracajaca wartosc liczby doskonalej*/
    int returnValue(){
        return value;
    }
    virtual void Dowod();
};
/*Funkcja wyswietlajaca dowod na to, ze liczba jest doskonala*/
void Doskonala::Dowod(){
    string temp = "";
    for(int p=1;p<value;p++){
        if(value%p==0){
           string liczba = to_string(p);
           temp+=liczba;
           temp+=" + ";
        }
    }
    for(int i=1;i<=3;i++){
        temp.erase(temp.end()-1);
    }
    cout<<temp<<endl;
}
/*Klasa operujaca na wektorze liczb doskonalych*/
class Liczby_doskonale : public Doskonala{
public:
    vector <Doskonala*> dosk;
    Liczby_doskonale(){}
    ~Liczby_doskonale(){
           for (Doskonala *f : dosk)
            {
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
    /*Funkcja pokazuje, ktora liczba doskonala w kolejnosci jest kazda kolejna
    liczba znajdujaca sie w kontenerze*/
    void Kolejnosc(){
        for(Doskonala* f : dosk){
            cout<<f->kol<<" liczba w kolejnosci: "<<f->value<<": ";
            f->Dowod();
        }
    }
    /*Przeciazona funkcja wyswietlajaca dowody
    dla wszystkich liczb doskonalych znajdujacych sie w wektorze*/
    virtual void Dowod(){
        for(Doskonala* f : dosk){
           cout<<f->value<<": ";
           f->Dowod();
        }
    }
};
/*Funkcja sprawdza, czy liczba p jest podzielnikiem liczby l*/
bool Liczby_doskonale::czy_podzielnik(int p, int l){
    if(l%p==0){
        return true;
    }
    return false;
}
/*Funkcja sprawdza, czy podana liczba jest liczba doskonala*/
bool Liczby_doskonale::czy_doskonala(int l){
    int suma = 1;
    for(int p=2;p*p<=l;p++){
        if(czy_podzielnik(p,l)){
            if((p*p)!=l){
                suma = suma + p + l/p;
            }
            else{
                suma+=p;
            }
        }
    }
    if(suma==l && l!=1){
        return true;
    }
    return false;
}
/*Funkcja sprawdza, czy podana liczba jest liczba doskonala*/
int Liczby_doskonale::pierwsza_dosk(){
    int i = 1;
    do{
        czy_doskonala(i);
        i++;
    }while(!czy_doskonala(i));
    return i;
}
/*Funkcja wylicza, ile liczb doskonalych znajduje sie przed
dana liczba doskonala*/
int Liczby_doskonale::iloscPrzed(int n){
    int licznik = 1;
    for(int i=pierwsza_dosk();i<n;i++){
            bool temp = czy_doskonala(i);
            if(temp){
                licznik++;
            }
        }
    return licznik;
}
/*Funkcja znajduje n-ta liczbe doskonala, gdzie n podane jest przez uzytkownika
i wypisuje wartosc tej liczby*/
void Liczby_doskonale::znajdzDoskonale(int n, int m){
    int licznik = iloscPrzed(n);
    for(int i=n;i<=m;i++){
        bool temp = czy_doskonala(i);
        if(temp){
            Doskonala *liczba = new Doskonala(i);
            liczba->kol = licznik;
            dosk.push_back(liczba);
            licznik++;
        }
    }
}
/*Zadanie 2*/
void Zadanie2(){
    /*Uzytkownik podaje zakres, w ktorym chce szukac liczb doskonalych, nastepnie tworzony jest
    pojemnik liczb doskonalych, liczby sa znajdowane, a nastepnie wypisywane wraz z dowodami*/
    cout<<"Zadanie 2"<<endl;
    int n,m;
    cout<<"Podaj pierwsza liczbe zakresu: ";
    cin>>n;
    cout<<"Podaj druga liczbe zakresu: ";
    cin>>m;
    Liczby_doskonale doskonale;
    doskonale.znajdzDoskonale(n,m);
    cout<<"Znalezione liczby doskonale wraz z dowodami: "<<endl;
    doskonale.Dowod();
}
/*Zadanie 3*/
void Zadanie3(){
    /*Uzytkownik podaje zakres, w ktorym chce szukac liczb doskonalych, nastepnie tworzony jest
    pojemnik liczb doskonalych, liczby sa znajdowane, nastepnie wypisywana jest ich liczba w kolejnosci wraz z dowodami,
    a pozniej same dowody doskonalosci*/
    cout<<"Zadanie 3"<<endl;
    Doskonala dosk;
    int n,m;
    cout<<"Podaj pierwsza liczbe zakresu: ";
    cin>>n;
    cout<<"Podaj druga liczbe zakresu: ";
    cin>>m;
    Liczby_doskonale doskonale;
    doskonale.znajdzDoskonale(n,m);
    cout<<"Znalezione liczby doskonale wraz z dowodami: "<<endl;
    doskonale.Kolejnosc(); doskonale.Dowod();
}
/*Klasa abstrakcyjna reprezentujaca funkcje*/
class Funkcja{
public:
    Funkcja(){}
    virtual ~Funkcja(){}
    virtual double oblicz(double x)=0;
};
/*Klasa reprezentujaca funkcje sinus*/
class Sinus:public Funkcja{
public:
    Sinus(){}
    ~Sinus(){}
    double oblicz(double x){
        return sin(x);
    }
};
/*Klasa reprezentujaca funkcje cosinus*/
class Cosinus:public Funkcja{
public:
    Cosinus(){}
    ~Cosinus(){}
    double oblicz(double x){
        return cos(x);
    }
};
/*Klasa reprezentujaca funkcje wykladnicza e^x*/
class Exponential:public Funkcja{
public:
    Exponential(){}
    ~Exponential(){}
    double oblicz(double x){
        return exp(x);
    }
};
/*Klasa reprezentujaca funkcje homograficzna 1/x*/
class Mobius:public Funkcja{
public:
    Mobius(){}
    ~Mobius(){}
    double oblicz(double x){
        if(x!=0){
            return 1/x;
        }
    }
};
/*Klasa reprezentujaca wybrany algorytm numeryczny*/
class AlgorytmNumeryczny{
protected:
    Funkcja *funkcja;
    double epsilon;
    AlgorytmNumeryczny(Funkcja *funkcja_, double epsilon_=0.001):funkcja(funkcja_), epsilon(epsilon_){}
    virtual ~AlgorytmNumeryczny(){}
public:
    /*Funkcja sluzaca do ustawienia wartosci epsilona*/
    void ustawEpsilon(double epsilon_){
        epsilon = epsilon_;
    }
    virtual double oblicz()=0;
};
/*Klasa reprezentujaca miejsca zerowe*/
class MiejscaZerowe : public AlgorytmNumeryczny{
protected:
    double a = -1.0;
    double b = 1.0;
public:
    MiejscaZerowe(Funkcja *funkcja_, double epsilon_=0.001) : AlgorytmNumeryczny(funkcja_, epsilon_){}
    ~MiejscaZerowe(){}
    /*Funkcja sluzaca do ustawienia przedzialu, w jakim szukamy miejsca zerowego*/
    void ustawPrzedzial(double a_, double b_){
        a = a_; b = b_;
    }
    /*Funkcja sluzaca do obliczenia miejsca zerowego znajdujacego sie w zadanym przedziale z dokladnoscia
    epsilon, przy uzyciu metody bisekcji.*/
    double oblicz(){
        double temp;
        while(abs(a-b)>epsilon){
        temp = (a+b)/2;
        if(abs(funkcja->oblicz(temp))<=epsilon){
            break;
        }
        else if(funkcja->oblicz(temp) * funkcja -> oblicz(a)<0){
            b = temp;
        }
        else{
            a = temp;
        }
        }
        return temp;
    }
};
/*Klasa reprezentujaca pochodna*/
class Pochodna : public AlgorytmNumeryczny{
protected:
    double x = 0.0;
public:
    Pochodna(Funkcja *funkcja_) : AlgorytmNumeryczny(funkcja_){}
    ~Pochodna(){}
    /*Funkcja sluzaca do ustawienia wartosci x*/
    double ustawX(double x_){
        x = x_;
    }
    /*Funkcja wyliczajaca wynik pochodnej w zadanym punkcie x*/
    double oblicz(){
    double wynik = (funkcja->oblicz(x+epsilon)-funkcja->oblicz(x))/epsilon;
    return wynik;
    }
};
/*Funkcja sluzaca do ustawienia epsilona i przedzialu, a nastepnie
wyliczenia miejsca zerowego*/
double obliczMiejsceZerowe(Funkcja *funkcja,double a,double b, double e){
    MiejscaZerowe m(funkcja);
    m.ustawEpsilon(e);
    m.ustawPrzedzial(a,b);
    double wynik = m.oblicz();
    return wynik;
}
/*Funkcja sluzaca do ustawienia epsilona i wartosci x, a nastepnie
obliczenia pochodnej w podanym punkcie x*/
double obliczPochodna(Funkcja *funkcja, double x, double e){
    Pochodna p(funkcja);
    p.ustawEpsilon(e);
    p.ustawX(x);
    double wynik = p.oblicz();
    return wynik;
}
/*Zadanie 4*/
void Zadanie4(){
    /*Zostaja utworzone 4 funkcje podane w zadaniu, nastepnie uzytkownik podaje
    poczatek i koniec przedzialu, dokladnosc oraz wartosc x. Zostaje wyliczone miejsce zerowe kazdej funkcji
    w podanym przedziale, oraz jej pochodna w podanym punkcie x.*/
    cout<<"Zadanie 4"<<endl;
    Funkcja *sinus = new Sinus();
    Funkcja *cosinus = new Cosinus();
    Funkcja *exp = new Exponential();
    Funkcja *mob = new Mobius();
    double e, a, b, x;
    cout<<"Podaj dokladnosc: ";
    cin>>e;
    cout<<"Podaj poczatek przedzialu: ";
    cin>>a;
    cout<<"Podaj koniec przedzialu: ";
    cin>>b;
    cout<<"Podaj wartosc x: ";
    cin>>x;
    cout<<"Miejsce zerowe funkcji sinus znajduje sie w "<<obliczMiejsceZerowe(sinus,a,b,e)<<". Pochodna tej funkcji w punkcie "<<x<<" ma wartosc "<<obliczPochodna(sinus,x,e)<<"."<<endl;
    cout<<"Miejsce zerowe funkcji cosinus znajduje sie w "<<obliczMiejsceZerowe(cosinus,a,b,e)<<". Pochodna tej funkcji w punkcie "<<x<<" ma wartosc "<<obliczPochodna(cosinus,x,e)<<"."<<endl;
    cout<<"Miejsce zerowe funkcji e^x znajduje sie w "<<obliczMiejsceZerowe(exp,a,b,e)<<". Pochodna tej funkcji w punkcie "<<x<<" ma wartosc "<<obliczPochodna(exp,x,e)<<"."<<endl;
    cout<<"Miejsce zerowe funkcji 1/x znajduje sie w "<<obliczMiejsceZerowe(mob,a,b,e)<<". Pochodna tej funkcji w punkcie "<<x<<" ma wartosc "<<obliczPochodna(mob,x,e)<<"."<<endl;
    delete sinus; delete cosinus; delete exp; delete mob;
}

int main()
{
    do{
        cout<<"Podaj numer zadania: ";
        int choice;
        cin>>choice;
    switch(choice){
        case 1:{
            Zadanie1();
            break;
        }
        case 2:{
            Zadanie2();
            break;
        }
        case 3:{
            Zadanie3();
            break;
        }
        case 4:{
            Zadanie4();
            break;
        }
        default:{
            cout<<"Prosze podac poprawny numer zadania"<<endl;
        }
    }
    }while(true);
    return 0;
}
