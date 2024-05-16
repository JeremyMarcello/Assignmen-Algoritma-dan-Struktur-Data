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
