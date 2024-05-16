#include <iostream>
using namespace std;

void bubbleSort(string& str) {
    int n = str.length();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (str[j] > str[j + 1]) {
                // Tukar huruf
                std::swap(str[j], str[j + 1]);
                swapped = true;
            }
        }
        // Jika tidak ada huruf yang ditukar, berarti sudah terurut
        if (!swapped) break;
    }
}

bool cekAnagram(string kata1, string kata2){
    if(kata1.length() != kata2.length()){
        return false;
    }
    bubbleSort(kata1);
    bubbleSort(kata2);
    return kata1==kata2;
}

int main() {
    string kata1, kata2;
    cout << "Masukkan kata pertama: ";
    cin >> kata1;
    cout << "Masukkan kata kedua ";
    cin >> kata2;
    if (cekAnagram(kata1,kata2)){
        cout << "Kata pertama dan kedua adalah anagram\n";
    } else{
        cout << "Kata pertama dan kedua bukan anagram\n";
    }
    return 0;
}