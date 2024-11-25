#include <stdio.h>

//hàm hợp nhất 2 nửa đã được sắp xếp
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1; //Số phần tử của mảng con trái
    int n2 = right - mid; // Số phần tử của mảng con phải

    // Tạo 2 mảng con mới
    int L[n1], R[n2];
    
    // Copy dữ liệu vào 2 mảng con
    for(int i = 0; i < n1; i++)
    {
        L[i] = arr[left + 1];
    }
    for(int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    // Hợp nhất 2 mảng tạm về arr[]
    int i = 0; // Chỉ số ban đầu của mảng con trái
    int j = 0; // Chỉ số ban đầu của mảng con phải
    int k = left; //Chỉ số ban đàu của mảng hợp nhất

    while(i < n1 && j < n2)
    {
        if(L[i] < R[j])
        {
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Sao chếp các phân tử còn lại của L{[], nếu có
    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại của R[], nếu có
    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Hàm sắp xếp sử dụng phương pháp merge sort
void mergeSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;  // Tìm chỉ số giữa

        //Gọi đệ quy để chia đôi mảng
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Hợp nhất hai nửa đã được sắp xếp
        merge(arr, left, mid, right);
    }
}

// In mảng ra màn hình
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

    printf("Array before sorting: ");
    printArry(arr, n);

    mergeSort(arr, 0, n - 1);
    printf("Array after sorting: ");
    printArry(arr, n);
    
    return 0;
}