#include <iostream>
using namespace std;

int main() {
char t[8][8];
cout << "Saper" <<  endl;
cout << "Piotr Waclawski" << endl;
for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
        t[i][j] = '.';
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
int wiersz, kolumna;
cout << "Podaj wiersz: ";
cin >> wiersz;
cout << "\nPodaj kolumne: ";
cin >> kolumna;
cout << endl;
cout << "Wybrales: " << wiersz << " " << kolumna << endl;
t[wiersz-1][kolumna-1] = 'X';
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
return 0;
}
