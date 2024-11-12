#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SentenceNode {
    char word[256];                 //Từ trong câu
    struct SentenceNode *next;      //Liên kết đến từ tiếp theo
} SentenceNode;

//Hàm tạo Node cho từ
SentenceNode* createWordNode(char* word)
{
    SentenceNode *newNode = (SentenceNode*) malloc(sizeof(SentenceNode));
    strcpy(newNode->word, word);
    newNode->next = NULL;
    return newNode;
}

//Hàm thêm từ vào danh sách
void addword(SentenceNode **head, char* word)
{
    SentenceNode *newNode = createWordNode(word);
    newNode->next = *head;
    *head = newNode;
}

//Hàm tìm từ xuất hiện nhiều nhất trong câu
char* findMostFrequentWord(SentenceNode *head)
{
    SentenceNode *current = head;
    char *mostFrequentWord = NULL;
    int maxCount = 0;

    while(current != NULL)
    {
        int count = 0;
        SentenceNode *temp = head;
        while(temp != NULL)
        {
            if(strcmp(current->word, temp->word) == 0)
            {
                count++;
            }
            temp = temp->next;
        }
        if(count > maxCount)
        {
            maxCount = count;
            mostFrequentWord = current->word;
        }
        current = current->next;
    }
    return mostFrequentWord;
}

//Hàm loại bỏ từ láy
void removeDuplicateWord(SentenceNode **head)
{
    SentenceNode *current = *head;
    while(current != NULL && current->next != NULL)
    {
        if(strcmp(current->word, current->next->word) == 0)
        {
            SentenceNode *temp = current->next;
            current->next = temp->next;
            free(temp);
        } else{
            current = current->next;
        }
    }
}

//Hàm đếm số từ vựng trong câu 
int countUniqueWord(SentenceNode *head)
{
    int uniqueCount = 0;
    SentenceNode *current = head;

    while(current != NULL)
    {
        int isUnique = 1;
        SentenceNode *temp = head;
        while(temp != current)
        {
            if(strcmp(current->word, temp->word) == 0)
            {
                isUnique = 0;
                break;
            }
            temp = temp->next;
        }
        if(isUnique)
        {
            uniqueCount++;
        }
        current = current->next;
    }
    return uniqueCount;
}

int main()
{
    SentenceNode *sentencelist = NULL;

    //Thêm các từ vào dánh sách
    addword(&sentencelist, "xanh");
    addword(&sentencelist, "xanh");
    addword(&sentencelist, "bien");
    addword(&sentencelist, "troi");
    addword(&sentencelist, "xanh");

    //Xác định từ xuất hiện nhiều nhất
    printf("tu xuat hien nhieu nhat la: %s\n", findMostFrequentWord(sentencelist));

    //Loại bỏ từ láy
    removeDuplicateWord(&sentencelist);

    //Đếm số từ vựng khác nhau 
    printf("So tu vung khac nhau: %d\n", countUniqueWord(sentencelist));


    return 0;
}
