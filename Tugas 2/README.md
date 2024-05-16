# <h1 align="center">Tugas 2 Struktur Data</h1>

<p align="center">Jeremy Marcello Waani / 2311110003 / S1SD04-A</p>

## CPMK 2 – SubCPMK 2


### **1. Penjelasan Alur dan Runtime Algoritma Sorting:**

* **Bubble Sort:**

    * **Alur:** Membandingkan elemen berpasangan dan menukarnya jika urutannya salah, diulang hingga seluruh array terurut.
    * **Best Case:** O(n) - Array sudah terurut, hanya satu iterasi tanpa pertukaran.
    * **Worst Case:** O(n^2) - Array terbalik, n iterasi penuh dengan n pertukaran per iterasi.

* **Selection Sort:**

    * **Alur:** Mencari elemen terkecil di bagian yang tidak terurut, menukarnya dengan elemen pertama, diulang hingga seluruh array terurut.
    * **Best Case:** O(n^2) - Tetap membutuhkan n(n-1)/2 perbandingan.
    * **Worst Case:** O(n^2) - Tetap membutuhkan n(n-1)/2 perbandingan.

* **Merge Sort:**

    * **Alur:** Membagi array menjadi dua bagian, mengurutkan rekursif, dan menggabungkan bagian yang terurut.
    * **Best Case:** O(n log n) - Pembagian dan penggabungan memerlukan O(log n).
    * **Worst Case:** O(n log n) - Pembagian dan penggabungan memerlukan O(log n).

### **2. Program Bubble Sort**

```c++
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
```

**OUTPUT:** ![Cuplikan layar dari 2024-05-16 20-32-46](https://github.com/JeremyMarcello/Assignment-Algoritma-dan-Struktur-Data/assets/156126843/20f15aee-09d0-4c92-b072-85093fe59bc5)

**Penjelasan Program:** Program ini mengimplementasikan algoritma Bubble Sort untuk mengurutkan array `angka`. Fungsi `bubbleSort` akan membandingkan dan menukar elemen jika tidak dalam urutan yang benar. Fungsi `printAngka` digunakan untuk mencetak array yang terurut.

### **3. Program Cek Anagram**

```c++
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
```
**OUTPUT:**![Cuplikan layar dari 2024-05-16 21-13-22](https://github.com/JeremyMarcello/Assignment-Algoritma-dan-Struktur-Data/assets/156126843/a1662dc9-378c-4986-98b3-182ea61f6f72)

### **4. Program Menggabungkan Dua Array**

```cpp
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
```
**OUTPUT:**![Cuplikan layar dari 2024-05-16 21-51-28](https://github.com/JeremyMarcello/Assignment-Algoritma-dan-Struktur-Data/assets/156126843/313c9096-b71e-4c89-9b64-bc691f2f21f1)

## CPMK 2 – SubCPMK 3

### **1. Penjelasan Alur dan Runtime Algoritma Searching**

* **Binary Search**
    * **Alur:** Binary Search bekerja pada array yang sudah diurutkan. Algoritma ini mencari elemen yang dituju dengan membagi array menjadi dua bagian. Pertama, algoritma membandingkan elemen tengah array dengan elemen yang dicari. Jika elemen tengah adalah elemen yang dicari, pencarian selesai. Jika elemen tengah lebih besar dari elemen yang dicari, maka pencarian dilanjutkan pada bagian kiri array. Sebaliknya, jika elemen tengah lebih kecil, maka pencarian dilanjutkan pada bagian kanan array. Proses ini diulang terus pada bagian array yang sesuai sampai elemen ditemukan atau bagian array yang dicari habis.
    * **Best Case:** O(1) - terjadi ketika elemen tengah adalah elemen yang dicari. Hanya butuh satu perbandingan.
    * **Worst Case:** O(log n) - terjadi ketika harus membagi array sampai hanya tersisa satu elemen. Ini karena setiap kali array dibagi menjadi dua bagian, sehingga kompleksitasnya adalah logaritmik terhadap ukuran array.

* **Linear Search**
    * **Alur:** Linear Search mencari elemen dengan memeriksa setiap elemen dalam array satu per satu dari awal hingga akhir. Algoritma ini membandingkan elemen yang dicari dengan setiap elemen dalam array secara berurutan. Jika ditemukan elemen yang sesuai, pencarian selesai. Jika mencapai akhir array tanpa menemukan elemen yang dicari, maka elemen tersebut tidak ada dalam array.
    * **Best Case:** O(1) - terjadi ketika elemen yang dicari adalah elemen pertama dalam array. Hanya butuh satu perbandingan.
    * **Worst Case:** O(n) - terjadi ketika elemen yang dicari berada di akhir array atau tidak ada dalam array. Dalam kasus terburuk, setiap elemen dalam array harus diperiksa sekali.

### **2. Program Binary Search**

```c++
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
```
**OUTPUT:**![Cuplikan layar dari 2024-05-16 22-19-45](https://github.com/JeremyMarcello/Assignment-Algoritma-dan-Struktur-Data/assets/156126843/0e3f270a-979c-40f8-bcca-6220d3f63ab3)

   **Penjelasan Program:** Program ini mengimplementasikan algoritma Linear Search untuk mencari kata dalam array string. Pengguna diminta memasukkan jumlah kata yang akan diinput dan kata-kata tersebut, dengan batas maksimal 100 kata. Pengguna juga diminta memasukkan kata yang ingin dicari. Fungsi `linearSearch` kemudian memeriksa setiap elemen dalam array untuk menemukan kata yang sesuai, mengabaikan string kosong, dan mengembalikan indeks kata jika ditemukan, atau `-1` jika tidak ditemukan. Hasil pencarian ditampilkan dengan mencetak posisi kata dalam array atau pesan bahwa kata tidak ditemukan.

3. **Program Mencari Kata dalam Array dengan String Kosong**

```c++
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
```
**OUTPUT:**![Cuplikan layar dari 2024-05-16 22-20-00](https://github.com/JeremyMarcello/Assignment-Algoritma-dan-Struktur-Data/assets/156126843/073d5ae9-f6cc-4673-ab15-9150c60cf505)

## CPMK 2 – SubCPMK 4

### **1. Penjelasan Struct dan Contoh Program**

**Penjelasan Struct:** Struktur (struct) dalam pemrograman C++ adalah tipe data yang mengelompokkan beberapa variabel dengan tipe yang berbeda di bawah satu nama untuk memudahkan pengelolaan data terkait.

```c++
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
```
**OUTPUT:**![Cuplikan layar dari 2024-05-16 23-38-58](https://github.com/JeremyMarcello/Assignment-Algoritma-dan-Struktur-Data/assets/156126843/857ed33c-200f-4248-8bc1-a135eb22da86)

## CPMK 2 – SubCPMK 5

### **1. Program Menghilangkan Duplikasi pada Unsorted Linked List**

```c++
#include <iostream>
using namespace std;

struct Node{
    string data;
    Node *next;
};
Node *head, *tail, *baru, *bantu, *hapus;

void init(){
    head = NULL;
    tail = head;
}

int isEmpty(){
    return head == NULL ? 1 : 0;
}

void buatNode(string data){
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

int hitungList(){
    bantu = head;
    int jumlah = 0;
    while (bantu != NULL)
    {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

void insertDepan(string data){
    buatNode(data);
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        tail->next = baru;
        baru->next = head;
        head = baru;
    }
}

void insertBelakang(string data){
    buatNode(data);
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }
}

void insertTengah(string data, int posisi){
    if (isEmpty() == 1 || posisi <= 1)
    {
        insertDepan(data);
    }
    else
    {
        buatNode(data);
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            if (bantu->next == head)
            {
                insertBelakang(data);
                return;
            }
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

void hapusDepan(){
    if (isEmpty() == 0)
    {
        hapus = head;
        tail->next = head->next;
        head = head->next;
        delete hapus;
    }
    else
    {
        cout << "List Masih Kosong!" << endl;
    }
}

void hapusBelakang(){
    if (isEmpty() == 0)
    {
        hapus = tail;
        bantu = head;
        while (bantu->next != tail)
        {
            bantu = bantu->next;
        }
        tail = bantu;
        tail->next = head;
        delete hapus;
    }
    else
    {
        cout << "List Masih Kosong!" << endl;
    }
}

void hapusTengah(int posisi){
    if (isEmpty() == 0)
    {
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
    else
    {
        cout << "List Masih Kosong!" << endl;
    }
}

void clearList(){
    if (head != NULL)
    {
        hapus = head->next;
        while (hapus != head)
        {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List Berhasil Terhapus!" << endl;
}

void tampil(){
    cout << "Isi linked list: ";
    if (isEmpty() == 0)
    {
        Node *temp = head;
        do
        {
            cout << temp->data << ends;
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
    else
    {
        cout << "List Masih Kosong!" << endl;
    }
}

void hapusDuplikasi(){
    if (isEmpty() == 0)
    {
        Node *current = head;
        Node *index = NULL;
        Node *temp = NULL;

        if (head == NULL)
            return;
        else
        {
            do
            {
                temp = current;
                index = current->next;

                while (index != head)
                {
                    if (current->data == index->data)
                    {
                        temp->next = index->next;
                        delete index;
                        index = temp->next;
                    }
                    else
                    {
                        temp = index;
                        index = index->next;
                    }
                }
                current = current->next;
            } while (current->next != head);
        }
    }
    else
    {
        cout << "List Masih Kosong!" << endl;
    }
}


int main(){
    init();
    insertDepan("Ayam ");
    insertDepan("Bebek ");
    insertBelakang("Cicak ");
    insertBelakang("Domba ");
    insertTengah("Ayam ", 2);
    tampil();
    hapusDuplikasi();
    tampil();

    return 0;
}
```
**OUTPUT:**![Cuplikan layar dari 2024-05-17 00-14-50](https://github.com/JeremyMarcello/Assignment-Algoritma-dan-Struktur-Data/assets/156126843/ca9bcf3a-c1ae-4b86-a9e3-bfea4d4e7a18)

2. **Program Menghapus Node di Tengah Single Linked List**

```c++
#include <iostream>
using namespace std;

struct Node{
    string data;
    Node *next;
};
Node *head, *tail, *baru, *bantu, *hapus;

void init(){
    head = NULL;
    tail = head;
}

int isEmpty(){
    return head == NULL ? 1 : 0;
}

void buatNode(string data){
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

int hitungList(){
    bantu = head;
    int jumlah = 0;
    while (bantu != NULL)
    {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

void insertDepan(string data){
    buatNode(data);
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        tail->next = baru;
        baru->next = head;
        head = baru;
    }
}

void insertBelakang(string data){
    buatNode(data);
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }
}

void insertTengah(string data, int posisi){
    if (isEmpty() == 1 || posisi <= 1)
    {
        insertDepan(data);
    }
    else
    {
        buatNode(data);
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            if (bantu->next == head)
            {
                insertBelakang(data);
                return;
            }
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

void hapusDepan(){
    if (isEmpty() == 0)
    {
        hapus = head;
        tail->next = head->next;
        head = head->next;
        delete hapus;
    }
    else
    {
        cout << "List Masih Kosong!" << endl;
    }
}

void hapusBelakang(){
    if (isEmpty() == 0)
    {
        hapus = tail;
        bantu = head;
        while (bantu->next != tail)
        {
            bantu = bantu->next;
        }
        tail = bantu;
        tail->next = head;
        delete hapus;
    }
    else
    {
        cout << "List Masih Kosong!" << endl;
    }
}

void hapusTengah(int posisi){
    if (isEmpty() == 0)
    {
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
    else
    {
        cout << "List Masih Kosong!" << endl;
    }
}

void clearList(){
    if (head != NULL)
    {
        hapus = head->next;
        while (hapus != head)
        {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List Berhasil Terhapus!" << endl;
}

void tampil(){
    cout << "Isi linked list: ";
    if (isEmpty() == 0)
    {
        Node *temp = head;
        do
        {
            cout << temp->data << ends;
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
    else
    {
        cout << "List Masih Kosong!" << endl;
    }
}

void hapusDuplikasi(){
    if (isEmpty() == 0)
    {
        Node *current = head;
        Node *index = NULL;
        Node *temp = NULL;

        if (head == NULL)
            return;
        else
        {
            do
            {
                temp = current;
                index = current->next;

                while (index != head)
                {
                    if (current->data == index->data)
                    {
                        temp->next = index->next;
                        delete index;
                        index = temp->next;
                    }
                    else
                    {
                        temp = index;
                        index = index->next;
                    }
                }
                current = current->next;
            } while (current->next != head);
        }
    }
    else
    {
        cout << "List Masih Kosong!" << endl;
    }
}


int main(){
    init();
    insertDepan("Ayam ");
    insertDepan("Bebek ");
    insertBelakang("Cicak ");
    insertBelakang("Domba ");
    insertTengah("Ayam ", 2);
    tampil();
    hapusTengah(4);
    tampil();

    return 0;
}
```
**OUTPUT:**![Cuplikan layar dari 2024-05-17 00-16-35](https://github.com/JeremyMarcello/Assignment-Algoritma-dan-Struktur-Data/assets/156126843/a4a5c68f-ff99-4165-926a-21e11a5f834d)

### **3. Program Mengecek Linked List Palindrom**

```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Node{
    string data;
    Node *next;
};
Node *head, *tail, *baru, *bantu, *hapus;

void init(){
    head = NULL;
    tail = head;
}

int isEmpty(){
    return head == NULL ? 1 : 0;
}

void buatNode(string data){
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

void insertDepan(string data){
    buatNode(data);
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        tail->next = baru;
        baru->next = head;
        head = baru;
    }
}

void insertBelakang(string data){
    buatNode(data);
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }
}

void insertTengah(string data, int posisi){
    if (isEmpty() == 1 || posisi <= 1)
    {
        insertDepan(data);
    }
    else
    {
        buatNode(data);
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            if (bantu->next == head)
            {
                insertBelakang(data);
                return;
            }
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

void hapusTengah(int posisi){
    if (isEmpty() == 0)
    {
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
    else
    {
        cout << "List Masih Kosong!" << endl;
    }
}

void tampil(){
    cout << "Isi linked list: ";
    if (isEmpty() == 0)
    {
        Node *temp = head;
        do
        {
            cout << temp->data << ends;
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
    else
    {
        cout << "List Masih Kosong!" << endl;
    }
}

bool isPalindrom(){
    if (isEmpty()) // Jika linked list kosong, tidak bisa menjadi palindrom
        return false;

    vector<string> elements; // Array untuk menyimpan elemen-elemen linked list

    Node *current = head;
    do {
        elements.push_back(current->data); // Menambahkan data dari setiap node ke array
        current = current->next;
    } while (current != head);

    int start = 0; // Pointer ke elemen pertama array
    int end = elements.size() - 1; // Pointer ke elemen terakhir array

    // Periksa apakah array adalah palindrom
    while (start < end) {
        if (elements[start] != elements[end])
            return false; // Jika ada elemen yang tidak cocok, bukan palindrom
        start++;
        end--;
    }

    return true; // Jika semua elemen cocok, merupakan palindrom
}

int main(){
    init();
    insertDepan("Ayam ");
    insertDepan("Cicak ");
    insertDepan("Bebek ");
    insertBelakang("Cicak ");
    insertBelakang("Bebek ");
    insertTengah("Ayam ", 3);
    tampil();
    if (isPalindrom())
        cout << "Linked list ini adalah palindrom" << endl;
    else
        cout << "Linked list ini bukan palindrom" << endl;
    return 0;
}

```
**OUTPUT:**![Cuplikan layar dari 2024-05-17 00-37-14](https://github.com/JeremyMarcello/Assignment-Algoritma-dan-Struktur-Data/assets/156126843/eb8ec270-6ad8-45e3-9c87-ba5cab9e1b97)

## CPMK 2 – SubCPMK 6

### **1. Program Operasi Stack**

   ```cpp
#include <iostream>
using namespace std;

#define MAX_SIZE 5

struct Stack {
    int top;
    int items[MAX_SIZE];
};

void init(Stack &stack) {
    stack.top = -1;
}

bool isEmpty(Stack &stack) {
    return stack.top == -1;
}

bool isFull(Stack &stack) {
    return stack.top == MAX_SIZE - 1;
}

void push(Stack &stack, int value) {
    if (isFull(stack)) {
        cout << "Stack penuh, push gagal." << endl;
    } else {
        stack.items[++stack.top] = value;
        cout << "Nilai " << value << " berhasil ditambahkan ke dalam stack." << endl;
    }
}

void pop(Stack &stack) {
    if (isEmpty(stack)) {
        cout << "Stack kosong, pop gagal." << endl;
    } else {
        int poppedValue = stack.items[stack.top--];
        cout << "Nilai " << poppedValue << " berhasil dihapus dari stack." << endl;
    }
}

int top(Stack &stack) {
    if (isEmpty(stack)) {
        cout << "Stack kosong." << endl;
        return -1;
    } else {
        return stack.items[0];
    }
}


int size(Stack &stack) {
    return stack.top + 1;
}

void clear(Stack &stack) {
    init(stack);
    cout << "Semua elemen berhasil dihapus dari stack." << endl;
}

void printStack(Stack &stack) {
    if (isEmpty(stack)) {
        cout << "Stack kosong." << endl;
    } else {
        cout << "Isi stack: ";
        for (int i = stack.top; i >= 0; i--) {
            cout << stack.items[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    Stack stack;
    init(stack);
    printStack(stack);
    push(stack, 8);
    push(stack, 3);
    push(stack, 1);
    push(stack, 9);
    push(stack, 5);
    push(stack, 6);
    printStack(stack);
    cout << "Top stack: " << top(stack) << endl;
    cout << "Size stack: " << size(stack) << endl;
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    clear(stack);

    return 0;
}
```
**OUTPUT:**![Cuplikan layar dari 2024-05-17 00-51-01](https://github.com/JeremyMarcello/Assignment-Algoritma-dan-Struktur-Data/assets/156126843/d7c2edcb-2820-4e4b-9214-8c5f46c9d632)

### **2. Program Mengurutkan Stack**

```c++
#include <iostream>
using namespace std;

#define MAX_SIZE 5

struct Stack {
    int top;
    int items[MAX_SIZE];
};

void init(Stack &stack) {
    stack.top = -1;
}

bool isEmpty(Stack &stack) {
    return stack.top == -1;
}

bool isFull(Stack &stack) {
    return stack.top == MAX_SIZE - 1;
}

void push(Stack &stack, int value) {
    if (isFull(stack)) {
        cout << "Stack penuh, push gagal." << endl;
    } else {
        stack.items[++stack.top] = value;
        cout << "Nilai " << value << " berhasil ditambahkan ke dalam stack." << endl;
    }
}

void pop(Stack &stack) {
    if (isEmpty(stack)) {
        cout << "Stack kosong, pop gagal." << endl;
    } else {
        int poppedValue = stack.items[stack.top--];
        cout << "Nilai " << poppedValue << " berhasil dihapus dari stack." << endl;
    }
}

int top(Stack &stack) {
    if (isEmpty(stack)) {
        cout << "Stack kosong." << endl;
        return -1;
    } else {
        return stack.items[0];
    }
}

int size(Stack &stack) {
    return stack.top + 1;
}

void clear(Stack &stack) {
    init(stack);
    cout << "Semua elemen berhasil dihapus dari stack." << endl;
}

void printStack(Stack &stack) {
    if (isEmpty(stack)) {
        cout << "Stack kosong." << endl;
    } else {
        cout << "Isi stack: ";
        for (int i = stack.top; i >= 0; i--) {
            cout << stack.items[i] << " ";
        }
        cout << endl;
    }
}

void bubbleSort(Stack &stack) {
    int n = size(stack);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (stack.items[j] > stack.items[j + 1]) {
                // Tukar elemen
                int temp = stack.items[j];
                stack.items[j] = stack.items[j + 1];
                stack.items[j + 1] = temp;
            }
        }
    }
}

int main() {
    Stack stack;
    init(stack);
    printStack(stack);
    push(stack, 8);
    push(stack, 3);
    push(stack, 1);
    push(stack, 9);
    push(stack, 5);
    push(stack, 6);
    printStack(stack);
    cout << "Top stack: " << top(stack) << endl;
    cout << "\nStack sebelum diurutkan:" << endl;
    printStack(stack);
    bubbleSort(stack);
    cout << "Stack setelah diurutkan:" << endl;
    printStack(stack);
    cout << "Top stack: " << top(stack) << endl;

    return 0;
}
```
**OUTPUT:**![Cuplikan layar dari 2024-05-17 00-51-32](https://github.com/JeremyMarcello/Assignment-Algoritma-dan-Struktur-Data/assets/156126843/dc2187ef-41ba-4786-9b3b-9f7b35c0cef8)

## CPMK 2 – SubCPMK 7

### **1. Program Operasi Queue**

```c++
#include <iostream>
#include <string>
using namespace std;

#define MAX_SIZE 5

struct Queue {
    int depan, belakang, size;
    string items[MAX_SIZE];
};

void init(Queue &queue) {
    queue.depan = 0;
    queue.belakang = -1;
    queue.size = 0;
}

bool isEmpty(Queue &queue) {
    return queue.size == 0;
}

bool isFull(Queue &queue) {
    return queue.size == MAX_SIZE;
}

void enqueue(Queue &queue, const string &value) {
    if (isFull(queue)) {
        cout << "Queue penuh, enqueue gagal." << endl;
    } else {
        queue.belakang = (queue.belakang + 1) % MAX_SIZE;
        queue.items[queue.belakang] = value;
        queue.size++;
        cout << "Kata '" << value << "' berhasil ditambahkan ke dalam queue." << endl;
    }
}

void dequeue(Queue &queue) {
    if (isEmpty(queue)) {
        cout << "Queue kosong, dequeue gagal." << endl;
    } else {
        string dequeuedValue = queue.items[queue.depan];
        queue.depan = (queue.depan + 1) % MAX_SIZE;
        queue.size--;
        cout << "Kata '" << dequeuedValue << "' berhasil dihapus dari queue." << endl;
    }
}

string depan(Queue &queue) {
    if (isEmpty(queue)) {
        cout << "Queue kosong." << endl;
        return ""; // Nilai default jika queue kosong
    } else {
        return queue.items[queue.depan];
    }
}

int size(Queue &queue) {
    return queue.size;
}

void clear(Queue &queue) {
    init(queue);
    cout << "Semua kata berhasil dihapus dari queue." << endl;
}

void printQueue(Queue &queue) {
    if (isEmpty(queue)) {
        cout << "Queue kosong." << endl;
    } else {
        cout << "Isi queue: ";
        int i = queue.depan;
        int count = 0;
        while (count < queue.size) {
            cout << queue.items[i] << " ";
            i = (i + 1) % MAX_SIZE;
            count++;
        }
        cout << endl;
    }
}

int main() {
    Queue queue;
    init(queue);
    enqueue(queue, "satu");
    enqueue(queue, "dua");
    enqueue(queue, "tiga");
    enqueue(queue, "empat");
    enqueue(queue, "lima");
    enqueue(queue, "enam"); // Ini akan gagal karena queue penuh
    printQueue(queue);
    cout << "depan queue: " << depan(queue) << endl;
    cout << "Size queue: " << size(queue) << endl;
    dequeue(queue);
    printQueue(queue);
    clear(queue);

    return 0;
}
```
**OUTPUT:**![Cuplikan layar dari 2024-05-17 01-00-00](https://github.com/JeremyMarcello/Assignment-Algoritma-dan-Struktur-Data/assets/156126843/a04c712e-70f7-4819-8b07-31a891a2c639)

### **2. Program Adopsi Kucing dan Anjing dishelter**

```c++
#include <iostream>
#include <string>
using namespace std;

#define MAX_SIZE 5

struct Queue {
    int depan, belakang, size;
    string items[MAX_SIZE];
};

void init(Queue &queue) {
    queue.depan = 0;
    queue.belakang = -1;
    queue.size = 0;
}

bool isEmpty(Queue &queue) {
    return queue.size == 0;
}

bool isFull(Queue &queue) {
    return queue.size == MAX_SIZE;
}

void enqueue(Queue &queue, const string &value) {
    if (isFull(queue)) {
        cout << "shelter penuh, gagal menambah hewan." << endl;
    } else {
        queue.belakang = (queue.belakang + 1) % MAX_SIZE;
        queue.items[queue.belakang] = value;
        queue.size++;
        cout << "Hewan'" << value << "' berhasil dimasukkan ke shelter." << endl;
    }
}

void dequeue(Queue &queue) {
    if (isEmpty(queue)) {
        cout << "Kucing dan anjing sedang kosong, adopsi gagal." << endl;
    } else {
        string dequeuedValue = queue.items[queue.depan];
        queue.depan = (queue.depan + 1) % MAX_SIZE;
        queue.size--;
        cout << "Hewan '" << dequeuedValue << "' berhasil kamu adopsi." << endl;
    }
}

string depan(Queue &queue) {
    if (isEmpty(queue)) {
        cout << "Queue kosong." << endl;
        return ""; // Nilai default jika queue kosong
    } else {
        return queue.items[queue.depan];
    }
}

int size(Queue &queue) {
    return queue.size;
}

void printQueue(Queue &queue) {
    if (isEmpty(queue)) {
        cout << "Kucing dan anjing sedang kosong." << endl;
    } else {
        cout << "Hewan yang tersedia: ";
        int i = queue.depan;
        int count = 0;
        while (count < queue.size) {
            cout << queue.items[i] << " ";
            i = (i + 1) % MAX_SIZE;
            count++;
        }
        cout << endl;
    }
}

void dequeueDogCat(Queue &queue, const string &target) {
    if (isEmpty(queue)) {
        cout << "Kucing dan anjing sedang kosong, adopsi gagal." << endl;
    } else {
        bool found = false;
        int count = 0;
        int i = queue.depan;
        while (count < queue.size) {
            if (queue.items[i] == target) {
                found = true;
                break;
            }
            i = (i + 1) % MAX_SIZE;
            count++;
        }
        if (found) {
            cout << "Hewan '" << target << "' berhasil kamu adopsi." << endl;
            while (i != queue.belakang) {
                queue.items[i] = queue.items[(i + 1) % MAX_SIZE];
                i = (i + 1) % MAX_SIZE;
            }
            queue.items[i] = ""; // Kosongkan elemen terakhir
            queue.belakang = (queue.belakang - 1 + MAX_SIZE) % MAX_SIZE;
            queue.size--;
        } else {
            cout << "Hewan '" << target << "' sedang kosong" << endl;
        }
    }
}


int main() {
    Queue queue;
    init(queue);
    enqueue(queue, "Cat");
    enqueue(queue, "Cat");
    enqueue(queue, "Dog");
    enqueue(queue, "Cat");
    enqueue(queue, "Dog");
    printQueue(queue);
    dequeue(queue);
    dequeueDogCat(queue, "Cat");
    dequeueDogCat(queue, "Cat");
    dequeueDogCat(queue, "Cat");
    dequeueDogCat(queue, "Dog");
    printQueue(queue);

    return 0;
}
```
**OUTPUT:**![Cuplikan layar dari 2024-05-17 01-16-52](https://github.com/JeremyMarcello/Assignment-Algoritma-dan-Struktur-Data/assets/156126843/b1f0779a-5913-420b-bd44-abcc15f8fc93)
