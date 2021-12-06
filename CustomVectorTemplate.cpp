#include <queue>
#include <set>
#include <unordered_set>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
using namespace std;
#define ll long long int
#define mod 1000000007
#define endl '\n'
#define loop(i, range) for(int i = 0; i < range; i++)
#define loop1(i, start, end) for(int i = start; i <= end; i++)
#define pb emplace_back
#define ppb pop_back
#define mp make_pair

template<typename T>
class MyVector
{
public:
    typedef T* iterator;

    MyVector();
    MyVector(unsigned int size);
    MyVector(unsigned int size, const T &init);
    MyVector(const MyVector<T> &v);
    ~MyVector();

    unsigned int capacity() const;
    unsigned int size() const;
    bool empty() const;
    iterator begin();
    iterator end();
    T & front();
    T & back();
    void push_back(const T &data);
    void pop_back();

    void reserve(unsigned int capacity);
    void resize(unsigned int size);

    T &operator[](unsigned int index);
    MyVector<T> &operator=(const MyVector<T> &);
    void clear();

private:
    unsigned int my_size;
    unsigned int my_capacity;
    T* buffer;
};

template<class T>
MyVector<T>::MyVector()
{
    my_capacity = 0;
    my_size = 0;
    buffer = 0;
}

template<class T>
MyVector<T>::MyVector(const MyVector<T> &v)
{
    my_size = v.my_size;
    my_capacity = v.my_capacity;
    buffer = new T[my_size];
    for (int i = 0; i < my_size; i++)
        buffer[i] = v.buffer[i];
}


template<class T>
MyVector<T>::MyVector(unsigned int size)
{
    my_capacity = size;
    my_size = size;
    buffer = new T[size];
}

template<class T>
MyVector<T>::MyVector(unsigned int size, const T & init)
{
    my_size = size;
    my_capacity = size;
    buffer = new T[size];
    for (int i = 0; i < size; i++)
        buffer[i] = init;
}

template<class T>
MyVector<T> &MyVector<T>::operator = (const MyVector<T>&v)
{
    delete [] buffer;
    my_size = v.my_size;
    my_capacity = v.my_capacity;
    buffer = new T[my_size];
    for (unsigned int i = 0; i < my_size; i++)
        buffer[i] = v.buffer[i];

    return *this;
}


template<class T>
typename MyVector<T>::iterator MyVector<T>::begin()
{
    return buffer;
}

template<class T>
typename MyVector<T>::iterator MyVector<T>::end()
{
    return buffer + size();
}

template<class T>
T& MyVector<T>::front()
{
    return buffer[0];
}

template<class T>
T& MyVector<T>::back()
{
    return buffer[my_size - 1];
}

template<class T>
void MyVector<T>::push_back(const T &v)
{
    if (my_size >= my_capacity)
        reserve(my_capacity + 5);
    buffer[my_size++] = v;
}

template<class T>
void MyVector<T>::pop_back()
{
    my_size--;
}

template<class T>
void MyVector<T>::reserve(unsigned int capacity)
{
    if (buffer == 0) {
        my_size = 0;
        my_capacity = 0;
    }

    T* NewBuffer = new T[capacity];

    unsigned int l_size = capacity < my_size ? capacity : my_size;

    for (unsigned int i = 0; i < l_size; i++)
        NewBuffer[i] = buffer[i];

    my_capacity = capacity;
    delete[] buffer;
    buffer = NewBuffer;
}

template<class T>
unsigned int MyVector<T>::size() const//
{
    return my_size;
}

template<class T>
unsigned int MyVector<T>::capacity() const//
{
    return my_capacity;
}

template<class T>
void MyVector<T>::resize(unsigned int size)
{
    reserve(size);
    my_size = size;
}

template<class T>
T& MyVector<T>::operator[](unsigned int index)
{
    return buffer[index];
}

template<class T>
MyVector<T>::~MyVector()
{
    delete[] buffer;
}

template<class T>
void MyVector<T>::clear()
{
    my_capacity = 0;
    my_size = 0;
    buffer = 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
#endif

    MyVector<int> v;
    cout << v.capacity() << endl;
    // cout << v.size() << endl;
    v.push_back(34);
    cout << v.size() << endl;
    cout << v.capacity() << endl;

    auto x = 206;
    while (x--)
        v.push_back(x);

    cout << v.capacity() << endl;








    return 0;
}