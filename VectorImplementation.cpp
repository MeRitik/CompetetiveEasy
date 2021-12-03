#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
class DynamicArray {
public:
    T *pointer;
    unsigned int capacity;
    unsigned int current;

    DynamicArray() {
        capacity = 1;
        current = 0;
        pointer = new T;
    }

    DynamicArray(int capacity) {
        this->capacity = capacity;
        current = 0;
        create();
    }

    DynamicArray(int capacity, const T &value) {
        this->capacity = capacity;
        create(value);
    }

    DynamicArray(const DynamicArray<T> &obj) {
        this->capacity = obj.capacity;
        this->current = obj.current;
        this->pointer = new T[capacity];

        for (int i = 0; i < obj.current; i++)
        {
            pointer[i] = obj.pointer[i];
        }
    }

    // void create() {
    //     pointer = new int[capacity];
    // }

    void create(int value = 0) {
        pointer = new int[capacity];

        for (int i = 0; i < capacity; i++) {
            pointer[i] = value;
        }
    }

    void print() {
        for (int i = 0; i < current; i++)
            cout << pointer[i] << endl;
    }

    unsigned int size() {
        return current;
    }

    unsigned int Cap() {
        return capacity;
    }

    void doubleCapacity() {
        T *temp = new T[2 * capacity];

        for (int i = 0; i < current; i++) {
            temp[i] = pointer[i];
        }

        delete []pointer;
        pointer = temp;
        capacity = 2 * capacity;
    }

    void push_back(int value) {
        if (current == capacity)
            doubleCapacity();
        pointer[current++] = value;
    }

    bool pop_back() {
        if (current == 0)
            return false;

        current = current - 1;
        return true;
    }

    T get(int index) {
        if (current > index)
            return pointer[index];
    }

    T& front() {
        return pointer[0];
    }

    T& back() {
        return pointer[current - 1];
    }

    T* begin() {
        return (pointer);
    }

    T* end() {
        return (pointer + size());
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
#endif

    DynamicArray<int> myarr;
    // cout << myarr[4] << endl;
    // cout << myarr.size() << endl;
    // cout << myarr.Cap() << endl;

    myarr.push_back(34);
    myarr.push_back(3);
    myarr.push_back(344);
    myarr.push_back(354);
    myarr.push_back(3544);
    myarr.push_back(78);

    // cout << "Size: " << myarr.size() << endl;
    // cout << "Cap: " << myarr.Cap() << endl;
    // myarr.print();
    // cout << endl;

    // myarr.pop_back();
    // cout << "Size: " << myarr.size() << endl;
    // myarr.print();

    // cout << endl << myarr.get(3) << endl;
    // cout << myarr.begin() << endl;
    // cout << myarr.end() << endl;

    DynamicArray<int> temparr(myarr);
    sort(temparr.begin(), temparr.end());
    temparr.print();



    return 0;
}
