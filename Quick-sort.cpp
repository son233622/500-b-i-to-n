#include <iostream>

using namespace std;

//Hàm phân đoạn
int partitionFunc(int arr[], int left, int right)
{
    int pivot = left;
    int i = left + 1;
    int j = right;

    while(i <= j)
    {
        while(i <= j && arr[i] < arr[pivot])
        {
            i++;
        }
        while(i <= j && arr[j] > arr[pivot])
        {
            j--;
        }
        if(i < j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    swap(arr[pivot], arr[j]);
    return j;
}

void quickSort(int arr[], int left, int right)
{
    if(left >= right)
    {
        return;
    }

    int partition = partitionFunc(arr, left, right);

    quickSort(arr, left, partition - 1);
    quickSort(arr, partition + 1, right);
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
    printArray(arr,n);

    quickSort(arr, 0, n - 1);

    cout << "Day so sau khi xap sep la : ";
    printArray(arr, n);
    
    return 0;
}