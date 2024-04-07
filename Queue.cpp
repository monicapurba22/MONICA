#include <iostream>
using namespace std;

class Queue {
private:
    int* queueArray; // Array untuk menyimpan elemen antrian
    int maxSize;     // Ukuran maksimum antrian
    int currentSize; // Jumlah elemen saat ini dalam antrian
    int frontIndex;  // Indeks untuk elemen depan antrian
    int rearIndex;   // Indeks untuk elemen belakang antrian

public:
    // Konstruktor untuk menginisialisasi antrian dengan ukuran tertentu
    Queue(int size) {
        maxSize = size;
        queueArray = new int[maxSize];
        currentSize = 0;
        frontIndex = 0;
        rearIndex = -1;
    }

    // Destruktor untuk membersihkan memori yang dialokasikan untuk array
    ~Queue() {
        delete[] queueArray;
    }

    // Menambahkan elemen ke belakang antrian
    void enqueue(int value) {
        if (currentSize == maxSize) {
            cout << "Queue is full. Cannot enqueue more elements." << endl;
            return;
        }
        rearIndex = (rearIndex + 1) % maxSize; // Menggeser rearIndex ke belakang dengan memperhatikan pembungkusan
        queueArray[rearIndex] = value;
        currentSize++;
    }

    // Menghapus elemen dari depan antrian
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue elements." << endl;
            return -1;
        }
        int dequeuedValue = queueArray[frontIndex];
        frontIndex = (frontIndex + 1) % maxSize; // Menggeser frontIndex ke depan dengan memperhatikan pembungkusan
        currentSize--;
        return dequeuedValue;
    }

    // Mendapatkan elemen dari depan antrian tanpa menghapusnya
    int front() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return queueArray[frontIndex];
    }

    // Memeriksa apakah antrian kosong
    bool isEmpty() {
        return currentSize == 0;
    }

    // Memeriksa apakah antrian penuh
    bool isFull() {
        return currentSize == maxSize;
    }

    // Mencetak seluruh elemen antrian
    void print() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue: ";
        int index = frontIndex;
        for (int i = 0; i < currentSize; i++) {
            cout << queueArray[index] << " ";
            index = (index + 1) % maxSize; // Menggeser indeks dengan memperhatikan pembungkusan
        }
        cout << endl;
    }
};

int main() {
    Queue q(5); // Membuat antrian dengan ukuran 5
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.print(); // Output: Queue: 1 2 3
    cout << "Front element: " << q.front() << endl; // Output: Front element: 1
    cout << "Dequeued element: " << q.dequeue() << endl; // Output: Dequeued element: 1
    q.print(); // Output: Queue: 2 3
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl; // Output: Is the queue empty? No
    cout << "Is the queue full? " << (q.isFull() ? "Yes" : "No") << endl; // Output: Is the queue full? No

    return 0;
}
