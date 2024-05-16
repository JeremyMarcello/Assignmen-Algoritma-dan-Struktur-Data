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
