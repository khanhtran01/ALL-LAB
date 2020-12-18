#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
template <typename T>
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
    bool isEmpty()
    {
        return (count) ? 1 : 0;
    }
    bool contains(T item)
    {
        for (int i = 0; i < count; i++)
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
    int size()
    {
        return count;
    }

    void push(T item)
    {
        ensureCapacity(count + 1);

        elements[count] = item;
        reheapUp(count);

        count++;
    }
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]";
    }
    int getItem(T item);
    void remove(T item);
    void clear();

private:
    void ensureCapacity(int minCapacity)
    {
        if (minCapacity >= capacity)
        {
            T *newElements = new T[capacity += 10];
            for (int i = 0; i < count; i++)
            {
                newElements[i] = elements[i];
            }
            delete[] elements;
            elements = newElements;
        }
    }

    void reheapDown(int index)
    {
        if (index < 0)
            return;
        if (index > count)
            return;
        if (index * 2 + 1 <= count && index * 2 + 2 > count)
        {
            if (elements[index] > elements[index * 2 + 1])
            {
                swap(elements[index], elements[index * 2 + 1]);
            }
        }
        if (index * 2 + 2 <= count)
        {
            int newIndex;
            int *p;
            if (elements[index * 2 + 1] > elements[index * 2 + 2])
            {
                newIndex = index * 2 + 1;
                p = &elements[index * 2 + 1];
            }
            else
            {
                newIndex = index * 2 + 2;
                p = &elements[index * 2 + 2];
            }

            if (*p > elements[index])
            {
                swap(*p, elements[index]);
                reheapDown(newIndex);
            }
        }
    }

    void reheapUp(int position)
    {
        if (position <= 0)
            return;
        if (position > count)
            return;
        if (position != 0)
        {
            if (elements[position] >= elements[(position - 1) / 2])
            {
                swap(elements[position], elements[(position - 1) / 2]);
                reheapUp((position - 1) / 2);
            }
        }
    }
};

template <class T>
int Heap<T>::getItem(T item)
{
    // TODO: return the index of item in heap
    for (int i = 0; i < count; i++)
    {
        if (elements[i] == item)
            return i;
    }
    return -1;
}

template <class T>
void Heap<T>::remove(T item)
{
    // TODO: remove the element with value equal to item
    int index = getItem(item);
    if (index == -1)
        return;
    else
    {
        swap(elements[index], elements[count - 1]);
        int * newElements = new int[this->capacity];
        for (int i = 0 ; i < count - 1; i++)
        {
            newElements[i] = elements[i];
        }
        delete[] elements;
        this->elements = newElements;
        reheapDown(index);
        count--;
    }
}

template <class T>
void Heap<T>::clear()
{
    // TODO: delete all elements in heap
    delete[] elements;
    elements = nullptr;
    count = 0;
}
int main()
{
    Heap<int> maxHeap;
    int arr[] = {42, 35, 30, 15, 20, 21, 18, 3, 7, 14};
    for (int i = 0; i < 10; i++)
        maxHeap.push(arr[i]);
    maxHeap.printHeap();
    cout << '\n';
    maxHeap.remove(42);
    maxHeap.remove(35);
    maxHeap.remove(30);
    maxHeap.printHeap();
}
