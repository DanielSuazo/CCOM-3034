#include <iostream>


using namespace std;

class SortedList {
  private:
    int *A;
    int length, allocationSize;
    void resize(int);
  public:
    SortedList();
    ~SortedList();
    void insert(int);
    void display(int) const;
    int* begin() const;
    int* end() const;
    int getLength() const;
};

SortedList::SortedList() {
  A = new int[4];
  length = 0;
  allocationSize = 4;
}

SortedList::~SortedList() {
  delete [] A;
  A = nullptr;
}

int SortedList::getLength() const {
  return length;
}

void SortedList::display(int index) const {
  cout << A[index] << endl;
}

void SortedList::resize(int newSize) {
  int *B = new int[newSize];
  for (int i = 0; i < length; i++) {
    B[i] = A[i];
  }
  delete [] A;
  A = B;
  allocationSize = newSize;
}

void SortedList::insert(int item) {
  if (length == allocationSize) {
    resize(allocationSize*2);
  }
  if (length == 0) {
    A[0] = item;
  } else if (item < A[0]) {
    for (int i = length; i > 0; i--) {
      A[i] = A[i-1];
    }
    A[0] = item;
  } else {

    int index = 1;
    while (item > A[index] && index < length) {
      index++;
    }

    for (int i = length; i > index; i--) {
      A[i] = A[i-1];
    }

    A[index] = item;
  }
  
  length++;
}

int* SortedList::begin() const {
  return A;
}

int* SortedList::end() const {
  return A+length;
}

int main() {
  SortedList a;
  a.insert(1);
  a.insert(2);
  a.insert(4);
  a.insert(5);
  a.insert(7);
  a.insert(3);
  for (auto i: a) {
    cout << i << " ";
  }
}