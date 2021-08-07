// KRISTIJAN ÈULINA 15.01.2020
#include <iostream>
#include <cstring>
#include <typeinfo>
 
using namespace std;
class cosnovna {
    public:
        cosnovna *sljedeci;
    
        virtual void unos() = 0;
    
        virtual void ispis () = 0;
        
        virtual void pretraga(int x) = 0;
        
        virtual void pretraga_cp(int x) = 0;
        
        virtual int gledaj() = 0;
};
 
// cpredmet
class cpredmet: public cosnovna {
    public:
        int sifra_predmeta;
        char naziv_predmeta;
        void unos() {
            cout << "Sifra predmeta: ";
                cin >> sifra_predmeta;
            cout << "Naziv predmeta: ";
                cin >> naziv_predmeta;
        }
        void ispis() {
            cout << "Sifra predmeta: " << sifra_predmeta << endl;
            cout << "Naziv predmeta: " << naziv_predmeta << endl;
        }
        void pretraga(int x)
        {
            if (x == sifra_predmeta)
            cout << "Naziv predmeta: " << naziv_predmeta << endl;
        }
        int gledaj()
        {
            return sifra_predmeta;
        }
        cpredmet() {
            cout << "Novi predmet!" << endl;
        }
        ~cpredmet() {
            cout << "Brišem prijavu!" << endl;
        }
};
 
// cprijava
class cprijava: public cosnovna {
    public:
        int sifra_prijave;
        int mat_br;
        int sifra_predmeta;
        int rok;
        void unos()
        {
            cout << "Sifra prijave: ";
                cin >> sifra_prijave;
            cout << "Maticni broj: ";
                cin >> mat_br;
            cout << "Sifra predmeta: ";
                cin >> sifra_predmeta;
            cout << "Rok:";
                cin >> rok;
        }
        void ispis() 
        {
            cout << "Sifra prijave: " << sifra_prijave << endl;
            cout << "Maticni broj: " << mat_br << endl;
            cout << "Sifra predmeta: " << sifra_predmeta << endl;
            cout << "Rok: " << rok << endl;
        }
        void pretraga_cp(int x)
        {
            if (sifra_predmeta == x)
            {
                ispis();
            }
        }
        int gledaj()
        {
            return sifra_prijave;
        }
        cprijava()
        {
            cout << "Nova prijava!" << endl;
        }
        ~cprijava()
        {
            cout << "Brisem prijavu!" << endl;
        }
        
};
 
cosnovna *lista;
 
void zadatak1()
{   
    // unos
    cosnovna *novi,*zadnji;
    int izbor;
    cout << "Unesite 1 za unos predmeta // 2 za unos prijave: ";
        cin >> izbor;
    zadnji = lista;
    while (zadnji->sljedeci)
        zadnji = zadnji -> sljedeci;
    switch(izbor)
    {
        case 1: novi = new cpredmet; break;
        case 2: novi = new cprijava; break;
    }
    novi -> sljedeci = NULL;
    zadnji -> sljedeci = novi;
    novi->unos();
    
    // ispis
    cosnovna *trenutni;
    trenutni = lista->sljedeci;
    while (trenutni)
    {   
        trenutni->ispis();
        trenutni = trenutni->sljedeci;
    }
}
 
void zadatak2()
{
    cosnovna *trenutni;
    trenutni = lista->sljedeci;
    int br_cpredmet = 0;
    int br_cprijava = 0;
    while (trenutni)
    {   
        if (!strcmp(typeid(*(trenutni)).name(),"8cpredmet"))
        {
        trenutni->ispis();
        br_cpredmet ++;
        }
        trenutni = trenutni->sljedeci;
    }
    trenutni = lista->sljedeci;
        while (trenutni)
    {   
        if (!strcmp(typeid(*(trenutni)).name(),"8cprijava"))
        {
        trenutni->ispis();
        br_cprijava ++;
        }
        trenutni = trenutni->sljedeci;
    }
    cout << "Ukupan broj zapisa klase cpredmet: " << br_cpredmet << endl;
    cout << "Ukupan broj zapisa klase cprrijava: " << br_cprijava << endl;
}
 
void zadatak3()
{
    cosnovna *trenutni;
    trenutni = lista -> sljedeci;
    int sifra;
    cout << "Unesi sifru koju zelis pretraziti: ";
        cin >> sifra;
    while (trenutni)
    {
        if (!strcmp(typeid(*(trenutni)).name(),"8cpredmet"))
        {
            trenutni->pretraga(sifra);
        }
        if (!strcmp(typeid(*(trenutni)).name(),"8cprijava"))
        {
            trenutni->pretraga_cp(sifra);
        }
        
        trenutni = trenutni->sljedeci;
    }
}
 
void zadatak4()
{
    int izbor;
    cout << "Unesite 1 za predmet // 2 za prijavu: ";
        cin >> izbor;
    char ime[20];
    int sifra_brisanje;
    cout << "Unesite sifru brisanja: ";
        cin >> sifra_brisanje;
    if (izbor == 1)
        strcpy(ime,"8cpredmet");
    if (izbor == 2)
        strcpy(ime,"8cprijava");
    cosnovna *brisi,*prethodni;
    brisi = lista->sljedeci;
    prethodni = lista;
    while (brisi)
    {
        if((!strcmp(typeid(*brisi).name(),ime)) && (sifra_brisanja==brisi->gledaj()))
        {
            prethodni->sljedeci = brisi->sljedeci;
            delete brisi;
            brisi = prethodni->sljedeci;
        }
        else
        {
            prethodni = brisi;
            brisi = brisi->sljedeci;
        }
    }
}
int main()
 
{   
    lista = new cosnovna;
    lista -> sljedeci = NULL;
    int izbor;
    do {
        cout << "IZBOR: ";
            cin >> izbor;
    switch (izbor)
    {
        case 1: zadatak1(); break;
        case 2: zadatak2(); break;
        case 3: zadatak3(); break;
        case 4: zadatak4(); break;
    }
        
    } while (izbor != 9);
 
    return 0;
}
