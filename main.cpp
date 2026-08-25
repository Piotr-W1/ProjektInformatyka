#include <iostream>
#include <random>
using namespace std;

int main() {
char t[8][8];
bool miny[8][8];
int wMiny, kMiny;
int liczbaMin = 0;
bool gra = true;
int wiersz, kolumna;
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
cout << "Podaj wiersz: ";
cin >> wiersz;
cout << "\nPodaj kolumne: ";
cin >> kolumna;
cout << endl;
cout << "Wybrales: " << wiersz << " " << kolumna << endl;
if (miny[wiersz-1][kolumna-1] == true) {
    t[wiersz-1][kolumna-1] = 'O';
    
cout << "Trafiles na mine!" << endl;
gra = false;
}
else {t[wiersz-1][kolumna-1] = 'X';
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
