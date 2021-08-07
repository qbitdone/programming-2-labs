#include <iostream>
#include "biblioteka_vrijeme.cc";
#include <cmath>
#include <iomanip>
 
using namespace std;
 
class ctrokut 
{
private:
    float s;
    cvrijeme vrijeme;
    
public:
    static int brojac;
    char naziv[60];
    float a,b,c;
    
float povrsina()
{
if (a+b < c || a+c < b || b+c < a)
    return -1;
s = (a+b+c) / 2;
float p;
p = sqrt(s*(s-a)*(s-b)*(s-c));
return p;
}
 
void unos()
{
vrijeme.pocetak();
cout << "Naziv: ";
    cin >> naziv;
cout << "A: ";
    cin >> a;
cout << "B: ";
    cin >> b;
cout << "C: ";
    cin >> c;
vrijeme.kraj();
vrijeme.proteklo();
}
void ispis()
{
if (povrsina() > -1) cout << "Naziv: " << naziv << " Stranice: " << a << " " << b << " " << c << " Povrsina: " << povrsina() << endl;
else cout << "Stranice ne èine trokut! " << endl;
cout << "Vrijeme: " << vrijeme.proteklo()/1000 << endl;
}
 
bool pravokutni()
{
if (pow(a,2) + pow(b,2) == pow(c,2)) 
    return true;
else return false;
}
};
int ctrokut::brojac = 0;
int main()
{
int izbor;
double zbr_pov = 0;
int br_cini = 0;
int br_ne_cini = 0;
ctrokut trokut[100];
do {
cout << "Unesi izbor: ";
    cin >> izbor;
switch(izbor)
{
case 1: trokut[ctrokut::brojac].unos();
                        ctrokut::brojac++;
                        break;
case 2: for ( int i = 0; i < ctrokut::brojac; i++)
                        trokut[i].ispis();
                        break;
case 3: for (int i = 0; i < ctrokut::brojac; i++)
                        {
                        if (trokut[i].povrsina() > -1)
                        {
                        br_cini ++;
                        zbr_pov = zbr_pov + trokut[i].povrsina();
                        }
                        else
                        br_ne_cini++;
                        }
                        
                        cout << "Ukupan broj unosa: " << ctrokut::brojac << endl;
                        cout << "Ukupan broj koji ne cini: " << br_ne_cini << endl;
                        cout << "Ukupan broj koji cini trokut: " << br_cini << endl;
                        cout << "Zbroj povrsina koji cine trokut: " << zbr_pov << endl;
                        break;
                        
case 4: for ( int i = 0; i < ctrokut::brojac; i++)
                        if (trokut[i].pravokutni())
                        trokut[i].ispis();
                        break;
}
}while(izbor != 9);
system("pause");
return 0;
}
