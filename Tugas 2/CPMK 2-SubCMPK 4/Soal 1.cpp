#include  <iostream>
using namespace std;

struct dataMahasiswa{
    string nama;
    int umur;
    string nim;
};

int main(){
    dataMahasiswa mhs1;
    dataMahasiswa mhs2;
    cout << "Masukkan nama mahasiswa pertama: ";
    getline(cin, mhs1.nama);
    cout << "Masukkan umur mahasiswa pertama: ";
    cin >> mhs1.umur;
    cout << "Masukkan nim mahasiswa pertama: ";
    cin >> mhs1.nim;

    cout << "\nData Mahasiswa:\n";
    cout << "Nama: " << mhs1.nama << endl;
    cout << "Usia: " << mhs1.umur << endl;
    cout << "NIM : " << mhs1.nim<< endl;

    return 0;
}