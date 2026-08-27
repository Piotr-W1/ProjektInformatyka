#include <iostream>
#include <random>
using namespace std;
int odkryjPole (int wiersz, int kolumna, char t[8][8], bool miny[8][8], int &odkrytePola){
    int sasiadMina = 0;
    if (t[wiersz-1][kolumna-1] != '.'){
        return 0;
    } 
    
    if (wiersz > 1){
if (miny[wiersz-2][kolumna-1] == true){
    sasiadMina++;
}
}
if (wiersz < 8){
    if (miny[wiersz][kolumna-1] == true){
    sasiadMina++;
    }
    }
    
if (kolumna>1){
if (miny[wiersz-1][kolumna-2] == true){
    sasiadMina++;
}
}
if (kolumna<8){
if (miny[wiersz-1][kolumna] == true){
    sasiadMina++;
}
}

if (wiersz>1 && kolumna>1){
if (miny[wiersz-2][kolumna-2] == true){
    sasiadMina++;
}
}
if (wiersz>1 && kolumna<8){
if (miny[wiersz-2][kolumna] == true){
    sasiadMina++;
}
}
if (wiersz<8 && kolumna>1){
if (miny[wiersz][kolumna-2] == true){
    sasiadMina++;
}
}
if (wiersz<8 && kolumna<8){
if (miny[wiersz][kolumna] == true){
    sasiadMina++;
}
}
t[wiersz-1][kolumna-1] = '0' + sasiadMina;
odkrytePola++;

if (sasiadMina==0){
    if (wiersz > 1){
        if (miny[wiersz-2][kolumna-1]==false){
    odkryjPole(wiersz-1, kolumna, t, miny, odkrytePola); 
        
}
}
if (wiersz < 8){
    if (miny[wiersz][kolumna-1] == false){
   odkryjPole(wiersz+1, kolumna, t, miny, odkrytePola);
   
}
}
if (kolumna > 1){
    if (miny[wiersz-1][kolumna-2] == false){
   odkryjPole(wiersz, kolumna-1, t, miny, odkrytePola);
   
}
}
if (kolumna < 8 ){
    if (miny[wiersz-1][kolumna] == false){
   odkryjPole(wiersz, kolumna+1, t, miny, odkrytePola);
   
}
}
if (wiersz>1 && kolumna>1){
if (miny[wiersz-2][kolumna-2] == false){
    odkryjPole (wiersz-1, kolumna-1, t, miny, odkrytePola);
    
}
}
if (wiersz>1 && kolumna<8){
if (miny[wiersz-2][kolumna] == false){
    odkryjPole (wiersz-1, kolumna+1, t, miny, odkrytePola);
    
}
}
if (wiersz<8 && kolumna>1){
if (miny[wiersz][kolumna-2] == false){
    odkryjPole (wiersz+1, kolumna-1, t, miny, odkrytePola);
    
}
}
if (wiersz<8 && kolumna<8){
if (miny[wiersz][kolumna] == false){
    odkryjPole (wiersz+1, kolumna+1, t, miny, odkrytePola);
    
}
}

}
return sasiadMina;
}

int main() {
char t[8][8];
bool miny[8][8];
int wMiny, kMiny;
int liczbaMin = 0;
bool gra = true;
int wiersz, kolumna;
int odkrytePola = 0;
random_device rd;
mt19937 generator(rd());
uniform_int_distribution<int> losowanie(1,8);

cout << "Saper" <<  endl;
cout << "Piotr Waclawski" << endl;
for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
        t[i][j] = '.';
        miny[i][j] = false;
    }
}
while (liczbaMin<10) {
wMiny = losowanie(generator);
kMiny = losowanie(generator);
    if (miny[wMiny-1][kMiny-1] == false){
    miny[wMiny-1][kMiny-1] = true;
    liczbaMin++;
    }
}

cout << "  ";
for (int i = 0; i < 8; i++) {
        cout << i+1 << " ";
}
cout<< endl;
for (int i = 0; i < 8; i++) {
    cout << i+1 << " ";
    for (int j = 0; j < 8; j++) {
        cout << t[i][j] << " ";
    }
    cout << endl;
}
while (gra == true){
do {
cout << "Podaj wiersz: ";
cin >> wiersz;
cout << "\nPodaj kolumne: ";
cin >> kolumna;
cout << endl;
if (wiersz < 1 || wiersz > 8 || kolumna < 1 || kolumna > 8){
cout << "Wpisano nieprawidlowe dane. Wpisz wiersz i kolumne w zakresie od 1 do 8" << endl;}
else if (t[wiersz-1][kolumna-1] != '.') {
    cout << "Wskazane pole zostalo juz wybrane." << endl;
}
}while (wiersz < 1 || wiersz > 8 || kolumna < 1 || kolumna > 8 || t[wiersz-1][kolumna-1] != '.' );
cout << "Wybrales: " << wiersz << " " << kolumna << endl;

if (miny[wiersz-1][kolumna-1] == true) {
    t[wiersz-1][kolumna-1] = 'O';
    
cout << "Trafiles na mine!" << endl;
gra = false;
}

   else {
    odkryjPole(wiersz, kolumna, t, miny, odkrytePola);
}
if (odkrytePola == 54) {
            cout << "Odkryles wszystkie pola bez min. Wygrales!" << endl;
            gra = false;

}


cout << "  ";
for (int i = 0; i < 8; i++) {
        cout << i+1 << " ";
}
cout<< endl;
for (int i = 0; i < 8; i++) {
    cout << i+1 << " ";
    for (int j = 0; j < 8; j++) {
        cout << t[i][j] << " ";
    }
    cout << endl;
}
}
return 0;
}


