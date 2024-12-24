#include <iostream>

using namespace std;
//Hàm hợp nhất hai nửa mảng đã được xắp sếp
void mergeArrays(int arr[], int m, int n, int p)
{
    int i = m, j = n + 1;
    int temp[p - m + 1];
    int k = 0;

    //Hợp nhất hai nửa mảng
    while(i <= n && j <= p)
    {
        if(arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
        }
    }

    //Sao chép các phần tử còn lại vào nửa đầu ̣( nếu có )
    while(i <= n)
    {
        temp[k++] = arr[i++];
    }

    //Sao chếp các phân tử còn lại của nửa sau (nếu có)
    while(j <= p)
    {
        temp[k++] = arr[j++];
    }

    //Ghi đè các phần tử đã sắp xếp từ mảng tạm vào mảng gốc
    for(int i = m, k = 0; i <= p; i++, k++)
    {
        arr[i] = temp[k];
    }
}

//Hàm đệ quy chia mảng thành các nửa nhỏ và hợp nhất
void splitMerge(int arr[], int first, int last)
{
    if(first >= last)
    {
        return;
    }

    int m = (first + last) / 2;

    //Đệ quy chia nửa trái
    splitMerge(arr, first, m);

    //Đệ quy chia nửa phải
    splitMerge(arr, m + 1, last);

    //Hợp nhất hai nửa
    mergeArrays(arr, first, m, last);
}

void mergeSort(int arr[], int n)
{
    if(n < 2)
    {
        return;
    }

    splitMerge(arr, 0, n - 1);
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

    mergeSort(arr, n);

    cout<< "Day so sau khi sap xep la : ";
    printArray(arr, n);

    return 0;
}