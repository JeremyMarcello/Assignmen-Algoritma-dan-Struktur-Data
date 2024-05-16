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
