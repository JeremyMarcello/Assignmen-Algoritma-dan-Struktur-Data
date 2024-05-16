#include <iostream>
#include <string>

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
    const int max = 100;
    string kata[max];
    int n;
    cout << "Masukkan jumlah kata: ";
    cin >> n;
    cout << "Masukkan kata-kata dengan string kosong dipisahkan dengan spasi, maksimal " << n << " kata: \n";
    for (int i = 0; i < n; ++i) {
        cin >> kata[i];
    }
    string diCari;
    cout << "Masukkan kata yang ingin dicari: ";
    cin >> diCari;

    int hasil = linearSearch(kata, n, diCari);

    if (hasil != -1) {
        cout << "Kata ditemukan pada array ke-: " << hasil << endl;
    } else {
        cout << "Kata tidak ditemukan." << endl;
    }

    return 0;
}
