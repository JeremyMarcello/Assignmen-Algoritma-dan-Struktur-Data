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
