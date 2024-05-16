#include <iostream>
using namespace std;

void gabungArray(int A[], int m, int B[], int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    while (i >= 0 && j >= 0) {
        if (A[i] > B[j]) {
            A[k--] = A[i--];
        } else {
            A[k--] = B[j--];
        }
    }
}

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

int main(){
    int A[10]= {3,1,5,2,6};
    int B[]= {7,4,9,8};
    int m = 5;
    int n = 4;
    cout << "Array A sebelum digabung: ";
    printAngka(A,m);
    cout << "Array A sebelum digabung: ";
    printAngka(B,n);
    gabungArray(A, m, B, n);
    cout << "Array A dan B setelah digabung dan belum diurutkan: ";
    printAngka(A, m+n);
    bubbleSort(A, m+n);
    cout << "Array A dan B setelah digabung dan sudah diurutkan: ";
    printAngka(A, m+n);
    return 0;
}