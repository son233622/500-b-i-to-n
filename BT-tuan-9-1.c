#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct File {
    char name[256];      //Tên file
    long size;           //kích thước file
    time_t timestamp;    //thời gian thay đổi file
    struct File *next;   //liên kết đến file tiếp theo
} File;

//Hàm tạo node cho file
File *createFileNode(char* name, long size, time_t timestamp) {
    File *newFile = (File*)malloc(sizeof(File));
    strcpy(newFile->name, name);
    newFile->size = size;
    newFile->timestamp = timestamp;
    newFile->next = NULL;
    return newFile;   
}

//Hàm chèn file theo thứ tự thời gian
void insertFileInorder(File **head, char* name, long size, time_t timestamp) {
    File * newfile = createFileNode(name, size, timestamp);
    if(*head == NULL || (*head)->timestamp > timestamp)
    {
        newfile->next = *head;
        *head = newfile;
    } else {
        File * current = *head;
        while(current->next != NULL && current->next->timestamp <= timestamp)
        {
            current = current->next;
        }
        newfile->next = current->next;
        current->next = newfile;
    }
}

//Hàm tính tổng kích thước các file
long calculateTotalSize(File *head)
{
    long totalSize = 0;
    File *current = head;
    while(current != NULL)
    {
        totalSize += current->size;
        current = current->next;
    }
    return totalSize;
}

//Hàm sao lưu các file vào USB giới hạn dung lượng
void backupFile(File **head, long maxsize)
{
    long totalSize = calculateTotalSize(*head);
    while(totalSize > maxsize)
    {
        // Tìm file có kích thước nhỏ nhất
        File *smallest = *head;
        File *smallestPrev = NULL;
        File *current = *head;
        File *prev = NULL;

        while(current != NULL)
        {
            if(current->size < smallest->size)
            {
                smallest = current;
                smallestPrev = prev;
            }
            prev = current;
            current = current->next;
        }

        //Loại bỏ kích thước file nhỏ nhất
        if(smallestPrev == NULL)
        {
            *head = (*head)->next;
        } else{
            smallestPrev->next = smallest->next;
        }
        totalSize -= smallest->size;
        free(smallest);
    }
}

int main()
{
    File *filelist = NULL;

    //thêm file vào danh sách theo thứ tự thời gian
    time_t t1 = time(NULL) - 3600;    //1 giờ trước
    time_t t2 = time(NULL) - 7200;    //2 giờ trước
    time_t t3 = time(NULL) - 1800;    //30 phút trước

    insertFileInorder(&filelist, "file1.txt", 500, t1);
    insertFileInorder(&filelist, "file2.txt", 1500, t2);
    insertFileInorder(&filelist, "file3.txt", 800, t3);

    printf("Tong kich thuoc cac file: %ld bytes\n", calculateTotalSize(filelist));

    //Sao lưu vào USB dung lượng 1GB
    backupFile(&filelist, 1073741824);
    printf("Sau khi sao luu, tong kich thuoc cac file: %ld bytes\n", calculateTotalSize(filelist));

    return 0;
}