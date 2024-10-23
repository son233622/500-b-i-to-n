#include <stdio.h>

#define max_rows 100  // Giới hạn tối đa cho số hàng

int main() 
{
    int rows;  
    int max_sinh, min_sinh;

    // Nhập số hàng của mảng (không vượt quá max_rows)
    do {
        printf("Nhap so hang toi da cua mang (toi da %d): ", max_rows);
        scanf("%d", &rows);
    } while (rows > max_rows || rows <= 0);

    // Tạo danh sách gồm năm sinh và số lượng người sinh ra
    int array[max_rows][2];
    int visited[max_rows] = {0};  // Mảng đánh dấu các phần tử đã kiểm tra

    // Nhập giá trị cho danh sách
    printf("Nhap cac du lieu cho danh sach:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    // Tìm và in các năm có số lượng người sinh ra bằng nhau
    printf("Cac nam co so luong nguoi sinh ra bang nhau:\n");
    for (int i = 0; i < rows; i++) {
        if (visited[i]) {
            continue;  // Nếu đã kiểm tra, bỏ qua
        }
        int count = 0;  // Đếm số lượng giá trị bằng nhau
        int values[max_rows];  // Lưu các giá trị tương ứng ở cột 1
        values[count++] = array[i][0];  
        visited[i] = 1; 

        for (int j = i + 1; j < rows; j++) {
            if (array[i][1] == array[j][1]) {
                values[count++] = array[j][0];  // Thêm giá trị cột 1 tương ứng
                visited[j] = 1;  // Đánh dấu đã kiểm tra
            }
        }

        if (count > 1) {  // Chỉ in nếu có nhiều hơn 1 giá trị bằng nhau
            printf("So luong nguoi sinh ra %d xuat hien %d lan vao cac nam: ", array[i][1], count);
            for (int k = 0; k < count; k++) {
                printf("%d ", values[k]);
            }
            printf("\n");
        }
    }

    // tìm min, max sinh
    min_sinh = array[0][1];
    max_sinh = array[0][1];

    for(int i = 1; i < rows; i++) 
    {
        if (array[i][1] < min_sinh) 
        {
            min_sinh = array[i][1]; // Cập nhật min nếu tìm thấy giá trị nhỏ hơn
        }
        if (array[i][1] > max_sinh) 
        {
            max_sinh = array[i][1]; // Cập nhật max nếu tìm thấy giá trị lớn hơn
        }
    }

    // In các năm có số lượng người sinh ra lớn nhất
    printf("So luong nguoi sinh ra lon nhat la: %d vao cac nam: ", max_sinh);
    for (int i = 0; i < rows; i++) 
    {
        if (array[i][1] == max_sinh) 
        {
            printf("%d ", array[i][0]);
        }
    }
    printf("\n");
    
    // In các năm có số lượng người sinh ra ít nhất
    printf("So luong nguoi sinh ra it nhat la: %d vao cac nam: ", min_sinh);
    for (int i = 0; i < rows; i++) 
    {
        if (array[i][1] == min_sinh) 
        {
            printf("%d ", array[i][0]);
        }
    }

    return 0;
}
