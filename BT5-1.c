/*Yêu cầu bài toán: Nhập vào n đối tượng có màu đỏ (red), trắng (white) và xanh (blue), sắp xếp theo trật tự như sau: các đối tượng cùng mầu nằm kế tiếp nhau và theo thứ tự đỏ, trắng, xanh.
Input {xanh, đỏ, xanh, đỏ, đỏ, trắng, đỏ, xanh, trắng}
Output {đỏ, đỏ, đỏ, đỏ, trắng, trắng, xanh, xanh, xanh}
Gợi ý:
Có thể mã hóa các mầu bằng các số nguyên 0, 1, 2 để biểu diễn lần lượt mầu đỏ, trắng và xanh tương ứng.
Chú ý: Không sử dụng các thư viện hàm sắp xếp có sẵn để giải quyết bài toán trên khi cài đặt chương trình*/

#include <stdio.h>

// Hàm sắp xếp màu sắc theo thứ tự đỏ trắng xanh (0, 1, 2) 
void sapxepmausac(int arr[], int n)
{
    int left = 0, mid = 0, right = n - 1;

    while(mid <= right)
    {
        if(arr[mid] == 0) // màu đỏ (0)
        {
            int temp = arr[left];
            arr[left] = arr[mid];
            arr[mid] = temp;
            left++;
            mid++;
        }else if(arr[mid] == 1){ // màu trắng (1)
            mid++;

        }else{ // màu xanh (2)
            int temp = arr[mid];
            arr[mid] = arr[right];
            arr[right] = temp;
            right--;
        }

    }
}

// Hàm in mảng
void inmang(int arr[], int n)
{
    for(int i = 0; i < n; i ++)
    {
        if(arr[i] == 0)
        {
            printf("do ");
        }
        else if(arr[i] == 1)
        {
            printf("trang ");
        }
        else
        {
            printf("xanh ");
        }
    }
    printf("\n");
}

int main()
{
    int arr[] = {2, 0, 2, 0, 0, 1, 0, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Mang truoc khi sap xep: \n");
    inmang(arr, n);

    sapxepmausac(arr, n);
    printf("Mang sau khi sap xep: \n");
    inmang(arr, n);
    
    return 0;
}