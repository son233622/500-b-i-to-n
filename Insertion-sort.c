#include <stdio.h>

void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // di chuyển các phần tử lớn hơn về phái sau
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1]= key;
    }   
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {32, 51, 27, 83, 66, 11, 45, 75};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting: ");
    printArray(arr, n);

    InsertionSort(arr, n);
    printf("Array after sorting: ");
    printArray(arr, n);
    return 0;
}