#include <iostream>
#include <cmath>

using namespace std;

class ArrayPlus {
    private:
        int * array;
        int size;
    public:
        ArrayPlus(int a, int b = 0);
        void resize();
        void print() const;
};

ArrayPlus::ArrayPlus(int a, int b = 0) {
    int * arr = new int[a];
    size = a;
    for (int i = 0; i < size; i++) {
        arr[i] = b;
    }
    array = arr;
}

void ArrayPlus::resize() {
    int * newarr = new int[size*2];
    for (int i = 0; i < size; i++) {
        newarr[i] = array[i];
    }
    for (int i = size; i < size*2; i++) {
        newarr[i] = 0;
    }
    delete array;
    array = newarr;
    size *= 2;
}

void ArrayPlus::print() const {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}

int main() {
    ArrayPlus arr(4, 3);
    arr.print();
    cout << endl;
    arr.resize();
    arr.print();

}