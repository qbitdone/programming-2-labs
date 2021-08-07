#include <iostream>
#include <fstream>
#include "biblioteka_vrijeme.cc"
#include <cmath>
#include <cstdlib>
 
using namespace std;
 
 
struct element {
    int sifra;
    char naziv[60];
    char smjer[50];
    int vrijeme;
    int red_br;
    
};
 
element student,student1;
fstream objekt;
int prost_broj;
 
 
int prvi_prost(int x){
    int prost;         
    for (int i=x-1;i>1;i--){
        prost = 1;
        for (int j=2;j<=sqrt(i);j++){
            if(i%j==0){
                prost = 0;
                break;
            }
        }
        if (prost) return i;
    }
    return 0;
}
 
void kreiranje_datoteke() {
    int velicina_dat;
    student.sifra = 0;
    student.naziv[0] = '\0';
    student.smjer[0] = '\0';
    student.vrijeme = 0;
    cout << "Unesite velicinu datoteke: ";
        cin >> velicina_dat;
    prost_broj = prvi_prost(velicina_dat);
    cout << "Prvi manji prost broj je: " << prost_broj << endl;
    objekt.open("kculina.dat", ios::out | ios::binary);
    for (int i = 0; i<velicina_dat; i++) {
        student.red_br = i;
        objekt.write((char *) &student, sizeof(element));
    }
    objekt.close();
}
 
void unos_datoteke() {
    vrijeme_pocetak();
    cout << "Sifra: ";
        cin >> student.sifra;
    cout << "Naziv: ";
        cin >> student.naziv;
    cout << "Smjer: ";
        cin >> student.smjer;
    vrijeme_kraj();
    student.vrijeme = vrijeme_proteklo()/1000;
    int rbz;
    rbz = student.sifra%prost_broj;
    objekt.open("kculina.dat", ios::in | ios::out | ios::binary);
    objekt.seekg(rbz * sizeof(element));
    do {
        objekt.read((char *) &student1, sizeof(element));   
    } while(student1.sifra > 1);
    rbz = (objekt.tellg()/sizeof(element)) -1;
    objekt.seekp(rbz*sizeof(element));
    student.red_br = student1.red_br;
    objekt.write((char *)&student, sizeof(element));
    objekt.close();
}
 
 
void pretrazivanje() {
    int rbz;
    int pronadjeno = 0;
    int sifra;
    cout << "Unesi sifru koju zelis pretraziti: ";
        cin >> sifra;
    objekt.open("kculina.dat", ios::in | ios::binary);
    rbz = sifra%prost_broj;
    objekt.seekg(rbz * sizeof(element));
    do {
        objekt.read((char *) &student ,sizeof(element));
        if (objekt.eof()) break;
        if (student.sifra == sifra)
       {
        pronadjeno = 1;
        cout << "Sifra: " << student.sifra << endl;
        cout << "Naziv: " << student.naziv << endl;
        cout << "Smjer: " << student.smjer << endl;
        cout << "Redni broj: " << student.red_br << endl;
        cout << "Vrijeme: " << student.vrijeme << endl; 
        break;
        }
    } while(student.sifra > 0); 
    if (pronadjeno == 0) cout << "Nije pronadjen u datoteci!! " << endl;
    objekt.close();
        
}
 
void statistika() {
int suma = 0;
int br_praznih = 0;
int br_zapisa = 0;
objekt.open("kculina.dat", ios::in | ios::binary);
while (1) {
 
    objekt.read((char *) &student, sizeof(student));
    if (objekt.eof()) break;
    if (student.sifra == 0) br_praznih++;
    if (student.sifra != 0) {
     br_zapisa++;
     suma = suma + student.sifra;
}   }
cout << "Broj praznih zapisa: " << br_praznih << endl;
cout << "Broj zapisa: " << br_zapisa << endl;
cout << "Suma sifri: " << suma;
objekt.close();
 
 
 
}
int main(){
    int izbor;
    do{
        cout << "1.Kreiranje datoteke praznih zapisa i racunanje prostog broja" << endl;
        cout << "2.Unos podataka u datoteku(uvazavajuci duplikate)" << endl;
        cout << "3.Pretrazivanje relativne datoteke uz prepoznavanje duplikata" << endl;
        cout << "4.Statistika" << endl;
        cout << "9.Izlaz iz programa" << endl;
        cout << "Unesite odabir: "; cin >> izbor; cout << endl;
        switch(izbor){
            case 1: kreiranje_datoteke(); cout << endl; break;
            case 2: unos_datoteke(); cout << endl; break;
            case 3: pretrazivanje(); cout << endl; break;
            case 4: statistika(); cout << endl; break;
            case 9: cout << "Izlaz iz programa!" << endl; break;
        }
    }while(izbor != 9);
    
    system("pause");
    return 0;
}
