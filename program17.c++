// judul    : perubahan aritmatika infix ke prefix
// matkul   : struktur data -  imanuel harkespan
// oleh     : gema umara muhammad
// tanggal  : 9 oktober 2022

#include <iostream>
#include <string>
#define MAX 20

using namespace std;

void push(char);
char pop();
bool isFull();
bool isEmpty();
string in2prefix(string);
int priority(char);
int stack[MAX];
int top = -1;
void cetak();

int main()
{
    string infix;
    string prefix;
    cout << "Masukkan huruf : ";
    cin >> infix;
    prefix = in2prefix(infix);

    return 0;
}

bool isFull()
{
    if (MAX == MAX - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(char oper)
{
    if (isFull())
    {
        cout << "Stack Penuh";
    }
    else
    {
        top++;
        stack[top] = oper;
    }
}

char pop()
{
    char ch;
    if (isEmpty())
    {
        cout << "\n";
    }
    else
    {
        ch = stack[top];
        stack[top] = 0;
        top--;

        return ch;
    }

    return 0;
}

string in2prefix(string infix)
{
    int i = 0;
    string prefx = " ";

    while (infix[i] != '\0')
    {
        // cek jika ketemu alfabet
        if (infix[i] >= 'a' && infix[i] <= 'z')
        {
            prefx.insert(prefx.end(), infix[i]);
            i++;
        }

        // jika ketemu bracket, simpan ke stack
        else if (infix[i] == ')' || infix[i] == '}' || infix[i] == ']')
        {
            push(infix[i]);
            i++;
        }

        else if (infix[i] == '(' || infix[i] == '{' || infix[i] == '[')
        {
            if (infix[i] == '(')
            {
                while (stack[top] != ')')
                {
                    prefx.insert(prefx.begin(), pop());
                }
                pop();
                i++;
            }

            if (infix[i] == '{')
            {
                while (stack[top] != '}')
                {
                    prefx.insert(prefx.begin(), pop());
                }
                pop();
                i++;
            }

            if (infix[i] == '[')
            {
                while (stack[top] != '[')
                {
                    prefx.insert(prefx.begin(), pop());
                }
            }
            pop();
            i++;
        }

        else
        {
            if (top == -1)
            {
                push(infix[i]);
                i++;
            }

            else if (priority(infix[i]) <= priority(stack[top]))
            {
                prefx.insert(prefx.begin(), pop());

                while (priority(infix[i]) > priority(stack[top]))
                {
                    prefx.insert(prefx.end(), pop());

                    if (top < 0)
                    {
                        break;
                    }
                }

                push(infix[i]);
                i++;
            }

            else if (priority(infix[i]) > priority(stack[top]))
            {
                push(infix[i]);
                i++;
            }
        }
    }

    while (top != -1)
    {
        prefx.insert(prefx.begin(), pop());
    }

    cout << "Hasil konversi ke Prefix : " << prefx;

    return prefx;
}

int priority(char alpha)
{
    if (alpha == '+' || alpha == '-')
    {
        return 1;
    }

    if (alpha == '*' || alpha == '/')
    {
        return 2;
    }

    if (alpha == '$')
    {
        return 3;
    }

    return alpha;
}

void cetak()
{
    for (int i = 0; i <= top; i++)
    {
        cout << stack[i] << " ";
    }
}