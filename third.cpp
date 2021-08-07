//KRISTIJAN ČULINA 28.10.2019
 
 
#include <iostream>
#include "biblioteka_vrijeme.cc"
#include <cstring>
 
using namespace std;
 
struct element
{
    int sifra;
    char prezime[30];
    char naslov[40];
    int vrijeme;
    element *prethodni;
    element *sljedeci;
};
// binarno stablo - prethodni = lijevi ////  sljedeci = desni//
element *lista;
element *stablo;
 
void upis_kraj ()
{
    element *zadnji,*novi;
    zadnji = lista;
    while (zadnji->sljedeci)
            zadnji = zadnji->sljedeci;
    novi = new element;
    zadnji->sljedeci=novi;
    novi->sljedeci = NULL;
    novi->prethodni = zadnji;
    vrijeme_pocetak();
    cout << "Sifra: "; 
        cin >> novi->sifra;
    cout << "Prezime: ";
        cin >> novi->prezime;
    cout << "Naslov: ";
        cin >> novi->naslov;
    vrijeme_kraj();
    novi->vrijeme = vrijeme_proteklo()/1000;
    cout << "Vrijeme: " << novi->vrijeme << endl;
    cout << "--------------------" << endl; 
    element *trenutni;
    trenutni = lista->sljedeci;
    while(trenutni) 
    {
        cout << "Sifra: " << trenutni->sifra << endl;
        cout << "Prezime: " << trenutni->prezime << endl;
        cout << "Naslov: " << trenutni->naslov << endl;
        cout << "Vrijeme: " << trenutni->vrijeme << endl;
        trenutni=trenutni->sljedeci;
    }
        
}
 
void upis_pocetak()
{       
    if (!lista->sljedeci)
    {
        upis_kraj(); 
        return;  
    }
    element *novi,*sljedeci;
    sljedeci = lista->sljedeci;
    novi = new element;
    novi->prethodni=lista;
    novi->sljedeci=sljedeci;
    lista->sljedeci=novi;
    sljedeci->prethodni=novi;
    vrijeme_pocetak();
    cout << "Sifra: "; 
        cin >> novi->sifra;
    cout << "Prezime: ";
        cin >> novi->prezime;
    cout << "Naslov: ";
        cin >> novi->naslov;
    vrijeme_kraj();
    novi->vrijeme = vrijeme_proteklo()/1000;
    cout << "Vrijeme: " << novi->vrijeme << endl;   
    cout << "-------------------" << endl;
 
    element *trenutni;
    trenutni = lista;
    while(trenutni->sljedeci)
        trenutni=trenutni->sljedeci;
    while(trenutni!=lista) 
    {
        cout << "Sifra: " << trenutni->sifra << endl;
        cout << "Prezime: " << trenutni->prezime << endl;
        cout << "Naslov: " << trenutni->naslov << endl;
        cout << "Vrijeme: " << trenutni->vrijeme << endl;
        trenutni=trenutni->prethodni;
    }
        
}
 
void brisanje() 
{
    element *brisi,*prethodni,*sljedeci;
    prethodni = lista;
    brisi = lista->sljedeci;
    sljedeci = brisi->sljedeci;
    int brojac = 0;
    int pretraga;
    cout << "Unesi sifru koju zelis obrisati: ";
        cin >> pretraga;
    while(brisi)
        {
            if(pretraga==brisi->sifra)
                {
                    prethodni->sljedeci=brisi->sljedeci;
                    sljedeci->prethodni = brisi->prethodni;
                    delete brisi;
                    cout << "Element je izbrisan!" << endl;
                    return;                 
                }
        prethodni = brisi;
        brisi = brisi->sljedeci;
        sljedeci = sljedeci->sljedeci;
        }
        if (brojac==0) cout << "Greška - Nije pronađen autor s tom sifrom! " << endl;
}
void novi_element() 
{
    element *zadnji,*novi;
    int dalje = 1;
    zadnji = stablo;
    int sifra,vrijeme;
    char prezime[40],naslov[40];
    vrijeme_pocetak();
    cout << "Sifra: "; 
        cin >> sifra;
    cout << "Prezime: ";
        cin >> prezime;
    cout << "Naslov: ";
        cin >> naslov;
    vrijeme_kraj();
    vrijeme = vrijeme_proteklo()/1000;
do 
    {
        if (sifra>zadnji->sifra)
        {
            if(zadnji->sljedeci!=NULL)
            {
                zadnji=zadnji->sljedeci;
            }
            else
            {
                novi = new element;
                zadnji->sljedeci = novi;
                novi->sifra = sifra;
                strcpy(novi->prezime,prezime);
                strcpy(novi->naslov,naslov);        
                novi->vrijeme = vrijeme;
                novi->sljedeci = NULL;
                novi->prethodni = NULL;
                dalje=0;
            };
        }
        else
        {
            if(zadnji->prethodni!=NULL) 
                    zadnji=zadnji->prethodni;
            else
            {
                novi = new element;
                zadnji->prethodni = novi;
                novi->sifra = sifra;
                strcpy(novi->prezime,prezime);
                strcpy(novi->naslov,naslov);
                novi->vrijeme = vrijeme;
                novi->sljedeci = NULL;
                novi->prethodni = NULL;
                dalje=0;
            };
        };
    } while (dalje==1);
    cout << "--------------------------------------------" << endl;
};
    
void ispis_uzlazno(element *stablo)
{
    static element *korijen = stablo;
    if (stablo==NULL) return;
    ispis_uzlazno(stablo->prethodni);
    if(stablo!=korijen)
    {
        cout << "Maticni broj: " << stablo->sifra << endl;
        cout << "Prezime i ime: " << stablo->prezime << endl;
        cout << "Godina upisa: " << stablo->naslov << endl;
        cout << "Vrijeme unosa: " << stablo->vrijeme << endl;
        cout << "--------------------------------------------" << endl;
    };
    ispis_uzlazno(stablo->sljedeci);
};
 
 
void ispis_silazno(element *stablo)
{
    static element *korijen = stablo;
    if (stablo==NULL) return;
    ispis_silazno(stablo->sljedeci);
    if(stablo!=korijen)
    {
        cout << "Maticni broj: " << stablo->sifra << endl;
        cout << "Prezime i ime: " << stablo->prezime << endl;
        cout << "Godina upisa: " << stablo->naslov << endl;
        cout << "Vrijeme unosa: " << stablo->vrijeme << endl;
        cout << "--------------------------------------------" << endl;
    };
    ispis_silazno(stablo->prethodni);
};
 
 
 
int main()
{
    lista = new element;
    lista->sljedeci=NULL;
    lista->prethodni=NULL;
    stablo = new element;
    stablo->sljedeci = NULL;
    stablo->prethodni = NULL;
    int izbor;
 
do 
{ 
    cout << "IZBORNIK: " << endl;
    cout << "1. Dodavanje elementa na kraj DVL // ispis od početka" << endl;
    cout << "2. Dodavanje elementa na pocetak DVL // ispis od kraja" << endl;
    cout << "3. Brisanje cvora iz dvostruko vezane liste" << endl;
    cout << "4. Dodavanje novog čvora u binarno stablo" << endl;
    cout << "5. Ispis binarnog stabla uzlazno" << endl;
    cout << "6. Ispis binarnog stabla silazno" << endl;
    cout << "9. Kraj programa" << endl;
    cout << "Izbor: ";
        cin >> izbor;
        
    switch(izbor) 
    {
        
        case 1: upis_kraj(); break;
        case 2: upis_pocetak(); break;
        case 3: brisanje(); break;
        case 4: novi_element(); break;
        case 5: ispis_uzlazno(stablo); break;
        case 6: ispis_silazno(stablo); break;
        case 9: break;
        default: cout << "Pogreška - krivi unos!" << endl;
        
        
    } 
        cout << "--------------" << endl;
    
} while(izbor !=9);
    
    
    
    return 0;
    system("pause");
}
