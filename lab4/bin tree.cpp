#include<iostream>
#include <sstream>
#include <string>
#include <locale.h>
using namespace std;

class bst {

    struct bintree {

        int data;
        bintree* left;
        bintree* right;

        bintree(int data, bintree* pleft = nullptr, bintree* pright = nullptr) {
            this->data = data;
            this->left = pleft;
            this->right = pright;
        }

    };

    bintree* head;

public:
    bst() {
        head = nullptr;
    }
    bool isEmpty() { return(head == nullptr); }
    int find(int data);
    void push(int data);
    void printBin();
    void printBinTree(bintree* ptr);
    int Counter(int data);

};

int bst::find(int data)
{
    int n = 0;
    bintree* ptr = this->head;
    while (ptr != nullptr) {
        if ((data) == ptr->data)
            return n;
        if ((data) > (ptr->data))
            ptr = ptr->right;
        else
            ptr = ptr->left;
        n++;
    }

    return n;
}

void bst::push(int data) {

    bintree* p = new bintree(data);
    bintree* parent = nullptr;

    p->data = data;
    p->left = nullptr;
    p->right = nullptr;

    if (isEmpty())
        head = p;

    else {
        bintree* ptr = this->head;
        while (ptr != nullptr) {
            parent = ptr;
            if ((data) >= (ptr->data))
                ptr = ptr->right;
            else
                ptr = ptr->left;
        }
        if ((data) < (parent->data))
            parent->left = p;
        else
            parent->right = p;
    }
}
void bst::printBin() {
    printBinTree(head);
}

void bst::printBinTree(bintree* ptr) {

    if (ptr != nullptr) {
        printBinTree(ptr->left);
        cout << "  " << ptr->data;
        printBinTree(ptr->right);
    }

}
int bst::Counter(int data)
{
    int n = 0;
    bintree* ptr = this->head;
    while (ptr != nullptr) {
        if ((data) == ptr->data)
            n++;
        if ((data) >= (ptr->data))
            ptr = ptr->right;
        else
            ptr = ptr->left;
    }
    return n;
}
int main() {
    setlocale(0, "");
    srand(time(NULL));

    bst b;

    while (true)
    {
        cout<< "Чтобы закончить ввод, введите *"<<endl;
        string s;
        cin >> s;
        if (s == "*")
            break;
        b.push(atoi(s.c_str()));
    }

    b.printBin();

    cout << endl << "Результат поиска: " << b.find(100);
    
    cout << endl << "Кол-во совпадений: " << b.Counter(100);

    cin.get();
    return 0;
}