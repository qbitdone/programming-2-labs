#include <iostream>
#include <fstream>
#include "biblioteka_vrijeme.cc"
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cstring>
 
using namespace std;
 
 
struct element_dat
{
    int sifra;
    char naziv[60];
    char smjer[60];
    double vrijeme;
};
 
 
struct element_lista
{
    int sifra;
    char naziv[60];
    char smjer[60];
    double vrijeme;
    element_lista *sljedeci;
    
};
 
fstream dat;
element_dat student;
 
 
void unos() {
    vrijeme_pocetak();
    cout << "Sifra: ";
        cin >> student.sifra;
    cout << "Naziv: ";
        cin >> student.naziv;
    cout << "Smjer: ";
        cin >> student.smjer;
    vrijeme_kraj();
    student.vrijeme = vrijeme_proteklo()/1000;
    dat.open("kculina.dat", ios::out | ios::app | ios::binary);
    dat.write((char *) &student, sizeof(student));
    dat.close();
    cout << endl;
    
}
 
void generiranje() {
    srand(time(NULL));
    rand();
    dat.open("kculina.dat", ios::out | ios::app | ios::binary);
    int N;
    cout << "Koliko zapisa zelite generirati: ";
        cin >> N;
    cout << "Generirane sifre studenata su: " << endl;
    for (int i = 0; i<N; i++)
    {
        student.vrijeme = 0;
        student.sifra = rand()% 10000;
        for (int j = 0; j<15; j++) student.naziv[j] = char(rand()%25 + 97);
        for (int a = 0; a<15; a++) student.smjer[a] = char(rand()%25 + 97);
        dat.write ((char *) &student, sizeof(student));
        cout << student.sifra  << "  ";
        
    }
    dat.close();
    cout << endl;
}
 
void dealokacija_liste(element_lista *lista){
    element_lista *trenutni, *sljedeci;
    trenutni = lista->sljedeci;
    sljedeci = trenutni->sljedeci;
    
    while(sljedeci){
        delete trenutni;
        trenutni = sljedeci;
        sljedeci = sljedeci->sljedeci;
    };
 
    lista->sljedeci = NULL;
}; 
 
void kopiranje(element_lista *lista) {
    element_lista *novi,*zadnji;
    zadnji = lista;
    dat.open("kculina.dat", ios::in | ios::binary);
    if (lista->sljedeci) dealokacija_liste(lista);
    cout << "Primarni kljucevi: " << endl;
    while (true)
    {
        dat.read((char *) &student, sizeof(student));
        if (dat.eof()) break;
        novi = new element_lista;
        novi->sljedeci = NULL;
        zadnji->sljedeci = novi;
        novi->sifra = student.sifra;
        novi->vrijeme = student.vrijeme;
        strcpy(novi->naziv,student.naziv);
        strcpy(novi->smjer,student.smjer);
        zadnji = novi;
        cout << novi->sifra << "  ";
        
     }
     dat.close();
     cout << endl; 
}
void ispis(element_lista *lista) {
 
    element_lista *trenutni;
    trenutni = lista->sljedeci;
    while (trenutni) {
        cout << "Sifra: " << trenutni->sifra << endl;
        cout << "Naziv: " << trenutni->naziv << endl;
        cout << "Smjer: " << trenutni->smjer << endl;
        cout << "Vrijeme: " << trenutni->vrijeme << endl;
        trenutni = trenutni->sljedeci;
        cout << endl;
    }
    cout << endl;
}
 
int main()
{
    element_lista *lista = new element_lista;
    remove("kculina.dat");
    lista -> sljedeci = NULL;
    int izbor;
    do{
        cout << "---IZBORNIK---" << endl;
        cout << "1. Rucni unos u datoteku" << endl;
        cout << "2. Generiranje novih sadrzaja" << endl;
        cout << "3. Kopiranje sadrzaja datoteke u vezanu listu" << endl;
        cout << "4. Ispis vezane liste" << endl;
        cout << "9. Izlaz iz programa" << endl;
        cout << "\nVas izbor: "; cin >> izbor;
        
        switch(izbor){
            case 1: unos(); break;
            case 2: generiranje(); break;
            case 3: kopiranje(lista); break;
            case 4: ispis(lista); break;
            case 9: cout << "Kraj"; break;
            default: cout << "\nPogresan unos" << endl << endl;
        };
    } while(izbor!=9);
    system ("pause");
    return 0;
}
