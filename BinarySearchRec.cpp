#include <iostream>
using namespace std;

int binarySearch(int arr[], int beg, int end, int item)
{
    if (beg > end)
        return -1;

    int mid = (beg + end) / 2;

    if (arr[mid] == item)
        return mid;

    if (item < arr[mid])
        return binarySearch(arr, beg, mid - 1, item);

    return binarySearch(arr, mid + 1, end, item);
}

int main()
{
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Array size must be a positive integer." << endl;
        return 0;
    }

    int* arr = new int[n];

    cout << "Enter " << n << " elements in sorted order: ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int item;
    cout << "Enter the element to search: ";
    cin >> item;

    int loc = binarySearch(arr, 0, n - 1, item);

    if (loc == -1)
        cout << "Element not found" << endl;
    else
        cout << "Element found at index " << loc << endl;

    delete[] arr;

    return 0;
}