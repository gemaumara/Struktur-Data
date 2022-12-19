#include <iostream>
#include <stdlib.h>

using namespace std;

struct Tree
{
  char huruf;
  Tree *left;
  Tree *right;
};

Tree *node, *nodeBaru, *root = NULL, *current;

Tree *tambahNode(Tree *&current, char data)
{
  if (current == NULL)
  {
    current = new Tree;
    current->huruf = data;
    current->left = NULL;
    current->right = NULL;
  }
  else
  {
    if (data < current->huruf)
    {
      tambahNode(current->left, data);
    }
    else
    {
      tambahNode(current->right, data);
    }
  }

  return current;
}

void preOrder(Tree *current)
{
  if (current != NULL)
  {
    cout << " " << current->huruf;
    preOrder(current->left);
    preOrder(current->right);
  }
}

void inOrder(Tree *current)
{
  // kiri parent kanan
  if (current != NULL)
  {
    inOrder(current->left);
    cout << " " << current->huruf;
    inOrder(current->right);
  }
}

void postOrder(Tree *current)
{
  // kiri kanan parent
  if (current != NULL)
  {
    postOrder(current->left);
    postOrder(current->right);
    cout << " " << current->huruf;
  }
}

void menu(int pilih)
{
  char data;
  Tree *inputan;
  switch (pilih)
  {
  case 1:
    cout << "Masukkan Satu Huruf : ";
    cin >> data;
    inputan = tambahNode(node, data);
    break;
  case 2:
    cout << "Masukkan Satu Huruf : ";
    cin >> data;
    inputan = tambahNode(node, data);
    break;
  case 3:
    preOrder(node);
    cout << "\n";
    break;
  case 4:
    inOrder(node);
    cout << "\n";
    break;
  case 5:
    postOrder(node);
    cout << "\n";
    break;
  case 0:
    exit(0);
    break;
  
  default:
    cout << "Masukkan pilihan yang tepat" << endl;
    break;
  }
}

int main()
{
  int pilih;
  do
  {
    cout << "1. Tambah Kiri" << endl;
    cout << "2. Tambah Kanan" << endl;
    cout << "3. Pre Order" << endl;
    cout << "4. In Order" << endl;
    cout << "5. Post Order" << endl;
    cout << "0. Exit" << endl;
    cout << "Masukkan Pilihan Menu : ";
    cin >> pilih;
    menu(pilih);
  } while (pilih != 0);
}