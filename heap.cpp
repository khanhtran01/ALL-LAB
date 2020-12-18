#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
template <class T>
class Heap
{
protected:
    T *elements;
    int capacity;
    int count;

public:
    Heap()
    {
        this->capacity = 10;
        this->count = 0;
        this->elements = new T[capacity];
    }
    ~Heap()
    {
        delete[] elements;
    }
    void push(T item);
    void clear();

    bool isEmpty()
    {
        return (count) ? 1 : 0;
    }
    bool contains(T item)
    {
        for (int i = 0; i< count; i++)
        {
            if (elements[i] == item)
            return 1;
        }
        return 0;
    }
    T peek()
    {
        if (elements)
        return elements[0];
    }
    bool pop()
    {
        if (elements == nullptr) return false;
        else
        {
            swap(elements[0], elements[count - 1]);
            reheapDown(0);
            count--;
            return true;
        }
    }
    int size()
    {
        return count;
    }

    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]\n";
    }

private:
    void ensureCapacity(int minCapacity);
    void reheapUp(int position);
    void reheapDown(int position);
};
int main()
{
    Heap<int> maxHeap;
    for (int i = 0; i < 10; i++)
    {
        maxHeap.push(i);
    }
    cout << maxHeap.size();
}