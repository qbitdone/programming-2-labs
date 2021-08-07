// KRISTIJAN ÈULINA 08.01.2020
#include <iostream>
#include <cstring>
using namespace std;
 
class cpredmeti_zapis {
    public:
        int sifra_predmeta;
        char naziv_predmeta[50];
        char naziv_smjera[50];
        
    void unos() 
    {
        cout << "Sifra: ";
            cin >> sifra_predmeta;
        cout << "Predmet: ";
            cin >> naziv_predmeta;
        cout << "Smjer: ";
            cin >> naziv_smjera;
    }
    void ispis()
    {
        cout << "Sifra: " << sifra_predmeta << endl;
        cout << "Predmet: " << naziv_predmeta << endl;
        cout << "Smjer: " << naziv_smjera << endl;
    }
};
 
class cpredmeti {
    public:
    cpredmeti *sljedeci;
    cpredmeti_zapis zapis; //po vrijednosti
};
 
class cprijave_zapis{
    public:
    int sifra_prijave;
    int sifra_predmeta;
    int mat_br;
    int rok;
    
    void unos(int sifra) 
    {
        cout << "Sifra prijave: ";
            cin >> sifra_prijave;
        cout << "Maticni broj: ";
            cin >> mat_br;
        cout << "Rok: ";
            cin >> rok;
        sifra_predmeta = sifra;
    }
    
    void ispis()
    {
        cout << "Sifra predmeta: " << sifra_predmeta << endl;
        cout << "Sifra prijave: " << sifra_prijave << endl;
        cout << "Maticni broj: " << mat_br << endl;
        cout << "Rok: " << rok << endl;
    }
    
};
 
class cprijave {
    public: 
    cprijave_zapis *zapis;
    cprijave *sljedeci;
    
    cprijave() {
        zapis = new cprijave_zapis;
        cout << "Konstruktor!" << endl;
    }
};
 
void zadatak1(cpredmeti *glava)
{   
    //unos
    cpredmeti *novi,*zadnji;
    zadnji = glava;
    while (zadnji->sljedeci)
        zadnji = zadnji->sljedeci;
    novi = new cpredmeti;
    novi->sljedeci = NULL;
    zadnji->sljedeci = novi;
    novi->zapis.unos();
    
    //ispis
    cpredmeti *trenutni;
    trenutni = glava->sljedeci;
    while (trenutni)
    {
        trenutni->zapis.ispis();
        trenutni = trenutni->sljedeci;
    }
        
}
 
void zadatak2(cpredmeti *glava) 
{
    cpredmeti *trenutni = glava->sljedeci;
    bool postoji = false;
    char trazeni_smjer[40];
    cout << "Unesite trazeni smjer: ";
        cin >> trazeni_smjer;
    while (trenutni)
    {
        if (strcmp(trazeni_smjer,trenutni->zapis.naziv_smjera) == 0)
        {
        postoji = true;
        trenutni->zapis.ispis(); 
        }
        
        trenutni = trenutni->sljedeci;
    }
        
    if (!postoji) cout << "Ne postoji element s tim smjerom! " << endl;
}
 
void zadatak3 (cprijave *glava,cpredmeti *glava2)
{
    cprijave *novi;
    cprijave *zadnji;
    zadnji = glava;
    cpredmeti *trenutni;
    trenutni = glava2->sljedeci;
    int sifra;
    bool postoji = false;
    cout << "Sifra predmeta: ";
        cin >> sifra;
    while (trenutni)
    {
        if (sifra == trenutni->zapis.sifra_predmeta)
        {
            postoji = true;
            break;
        }
        trenutni = trenutni->sljedeci;
    }
    if (!postoji)  
    { 
        cout << "Element ne postoji! " << endl;
        return;
    }
    while (zadnji->sljedeci)
        zadnji = zadnji->sljedeci;
    novi = new cprijave;
    novi->sljedeci = NULL;
    zadnji->sljedeci = novi;
    novi->zapis->unos(sifra);
}
 
void zadatak4(cprijave *glava,cpredmeti *glava2)
{
    int sifra;
    bool postoji = false;
    cout << "Unesi sifru predmeta: ";
        cin >> sifra;
    cpredmeti *trenutni = glava2 -> sljedeci;
    while (trenutni)
    {
        if (sifra == trenutni->zapis.sifra_predmeta)
        {
            trenutni->zapis.ispis();
            postoji = true;
            break;
        }
        trenutni = trenutni->sljedeci;
    }
    if (!postoji) 
    {
        cout << "Element ne postoji!" << endl;
        return ;
    }
    postoji = false;
    cprijave *trenutni2 = glava->sljedeci;
    while (trenutni2)
    {
        if (sifra == trenutni2->zapis->sifra_predmeta)
        {
            postoji = true;
            trenutni2->zapis->ispis();
            cout << "Pokazivac na sljedeci: " << trenutni2->sljedeci << endl;
            break;
        }
        trenutni2 = trenutni2->sljedeci;
    }
    
    if (!postoji) 
        cout << "Element nema prijava!" << endl;
}
 
int main(){
    int izbor;
    cpredmeti *predmeti_glava = new cpredmeti;
    predmeti_glava -> sljedeci=NULL;
    cprijave *prijave_glava = new cprijave;
    prijave_glava -> sljedeci=NULL;
    do{
        cout<<"1 UNOS PREDMETA I ISPIS CIJELE LISTE PREDMETA"<<endl;
        cout<<"2 PRETRAGA SMJERA"<<endl;
        cout<<"3 UNOS PRIJAVE"<<endl;
        cout<<"4 ISPIS LISTE PRIJAVA ZA ZADANI PREDMET"<<endl;
        cout<<"9 za izlaz"<<endl;
        cout<<"Izbor: ";
            cin >> izbor;
        switch(izbor){
            case 1:
            zadatak1(predmeti_glava);
            break;
            
            case 2:
            zadatak2(predmeti_glava);
            break;
            
            case 3:
            zadatak3(prijave_glava,predmeti_glava);
            break;
            
            case 4:
            zadatak4(prijave_glava,predmeti_glava);
            break;
            
            case 9:
            cout << "IZLAZ!" << endl;
            break;
        } 
        cout<<"---------------------"<<endl;
    }while(izbor != 9);
    system("pause");
    return 0;
}
