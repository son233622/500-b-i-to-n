#include <stdio.h>
#include <stdlib.h>

// Cấu trức để lưu trữ các phần tử của đa thức
typedef struct Node{
    int heso; // Hệ số
    int bac; // Bậc
    struct Node* next;
} Node;

// Hàm tạo 1 nút mới
Node* createNode(int heso, int bac)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->heso = heso;
    newNode->bac = bac;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm phần tử vào đa thức
void insertTerm(Node** head, int heso, int bac)
{
    if(heso == 0)
    {
        return; // Bỏ qua phần tử nếu hệ số bằng 0
    }

    Node* newNode = createNode(heso, bac);
    
    if(*head == NULL) // Nếu danh sách trống
    {
        *head = newNode;
    }else // Chèn vào cuối danh sách
    {
        Node* temp = *head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Hàm in đa thức
void printPolynomial(Node* head)
{
    if(head == NULL)
    {
        printf("0");
        return;
    }

    Node* temp = head;
    while(temp != NULL)
    {
        if(temp != head && temp->heso > 0)
        {
            printf(" + ");
        }

        printf("%dx^%d", temp->heso, temp->bac);
        temp = temp->next;
    }
}

// Hàm giải phóng bộ nhớ của danh sách
void freeList(Node** head)
{
    Node* temp;
    while(*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main()
{
    Node* Polynomial = NULL;
    int heso, bac;

    printf("Nhap da thuc ( he so vaf bac). Nhap he so 0 de dung.\n");
    while(1)
    {
        printf("Nhap he so: ");
        scanf("%d", &heso);
        if(heso == 0)
        {
            break;
        }

        printf("Nhap bac: ");
        scanf("%d", &bac);

        insertTerm(&Polynomial, heso, bac);
    }

    printf("Da thuc vua nhap la: ");
    printPolynomial(Polynomial);
    printf("\n");

    // Giải phóng bộ nhớ
    freeList(&Polynomial);

    return 0;
}