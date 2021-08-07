#include <iostream>
#include <fstream>
#include "biblioteka_vrijeme_i_binarno_pretrazivanje.cc"
#include <iomanip>
 
using namespace std;
 
struct element 
{
    int sifra;
    char naziv[60];
    char smjer[60];
    double vrijeme;
};
 
element student;
fstream dat, ind;
tindeks indeks;
 
int brojac = 0;
int zbroj = 0;
int maxi = 0;
 
void unos()
{
    do { 
    
        vrijeme_pocetak();
        cout << "Sifra: "; cin >> student.sifra;
        cout << "Naziv: "; cin >> student.naziv;
        cout << "Smjer: "; cin >> student.smjer;
        vrijeme_kraj();
        student.vrijeme = vrijeme_proteklo()/1000;
        if (student.vrijeme < 5) 
                cout << "Unos se poništava jer traje kraæe od 5 sekundi!" << endl;
                
    } while(student.sifra < 5);
    indeks.kljuc = student.sifra;
    indeks.adresa = brojac * sizeof(student);
    dat.open("dat.dat", ios::out | ios::app | ios::binary);
    dat.write((char *) &student, sizeof(student));
    dat.close(); dat.clear();
    ind.open("ind.ind", ios::out | ios::app | ios::binary);
    ind.write((char *) &indeks, sizeof(indeks));
    ind.close(); ind.clear();
    brojac ++;
    zbroj = zbroj + student.sifra;
    if (student.sifra > maxi) maxi = student.sifra;
    preslozi_indeks("ind.ind", indeks);
    
}
 
void ispis()
{
    dat.open("dat.dat", ios::in | ios::binary);
    ind.open("ind.ind", ios::in | ios::binary);
    while (true)
    {
        ind.read((char *) &indeks, sizeof(indeks));
        if (ind.eof()) break;
        dat.seekg(indeks.adresa);
        dat.read((char *) &student, sizeof(student));
        cout << "Sifra: " << student.sifra << endl;
        cout << "Naziv: " << student.naziv << endl;
        cout << "Smjer: " << student.smjer << endl;
        cout << "Vrijeme: " << student.vrijeme << endl;
        cout << endl;
    }
    
    dat.close(); dat.clear();
    ind.close(); ind.clear();
}
 
void pretraga()
{
    dat.open("dat.dat", ios::in | ios::binary);
    ind.open("ind.ind", ios::in | ios::binary);
    int sifra;
    cout << "Unesi sifru po kojoj zelite pretraziti datoteku: ";
        cin >> sifra;
    bool pronadjen = false;
    while (true)
    {
        ind.read((char *) &indeks, sizeof(indeks));
        if (ind.eof()) break;
        dat.seekg(indeks.adresa);
        dat.read((char *) &student, sizeof(student));
        if (sifra == student.sifra) {
        pronadjen = true;
        cout << "Sifra: " << student.sifra << endl;
        cout << "Naziv: " << student.naziv << endl;
        cout << "Smjer: " << student.smjer << endl;
        cout << "Vrijeme: " << student.vrijeme << endl;
        cout << endl;
        break; }
        
    }
    dat.close();
    ind.close();
    if (!pronadjen) cout << "Korisnik s tom sifrom se ne nalazi u datoteci!" << endl;
}
 
void statistika() 
{
    cout << "Aritmeticka sredina: " << zbroj/brojac << endl;
    cout << "Zbroj: " << zbroj << endl;
    cout << "Najveca sifra: " << maxi << endl;
}
 
int main()
{   
 
    int izbor;
    do {
        cout << "1 UNOS" << endl;
        cout << "2 ISPIS"   << endl;
        cout << "3 PRETRAGA" << endl;
        cout << "4 STATISTIKA"  << endl;
        cout << "-------------" << endl;
        cout << "Vas izbor: " << endl;
            cin >> izbor;
        switch(izbor) {
            case 1: unos(); break;
            case 2: ispis(); break;
            case 3: pretraga(); break;
            case 4: statistika(); break;
        }
    } while (izbor != 9);
    system("pause");
    return 0;
}
