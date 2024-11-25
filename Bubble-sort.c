#include <stdio.h>

void BubbleSort(int arr[], int n)
{
    for(int i = 0; i < n - 2; i++)
    {
        for(int j = n - 1;j > i; j--)
        {
            if(arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

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
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting: ");
    printArry(arr, n);

    BubbleSort(arr, n);
    printf("Array after sorting: ");
    printArry(arr, n);

    return 0;
}