#include <iostream>
using namespace std;
    int binarySearch(int arr[], int left, int right, int x)
    {
        if (x > arr[left + (right - left) / 2])
        {
            cout << "We traverse on index: " <<left + (right - left) / 2 << '\n';
            if (right >left)
            return binarySearch(arr,left + (right - left) / 2 + 1, right, x);
            return -1;
        }
        else if (x < arr[left + (right - left) / 2])
        {
            cout << "We traverse on index: " <<left + (right - left) / 2 << '\n';
            if (right> left)
            return binarySearch(arr, left,left + (right - left) / 2 - 1, x);
            return -1;
        }
        cout << "We traverse on index: " <<left + (right - left) / 2 << '\n';
        return left +(right - left) / 2;
    }
int main()

{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
}