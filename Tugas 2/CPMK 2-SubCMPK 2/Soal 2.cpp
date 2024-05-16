#include <iostream>
using namespace std;

void bubbleSort(int angka[], int n) {
    for (int i = 0; i < n-1; i++) {
        bool tukar = false;
        for (int j = 0; j < n-i-1; j++) {
            if (angka[j] > angka[j+1]) {
                int a = angka[j];
                angka[j] = angka[j+1];
                angka[j+1] = a;
                tukar = true;
            }
        }
        if (!tukar) break;
    }
}

void printAngka(int angka[], int size) {
    for (int i = 0; i < size; i++)
        cout << angka[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Masukkan banyak angka: ";
    cin >> n;
    int angka[n];
    cout << "Masukkan " << n << " angka:\n";
    for (int i = 0; i < n; i++) {
        cout << "Angka ke-" << i + 1 << ": ";
        cin >> angka[i];
    }
    cout << "Angka sebelum diurutkan: \n";
    printAngka(angka, n);
    bubbleSort(angka, n);
    cout << "Angka setelah diurutkan: \n";
    printAngka(angka, n);
    return 0;
}