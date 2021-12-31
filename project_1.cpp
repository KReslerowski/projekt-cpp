#include <iostream>
#include <cmath>
#include <cstdio>
#include <iomanip> // setprecision()
#include <string.h>
#include <windows.h>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

struct VerboseObject
{
    string name_object = "";
    VerboseObject (string n) : name_object(n) {cout << "wywolales konstruktor " << name_object << endl;}
    ~VerboseObject() {cout << "wywolales destruktor " << name_object << endl;}
    void metoda_wypisujaca() {cout << "wywolano metode wypisujaca nazwe obiektu" << name_object << endl;}
};
struct BinomialSolver
{
    double a,b,c;
    double x1;
    double x2;
    double zwr_a()
    {
        return a;
    }
    double zwr_b()
    {
        return b;
    }
    double zwr_c()
    {
        return c;
    }
    double zwr_x1()
    {
        return x1;
    }
    double zwr_x2()
    {
        return x2;
    }
    BinomialSolver(int xx,int x, int c_):a(xx),b(x),c(c_)
    {

    }
    ~BinomialSolver()
    {

    }
    void pierwiastki()
    {
        double delta=((b*b)-(4*a*c));
        if(delta<0)
        {
            cout<<"Brak pierwiastkow rzeczywistych rownania:";
        }
        else if(delta==0)
        {
            x1=(-b/(2*a));
            cout<<"rownanie ma jeden pierwiastek: "<<x1<<endl;
        }
        else
        {
            double pierwiastek_delta=sqrt(delta);
            x1=((-b-pierwiastek_delta)/(2*a));
            x2=((-b+pierwiastek_delta)/(2*a));
            cout<<"Rownanie ma dwa pierwiastki: "<<x1<<"; "<<x2<<endl;
        }
    }
    double calculate(double x)
    {
        double wynik=a*x*x+b*x+c;
        return wynik;
    }
};
class zespolone
{
    public:
    double rzeczywista;
    double urojona;
    zespolona();
    double licz_modul()
    {
        double mod=sqrt(pow(rzeczywista,2)+pow(urojona,2));
        return mod;
    }
};
bool sprawdz_n(short int n)
{
    if(n < 1)
    {
        return false;
    } 
    if(n >= 1)
    {
        return true;
    }
}
bool sprawdz_kolor(int R, int G, int B, bool kolor_ok)
{
    if(R >= 0 and R <= 255 and G >= 0 and G <= 255 and B >= 0 and B <= 255)
    {
        kolor_ok = true;
        return kolor_ok;
    }
    else
    {
        return kolor_ok;
    }
}
double round( double wartosc )
{
    return wartosc < 0 ? ceil( wartosc - 0.5 ) : floor( wartosc + 0.5 );
}

/*vector<string> vector1;
int licznik=0;
void read_word_by_word(string filename) {
    fstream file;
    string word;
    for (int i = 1; i <= 9; i++) {
        file.open(filename.c_str());
        string workingWord;
        while (file >> word) {
                licznik++;
            if (word.size() == i) {
                if (word != " ") {
                    workingWord = workingWord + " " + word;
                }
            }
        }
        vector1.push_back(workingWord);
        file.close();
    }
}*/
void zadanie1()
{
    cout << "Zadanie 1" << endl;
    VerboseObject a("swietna_nazwa");
    VerboseObject *b = new VerboseObject("druga_swietna_nazwa");
    delete b; // zniszczenie wektora b w pamieci
}
void zadanie2()
{
    cout << "Zadanie 2" << endl;
    BinomialSolver b(1,-5,4);
    b.pierwiastki();
    cout<<b.calculate(1);
}
void zadanie3()
{
    cout<<"Zadanie 3"<<endl;
    double x,i;
    int licznik=0;
    zespolone suma,najmodul,modul,iloczyn;
    suma.rzeczywista=0;
    suma.urojona=0;
    cout<<"Aby przerwac prowadzanie wprowac znak nie bedacy liczba"<<endl;
    cout<<"wprowadz liczbe:"<<endl;
    cin>>x;
    do
        {
            if(cin.fail())
            {
                break;
            }
            suma.rzeczywista+=x;
            cin>>i;
            suma.urojona+=i;
            if(licznik==0)
            {
                najmodul.rzeczywista=x;
                najmodul.urojona=i;
                iloczyn.rzeczywista=x;
                iloczyn.urojona=i;
            }
            else
            {
                modul.rzeczywista=x;
                modul.urojona=i;
                if(najmodul.licz_modul()<modul.licz_modul())
                {
                    najmodul=modul;
                }
                double x1=iloczyn.rzeczywista*i;
                double x2=iloczyn.urojona*x;
                iloczyn.rzeczywista=((iloczyn.rzeczywista*x)-(iloczyn.urojona*i));
                iloczyn.urojona=(x1+x2);
            }
            licznik++;
            cout<<"wprowadz liczbe:"<<endl;
        }
        while(cin>>x);
        cout<<"suma podanych liczb: "<<suma.rzeczywista<<" "<<suma.urojona<<"i"<<endl;
        cout<<"iloczyn podanych liczb: "<<iloczyn.rzeczywista<<" "<<iloczyn.urojona<<"i"<<endl;
        cout<<"liczba z najwiekszym modulem: "<<najmodul.rzeczywista<<" "<<najmodul.urojona<<"i"<<endl;
        cout<<"najwiekszy modu� wynosi: "<<najmodul.licz_modul()<<endl;
}
void zadanie4()
{
    cout << "Zadanie 4" << endl;
    short int n = 0; // liczba zestawow danych nastepujacych kolejno za n.
    short int R = 0,G = 0,B = 0;
    double red = 0, green = 0, blue = 0;
    
    double wynik_r = 0, wynik_g = 0, wynik_b = 0;
    int ilosc_danych_do_wpisania = 0;
    //sprawdz_n(n);
    cin >> n;
    if(sprawdz_n(n) == true)
    {
        ilosc_danych_do_wpisania = 10*n;
            
        for(int i = 0; i < ilosc_danych_do_wpisania; i++)
        {
            cin >> R >> G >> B;
            red += R;
            green += G;
            blue += B;
        }
        wynik_r = red / ilosc_danych_do_wpisania;
        wynik_g = green / ilosc_danych_do_wpisania;
        wynik_b = blue / ilosc_danych_do_wpisania;
        cout << round(wynik_r) << " " <<  round(wynik_g) << " "<< round(wynik_b);
    }
}
void zadanie5()
{
    double A = 0,B = 0,C = 0;
    double eps = 0;
    cin >> A >> B >> C >> eps;

    double delta = ((B*B)-(4*A*C));

    short int j = 0; // ilość zer do precyzji
    eps = 1/eps;  // żeby eps było całkowite

    for(; eps > 1; j++)
    {
        eps /= 10;
    }
    if(delta < 0)
    {
        cout << "brak rozwiazan w dziedzinie liczb rzeczywistych" << endl;
    }
    else if(delta == 0)
    {
        double x1 = -B/(2*A);
        cout << setprecision(j) << x1 << endl;
    }
    else
    {
        double x1 = ((-B - sqrt(delta)) / (2 * A));
        double x2 = ((-B + sqrt(delta)) / (2 * A));
        if(x1 > x2)
        {
            cout << setprecision(j) << x1 << endl;
        }
        else
        {
            cout << setprecision(j) << x2 << endl;
        }
    }
}
void zadanie6()
{
    cout << "Zadanie 6" << endl;
    cin.clear();
    cin.ignore();
    string ciag_wejsciowy = ""; // wzor
    getline(cin, ciag_wejsciowy); 
    string ciag_do_sprawdzenia = "";
    getline(cin, ciag_do_sprawdzenia);
    size_t x = ciag_do_sprawdzenia.find(ciag_wejsciowy);
    if(x != string::npos) // do końca ciągu
    {
        cout << "tak" << endl;
    }
    else
    {
        cout << "nie" << endl;
    }
}
void zadanie7()
{
    cout<<"Zadanie 7"<<endl;
    /*read_word_by_word("slowa.txt");
    srand(time(0));
    int result =(rand() % 9);
    cout << vector1[result] << endl;
    for (int i =0; i<licznik-1; i++)
        cout<<vector1[i];
    */
}
int main()
{
    short int numer_zadania = 0;
    cin >> numer_zadania;  
    do
    {
        system("cls");
        switch(numer_zadania)
        {
            case 1: 
            {
                zadanie1();
                break;
            }
            case 2: 
            {
                zadanie2();
                break;
            }
            case 3: 
            {
                zadanie3();
                break;
            }
            case 4: 
            {
                zadanie4();
                break;
            }
            case 5: 
            {
                zadanie5();
                break;
            }
            case 6: 
            {
                zadanie6();
                break;
            }
            case 7: 
            {
                zadanie7();
                break;
            }
            default: cout << "Error" << endl;
        }
    } while ( cin >> numer_zadania);
    return 0;
}