#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool checkDuplicates(string arr[], int n) {
    sort(arr, arr + n);
    
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] == arr[i + 1]) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Masukkan jumlah kata: ";
    cin >> n;
    string* kata = new string[n];
    cout << "Masukkan kata-kata: \n";
    for (int i = 0; i < n; ++i) {
        cin >> kata[i];
    }
    
    if (checkDuplicates(kata, n)) {
        cout << "Terdapat duplikasi dalam array." << endl;
    } else {
        cout << "Tidak terdapat duplikasi dalam array." << endl;
    }
    
    delete[] kata;
    return 0;
}