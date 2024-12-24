#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
       for(int j = n - 1; j > i; j--)
       {
        if(arr[j] < arr[j - 1])
        {
            swap(arr[j], arr[j - 1]);
        }
       }
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

    cout << "Day so ban dau la : ";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "Day so sau khi xap sep la : ";
    printArray(arr, n);

    return 0;
}