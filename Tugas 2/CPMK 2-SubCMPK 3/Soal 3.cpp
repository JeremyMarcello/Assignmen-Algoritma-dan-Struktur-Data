#include <iostream>
using namespace std;

int linearSearch(string kata[], int n, const string& diCari) {
    for (int i = 0; i < n; ++i) {
        if (kata[i] == "") {
            continue;
        }
        if (kata[i] == diCari) {
            return i;
        }
    }
    return -1;
}

int main() {
    string kata[] = {"Adi", "", "", "", "bermain", "", "bola", "", "", "sedang"};
    int size = sizeof(kata) / sizeof(kata[0]);
    string diCari = "bola";

    int hasil = linearSearch(kata, size, diCari);

    if (hasil != -1) {
        cout << "Kata ditemukan pada array ke-: " << hasil << endl;
    } else {
        cout << "Kata tidak ditemukan." << endl;
    }

    return 0;
}