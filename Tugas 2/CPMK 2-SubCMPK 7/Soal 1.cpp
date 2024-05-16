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
