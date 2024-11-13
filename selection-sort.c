#include <stdio.h>

void selectionSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        
        // Hoán đổi phần tử nhở nhất với phần tử đầu tiên chưa xắp sếp
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int n)
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

    printf("Day so ban dau: ");
    printArray(arr, n);
    
    selectionSort(arr, n);

    printf("Day so sau khi sap xep: ");
    printArray(arr, n);

    return 0;
}