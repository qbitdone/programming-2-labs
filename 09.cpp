© KRISTIJAN ÈULINA
 
#include <iostream>
using namespace std;
 
class cstavka
{
    private:
        cstavka *sljedeci;
    public:
        int sifra;
        int cijena;
        int kolicina;
        
    cstavka() 
    {
        this -> sljedeci = NULL;
        cout << "Alociram element liste!" << endl;
    }
    
    ~cstavka()
    {
        cout << "Dealociram " << sifra << endl;
    }
    
    void unos()
    {
        cstavka *zadnji, *novi;
        zadnji = this;
        while (zadnji -> sljedeci)
            zadnji = zadnji -> sljedeci;
        novi = new cstavka;
        novi -> sljedeci = NULL;
        zadnji->sljedeci = novi;
        cout << "Unesi sifru robe: ";
            cin >> novi->sifra;
        cout << "Unesi cijenu: ";
            cin >> novi->cijena;
        cout << "Unesi kolicinu: ";
            cin >> novi->kolicina;
    }
    
    void ispis()
    {
        cstavka *trenutni;
        trenutni = this->sljedeci;
        while (trenutni)
        {
            cout << "Sifra: " << trenutni->sifra << endl;
            cout << "Cijena: " << trenutni->cijena << endl;
            cout << "Kolicina: " << trenutni->kolicina << endl;
            trenutni = trenutni -> sljedeci;
        }
    }
    
    cstavka *dealokacija()
    {
        cstavka *trenutni, *sljedeci;
        trenutni = this->sljedeci;
        if (trenutni) {
        
        sljedeci = trenutni->sljedeci;
        while (sljedeci)
        {
            delete trenutni;
            trenutni = sljedeci;
            sljedeci = sljedeci -> sljedeci;
        }
    
        
        delete trenutni;
        return NULL; }
    }
    double iznos()
    {
        cstavka *trenutni;
        trenutni = this->sljedeci;
        double suma;
        while (trenutni)
        {
            suma = suma + (trenutni->cijena * trenutni->kolicina);
            trenutni = trenutni->sljedeci;
        }
        
        return suma;
    }
};
 
cstavka *lista;
cstavka *polje;
 
int main()
{
    int izbor;
    do {
        cout << "1 ALOKACIJA/UNOS/ISPIS" << endl;
        cout << "2 IZNOS/DEALOKACIJA" << endl;
        cout << "3 ALOKACIJA" << endl;
        cout << "4 DEALOKACIJA SVIH VEZANIH I POLJA" << endl;
        cout << "Izbor: ";
            cin >> izbor;
        switch (izbor)
        {
            case 1: if (lista==NULL)
                    lista = new cstavka;
                    lista->unos();
                    lista->ispis();
                    break;
                    
            case 2: cout << "Ukupan iznos je:  " << lista->iznos() << endl;
                    lista = lista->dealokacija();
                    break;
            case 3: int N;
                    if (polje != NULL)
                        cout << "Polje je veæ alocirano! " << endl;
                    else
                    {
                        cout << "Unesi broj elemenata polja: ";
                            cin >> N;
                        polje = new cstavka [N];
                        
                    }
                    int pozicija;
                    cout << "Pozicija unosa u polje: ";
                        cin >> pozicija;
                    polje[pozicija].unos();
                    polje[pozicija].ispis();
                    break;
            case 4: for (int i = 0; i<N; i++)
                    {
                        polje[i].dealokacija();
                    }
                    delete [] polje;
                    polje = NULL;
                    break;
        }           
                    
    }while (izbor != 9);
    
    return 0;
}
