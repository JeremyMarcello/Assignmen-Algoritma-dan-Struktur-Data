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
