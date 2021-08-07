#include <iostream>
 
using namespace std;
 
struct element
{
    int sifra;
    string prez_ime;
    string naslov;
    int vrijeme;
    element *sljedeci;
};
 
element *lista;
 
void unos() {
    element *novi;
    element *zadnji;
    zadnji = lista;
    while (zadnji->sljedeci)
        zadnji = zadnji -> sljedeci;
    novi = new element;
    zadnji -> sljedeci = novi;
    novi -> sljedeci = NULL;
    cout << "Unesi šifru: ";
        cin >> novi->sifra;
    cout << "Unesi prez_ime: ";
        cin >> novi->prez_ime;
    cout << "Unesi naslov: ";
        cin >> novi->naslov;
    cout << "Unesi vrijeme: ";
        cin >> novi->vrijeme;
}
 
void ispis() {
    element *trenutni;
    trenutni = lista->sljedeci;
    while (trenutni)
    {
        cout << "Sifra: " << trenutni->sifra << endl;
        cout << "Prez_ime: " << trenutni->prez_ime << endl;
        cout << "Naslov: " << trenutni->naslov << endl;
        cout << "Vrijeme: " << trenutni->vrijeme << endl;
        trenutni = trenutni->sljedeci; 
    }
}
 
void pretraga() {
    element *trenutni;
    trenutni = lista->sljedeci;
    int pret;
    cout << "Unesite pretragu: ";
    cin >> pret;
    int brojac = 0;
    while(trenutni)
    {
        if (pret==trenutni->sifra)
            {
                cout << "Sifra: " << trenutni->sifra << endl;
                cout << "Prez_ime: " << trenutni->prez_ime << endl;
                cout << "Naslov: " << trenutni->naslov << endl;
                cout << "Vrijeme: " << trenutni->vrijeme << endl;
                brojac++;
                break;
            }
        
        trenutni = trenutni->sljedeci;
    }
    if (brojac==0) cout << "Greška - nije pronađen!" << endl;
}
 
void brisanje() {
    element *brisi;
    element *prethodni;
    prethodni = lista;
    brisi = lista->sljedeci;
    int pret;
    cout << "Unesi pretragu: ";
    cin >> pret;
    int brojac = 0;
    while (brisi)
    {
        if (pret == brisi->sifra) {
            prethodni->sljedeci=brisi->sljedeci;
            delete brisi;
            cout << "Element je izbrisan!" << endl;
            brojac++;
            return;
        }
        
        prethodni = brisi;
        brisi = brisi->sljedeci;
        
    } 
    if (brojac==0) cout << "Greška - nije pronađen!" << endl;
}
int main() {
    lista = new element;
    lista -> sljedeci = NULL;
    int izbor;
    do{
    cout << "1. dodavanje novog elementa na kraj liste" << endl;
    cout << "2. ispis svih elemenata liste" << endl;
    cout << "3. pretrazivanje liste prema sifri" << endl;
    cout << "4. brisanje elementa liste prema maticnom sifri" << endl;
    cout << "9. Izlaz" << endl;
    cin >> izbor;
    switch(izbor) {
        case 1: unos(); break;
        case 2: ispis(); break;
        case 3: pretraga(); break;
        case 4: brisanje(); break;
        case 9: break;
        default: cout << "Kriva naredba!!!" << endl; 
    } } while(izbor !=9);
    
    
    
    return 0;
    
    
    
}
