#include <iostream>
#include <iomanip>
#include <windows.h>
#include <vector>
using namespace std;

class time
{
    unsigned int godziny;
    unsigned int minuty;
    unsigned int sekundy;
public:
    time(unsigned int s):sekundy(s)
    {
        minuty=sekundy/60;
        sekundy=sekundy%60;
        godziny=minuty/60;
        minuty=minuty%60;
    }
    void wypisz()
    {
        cout<<godziny<<":";
        cout<< setfill('0') << setw(2) << minuty<<":";
        cout<< setfill('0') << setw(2) << sekundy;
        cout<<endl;
    }
    unsigned int zwr_g()
    {
        return godziny;
    }
    unsigned int zwr_m()
    {
        return minuty;
    }
    unsigned int zwr_s()
    {
        return sekundy;
    }
};
void zadanie1()
{
    time t(3936);
    t.wypisz();
}

class student{
    string imie;
    string nazwisko;
    int indeks;
public:
    void dodaj()
    {
        cout<<"podaj imie:"<<endl;
        cin>>imie;
        cout<<"podaj nazwisko:"<<endl;
        cin>>nazwisko;
        cout<<"podaj indeks:"<<endl;
        cin>>indeks;
    }
    void wypisz()
    {
        cout<<"Imie: "<<imie<<" Nazwisko: "<<nazwisko<<" Indeks: "<<indeks<<endl;
    }
    int zwr_indeks()
    {
        return indeks;
    }
};

void zadanie2()
{
    cout<<"Ilu student�w chcesz doda�:"<<endl;
    int x;
    cin>>x;
    student s;
    vector<student> bazaStudentow;
    for(int i=0; i<x; i++)
    {
        s.dodaj();
        bazaStudentow.push_back(s);
    }
    cout<<endl;
    cout<<"podaj numer indeksu studenta do wyszukania:"<<endl;
    int numer;
    cin>>numer;
    int rozmiar=bazaStudentow.size();
    for(int i=0; i<rozmiar; i++)
    {
        if(bazaStudentow[i].zwr_indeks()==numer)
        {
            bazaStudentow[i].wypisz();
            cout<<"czy chcesz usunac studenta: t/n"<<endl;
            string wybor;
            if(wybor=="t")
            {
                bazaStudentow.erase(bazaStudentow.begin() + i);
                break;
            }
            else continue;
        }
    }
    cout<<"czy wypisac baze studentow: t/n"<<endl;
    string wybor;
    cin>>wybor;
    if(wybor=="t")
    {
        for(int i=0; i<rozmiar; i++)
        {
            bazaStudentow[i].wypisz();
        }
    }


    bazaStudentow.clear();
}

int main()
{
    int x;
do
{

        cout<<"wybierz zadanie:"<<endl;
        cin>>x;

        switch(x)
        {
        case 1:
        {
            cout<<"zadanie 1"<<endl;
            zadanie1();
            break;
        }
        case 2:
        {
            cout<<"zadanie 2"<<endl;
            zadanie2();
            break;
        }
        }
        cout<<endl;
}while(x<=2);

        return 0;
}
