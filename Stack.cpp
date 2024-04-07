#include <iostream>
using namespace std;

class stack 
{
private:
    static const int MAX = 100;
    int top;
    char items[MAX];

public:
    stack() {
        top = -1;
    }

    void push(char elements) {
        if (top == MAX - 1) {
            cout << "stack overflow, tidak dapat mengisi element." << endl;
        }
        else {
            top++;
            items[top] = elements;
            cout << "element '" << elements << "' berhasil ditambahkan ke dalam stack" << endl;
        }
    }

   char pop() {
    if (top == -1) {
        cout << "stack kosong tidak ada element yang dapat di hapus" << endl;
        return '\0';
    }
    else {
        char removeditem = items[top];
        top--;
        cout << "element '" << removeditem << "' berhasil dihapus dari dalam stack" << endl;
        return removeditem;
    }
}

};

int main(int argc, char** argv) {

	 stack stack;

    stack.push('a');
    stack.push('b');
    stack.push('c');
    stack.push('d');
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();

	return 0;
}
