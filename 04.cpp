#include <iostream>
#include <fstream>
#include "biblioteka_vrijeme.cc"
 
using namespace std;
 
// kod binarnih out je upis a in je èitanje iz njih !!
 
struct element {
    int sifra;
    char naziv[60];
    int br_kom;
    int vrijeme;
};
element student;
fstream objekt;
    
void unos() {
    
    objekt.open ("krculina.dat",ios::in | ios::binary);
    int pom_sifra;
    bool postoji = false;
    cout << "Unesi sifru: ";
        cin >> pom_sifra;
    while (true) 
    {
        objekt.read((char *) &student, sizeof(student));
        if (objekt.eof()) break;
        if (pom_sifra==student.sifra) postoji = true;
    }
    objekt.close();
    
    
    if (!postoji) {
    objekt.open ("krculina.dat", ios::out | ios::app | ios::binary);
    vrijeme_pocetak();
    student.sifra = pom_sifra;
    cout << "Unesi naziv: ";
        cin >> student.naziv;
    cout << "Unesi broj komada: ";
        cin >> student.br_kom;
    vrijeme_kraj();
    student.vrijeme = vrijeme_proteklo()/1000;
    cout << "Vrijeme potrebno za upis je: " << student.vrijeme << endl;
    objekt.write((char *) &student, sizeof(student));
    objekt.close(); }
    
    if(postoji) 
        cout << "Korisnik s tom šifrom veæ postoji u datoteci!" << endl;
}
 
void ispis() {
    
    objekt.open ("krculina.dat", ios::in | ios::binary);
    while (1)
    {
        objekt.read((char *) &student, sizeof(student));
        if (objekt.eof()) break;
        cout << "Sifra: " << student.sifra << endl;
        cout << "Naziv: " << student.naziv << endl;
        cout << "Broj komada: " << student.br_kom << endl;
        cout << "Vrijeme: " << student.vrijeme << endl;
        cout << endl;
    }
    objekt.close();
}
void pretraga() 
{
    int pretraga;
    int brojac = 0;
    cout << "Unesi pretragu: ";
        cin >> pretraga;
    objekt.open("krculina.dat", ios::in | ios::binary);
    while (1)
    {
        objekt.read((char *) &student, sizeof(student));
        if(objekt.eof()) break;
        if (pretraga==student.sifra) {
        cout << "Sifra: " << student.sifra << endl;
        cout << "Naziv: " << student.naziv << endl;
        cout << "Broj komada: " << student.br_kom << endl;
        cout << "Vrijeme: " << student.vrijeme << endl;
        brojac++;
        cout << endl; }
    }
    if (brojac==0) cout << "Korisnik sa zadanom šifrom ne postoji!" << endl;
    objekt.close();
    
    
}
int main() 
{
    int izbor;
    do {
        cout << "IZBORNIK!" << endl;
        cout << "Unesi 1 za unos podataka u datoteku" << endl;
        cout << "Unesi 2 za ispis podataka iz datoteke" << endl;
        cout << "Unesi 3 za pretragu datoteke" << endl;
        cout << "----------------------------------" << endl;
        cout << "Vaš izbor: ";
            cin >> izbor;
        switch(izbor) {
            case 1: unos(); break;
            case 2: ispis(); break;
            case 3: pretraga(); break;
        }
    } while(izbor !=9);
    system ("pause");
    return 0;
}
