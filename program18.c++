// judul    : queue antrian
// matkul   : struktur data - imanuel harkespan
// oleh     : gema umara muhammad
// tanggal  : 11 oktober 2022

#include <iostream>

using namespace std;

#define MAX 8

struct Antrian
{
    int data[MAX];
    int head;
    int tail;
};

Antrian antre;
void create();
bool isEmpty();
bool isFull();
void enqueue(int);
int dequeue();
void clear();
void tampil();

int main()
{

    // kamus
    int answer;
    int data;

    // memanggil fungsi create
    create();

    do
    {
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Tampil\n";
        cout << "4. Clear\n";
        cout << "5. Keluar\n";
        cout << "Masukkan Pilihan Anda : ";
        cin >> answer;

        switch (answer)
        {
        case 1:
            enqueue(data);
            break;

        case 2:
            if (isEmpty() == 0)
            {
                cout << "Elemen yang keluar : " << dequeue() << endl;
            }
            else
            {
                cout << "Data Kosong" << endl;
            }
            break;

        case 3:
            tampil();
            break;

        case 4:
            clear();
            break;

        case 5:
            break;
        }
    } while (answer != 5);
}

void create()
{
    antre.head = antre.tail = -1;
}

bool isEmpty()
{
    if (antre.tail == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull()
{
    if (antre.tail == MAX - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(int data)
{
    if (isFull())
    {
        cout << "Antrian Penuh" << endl;
    }
    else
    {
        cout << "Masukkan Data : ";
        cin >> data;

        if (isEmpty())
        {
            antre.head = antre.tail = 0;
            antre.data[antre.tail] = data;
        }
        else
        {
            antre.tail++;
            antre.data[antre.tail] = data;
        }
    }
}

int dequeue()
{
    int e = antre.data[antre.head];

    if (isEmpty())
    {
        cout << "Antrian Kosong" << endl;
    }
    else
    {
        for (int i = antre.head; i <= antre.tail - 1; i++)
        {
            antre.data[i] = antre.data[i + 1];
        }
    }

    antre.tail--;
    return e;
}

void clear()
{
    antre.head = antre.tail = -1;
    cout << "Data Clear" << endl;
}

void tampil()
{
    if (isEmpty())
    {
        cout << "Antrian Kosong" << endl;
    }
    else
    {
        cout << "Antrian : " << endl;
        for (int i = antre.head; i <= antre.tail; i++)
        {
            cout << antre.data[i] << endl;
        }
    }
}
