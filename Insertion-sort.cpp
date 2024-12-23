#include <iostream>

using namespace std;

void insertionSort(int arr[], int n)
{
    for( int i = 0; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {32, 51, 27, 83, 66, 11, 45, 75};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Day so ban dau la: ";
    printArray(arr, n);

    insertionSort(arr, n);

    cout << "Day so sau khi xap sep la : ";
    printArray(arr, n);

    return 0;
}