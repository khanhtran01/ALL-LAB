#include <iostream>
using namespace std;

void reheapDown(int maxHeap[], int numberOfElements, int index)
{
    if (index < 0)
        return;
    if (index > numberOfElements)
        return;
    if (index * 2 + 1 <= numberOfElements && index * 2 + 2 > numberOfElements)
    {
        if (maxHeap[index] > maxHeap[index * 2 + 1])
        {
            swap(maxHeap[index], maxHeap[index * 2 + 1]);
        }
    }
    if (index * 2 + 2 <= numberOfElements)
    {
        int newIndex;
        int *p;
        if (maxHeap[index * 2 + 1] > maxHeap[index * 2 + 2])
        {
            newIndex = index * 2 + 1;
            p = &maxHeap[index * 2 + 1];
        }
        else
        {
            newIndex = index * 2 + 2;
            p = &maxHeap[index * 2 + 2];
        }
        
        if (*p > maxHeap[index])
        {
            swap(*p, maxHeap[index]);
            reheapDown(maxHeap, numberOfElements, newIndex);
        }
    }
}
void reheapUp(int maxHeap[], int numberOfElements, int index)
{
    if (index <= 0)
        return;
    if (index > numberOfElements)
        return;
    if (index != 0)
    {
        if (maxHeap[index] >= maxHeap[(index - 1) / 2])
        {
            swap(maxHeap[index], maxHeap[(index - 1) / 2]);
            reheapUp(maxHeap, numberOfElements, (index - 1) / 2);
        }
    }
}

int main()
{
    int index = 0;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int numE = sizeof(arr) / sizeof(int);
index = 4;
    reheapUp(arr, numE, index);
index = 0;
    reheapDown(arr, numE, index);
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        cout << arr[i] << " ";
    }
}