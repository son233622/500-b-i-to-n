#include <stdio.h>

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Hàm phân đoạn (partition)
int Partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Chọn phần tử cuối làm pivot
    int i = (low - 1); // chỉ số cảu phần tử nhỏ hơn pivot

    for(int j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1; // vị trí pivot
}

// Hàm sắp xếp QuickSort

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = Partition(arr, low, high); // Chỉ số của pivot sau khi phân đoạn

        quickSort(arr, low, pi - 1); // Sắp xếp các phần tử trước pivot
        quickSort(arr, pi + 1, high); // Sắp xếp các phần tử sau pivot
    }
}

// Hàm in mảng
void printArry(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {32, 51, 27, 83, 66, 11, 45, 75};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sotring: ");
    printArry(arr, n);

    quickSort(arr, 0, n - 1);
    printf("Array after sorting: ");
    printArry(arr, n);
    return 0;
}