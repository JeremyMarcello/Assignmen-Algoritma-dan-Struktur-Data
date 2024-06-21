# <h1 align="center">Tugas 3 Struktur Data</h1>

<p align="center">Jeremy Marcello Waani / 2311110003</p>

## Priority Queue

Antrean prioritas adalah jenis antrian khusus di mana setiap elemen dihubungkan dengan nilai prioritas dan elemen dilayani berdasarkan prioritasnya[1]. Elemen dengan prioritas yang lebih tinggi akan diambil atau diproses lebih dulu daripada elemen dengan prioritas yang lebih rendah, yang memungkinkan penyimpanan dan pengambilan elemen sesuai dengan tingkat prioritasnya, yang memungkinkan penyelesaian masalah yang memerlukan penanganan lebih lanjut.

Contoh program priority queue menggunakan C++:

```cpp
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    priority_queue<int> pq;

    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();\
    }

    return 0;
}
```


Program di atas membuat sebuah priority queue dengan tipe data integer, kemudian menambahkan elemen-elemen 10, 30, 20, dan 5 ke dalamnya. Priority queue secara otomatis mengurutkan elemen-elemen tersebut berdasarkan prioritas tertinggi, di mana elemen dengan nilai terbesar berada di posisi paling atas. Melalui loop, program menggunakan fungsi `top()` untuk mendapatkan dan `pop()` untuk menghapus elemen dengan prioritas tertinggi, kemudian mencetaknya ke layar. Akhirnya, program menampilkan elemen-elemen dalam urutan prioritas dari yang terbesar ke yang terkecil, menghasilkan output `30 20 10 5`.

## Hash Table

Dalam struktur data tabel hash, elemen disimpan dalam pasangan nilai kunci. Nilai hash dari kunci adalah nilai bulat yang digunakan untuk mengindeks nilai, dan nilai adalah data yang terkait dengan kunci [2]. Metode hash table menghitung nilai hash dari kunci dan kemudian menyimpan nilai yang sesuai pada lokasi tertentu di dalam tabel. Karena fungsi hash dapat diakses langsung, penambahan, penghapusan, dan pencarian nilai sangat efektif.

Contoh program hash table menggunakan C++:

```cpp
#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

class HashTable {
private:
    int bucketCount;
    vector<list<pair<int, string>>> table;

    int hashFunction(int key) {
        return key % bucketCount;
    }

public:
    HashTable(int buckets) : bucketCount(buckets) {
        table.resize(bucketCount);
    }

    void insertItem(int key, const string& value) {
        int index = hashFunction(key);
        table[index].push_back({key, value});
    }

    void removeItem(int key) {
        int index = hashFunction(key);
        auto& bucket = table[index];

        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }

    string searchItem(int key) {
        int index = hashFunction(key);
        auto& bucket = table[index];

        for (auto& pair : bucket) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return "Not Found";
    }

    void displayTable() {
        for (int i = 0; i < bucketCount; ++i) {
            cout << "Bucket " << i << ": ";
            for (auto& pair : table[i]) {
                cout << "[" << pair.first << ": " << pair.second << "] ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht(7);

    ht.insertItem(1, "Apple");
    ht.insertItem(2, "Banana");
    ht.insertItem(3, "Cherry");
    ht.insertItem(4, "Date");
    ht.insertItem(5, "Elderberry");
    ht.insertItem(6, "Fig");
    ht.insertItem(7, "Grape");

    ht.displayTable();

    cout << "Search for key 3: " << ht.searchItem(3) << endl;
    cout << "Search for key 10: " << ht.searchItem(10) << endl;

    ht.removeItem(3);
    ht.displayTable();

    return 0;
}
```


Dalam program tersebut, Hash Table dibangun dengan menggunakan vektor yang berisi list dari pasangan integer dan string, di mana setiap pasangan merepresentasikan pasangan kunci-nilai yang disimpan. Fungsi hash sederhana digunakan untuk menentukan indeks bucket berdasarkan modulus terhadap jumlah bucket yang ditentukan. Program ini mendukung operasi dasar seperti memasukkan (insert), mencari (search), dan menghapus (remove) data berdasarkan kunci. Selain itu, metode `displayTable` digunakan untuk menampilkan seluruh isi hash table ke layar. Misalnya, setelah memasukkan beberapa pasangan kunci-nilai dan menghapus satu elemen, hasil keluarannya menunjukkan struktur hash table yang terorganisir berdasarkan fungsi hash yang digunakan.

## Rekursif

Fungsi rekursif adalah jenis fungsi yang memiliki nama sendiri. Proses ini juga disebut sebagai rekursi [3]. Fungsi rekursif membutuhkan kondisi dasar untuk menghentikan rekursi dan mengembalikan nilai. Untuk memecahkan masalah secara berulang seperti factorial, fibonacci, dan pencarian binary, regresi dapat digunakan.

Contoh program faktorial secara rekursif menggunakan C++:

```cpp
#include <iostream>
using namespace std;

int factorial(int n) {
  if (n <= 1)
    return 1;
  else
    return n * factorial(n-1);
}

int main() {
  int number = 5;
  cout << number << " factorial is " << factorial(number) << endl;

  return 0;
}
```


Saat fungsi `factorial` dipanggil dengan argumen `n`, jika `n` lebih kecil atau sama dengan 1, fungsi mengembalikan nilai 1 sebagai kondisi dasar rekursi. Namun, jika `n` lebih besar dari 1, fungsi akan memanggil dirinya sendiri dengan argumen `n-1` dan mengalikan n dengan hasil rekursif dari `factorial(n-1)`. Pada `main`, nilai faktorial dari bilangan 5 dihitung dan hasilnya, yaitu 120, dicetak ke layar bersama dengan teks yang sesuai.

## Graph & Tree

Graph adalah sekumpulan titik dan garis , dan tree adalah struktur data non linier yang terdiri dari sekumpulan node berbeda [4]. 

Contoh program representasi graph menggunakan adjacency list dalam C++:

```cpp
#include <list>
#include <iostream>
using namespace std;

class Graph {
  int V;
  list<int> *adj;

  public:
    Graph(int V);
    void addEdge(int v, int w);
    void printGraph();
};

Graph::Graph(int V) {
  this->V = V;
  adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);
}

void Graph::printGraph() {
  for(int i = 0; i < V; i++) {
    cout << i << "->";
    for (int x : adj[i])
      cout << x << ",";
    cout << endl;
  }
}
```

Kelas `Graph` memiliki variabel anggota `V` yang menunjukkan jumlah vertex (simpul) dalam graf dan `adj` yang merupakan array dari list, masing-masing list menyimpan simpul-simpul yang terhubung dari sebuah vertex tertentu. Konstruktor `Graph(int V)` digunakan untuk menginisialisasi jumlah vertex dan alokasi memori untuk array `adj`. Metode `addEdge(int v, int w)` digunakan untuk menambahkan edge (sisi) antara vertex `v` dan `w` dengan memasukkan w ke dalam list yang terhubung dengan vertex `v`. Metode `printGraph()` mencetak graf ke layar dengan mengiterasi melalui setiap vertex dan mencetak semua simpul yang terhubung dengan vertex tersebut dalam format `i->j,k,...`, di mana i adalah vertex dan `j,k,...` adalah vertex yang terhubung dari `i`. Program ini menyediakan representasi yang efisien dan fleksibel untuk merepresentasikan hubungan antar objek (vertex) dalam suatu graf menggunakan adjacency list.

## Referensi

[1] Programiz, "Antrean Prioritas C++" 2022. [Online]. Available: https://www.programiz.com/cpp-programming/priority-queue.

[2] Programiz, "Tabel Hash" 2022. [Online]. Available: https://www.programiz.com/dsa/hash-table.

[3] Programiz, "Rekursi C++" 2022. [Online]. Available: https://www.programiz.com/cpp-programming/recursion.

[4] Wordpress, "Data Structure : Mengenal Graph & Tree" 2020. [Online]. Available: https://ramdannur.wordpress.com/2020/11/10/data-structure-mengenal-graph-tree/.