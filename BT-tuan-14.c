#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


// Định nghĩa cấu trức một Node cây
typedef struct Node {
    char data[10];
    struct Node *left;
    struct Node *right;
}Node;

// Hàm tạo Node mới
Node* createNode(const char *data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Hàm kiểm tra cây có rỗng hay không
int isempty(Node* root)
{
    return root == NULL;
}

// Trung tố
void printInfix(Node* root)
{
    if (root == NULL) return;
    if (root->left || root->right) printf("(");
    printInfix(root->left);
    printf("%s", root->data);
    printInfix(root->right);
    if (root->left || root->right) printf(")");
}

// Hậu tố

void printPostfix(Node* root)
{
    if (root == NULL) return;
    printPostfix(root->left);
    printPostfix(root->right);
    printf("%s ", root->data);
}

// Tiền tố

void printPrefix(Node* root)
{
    if (root == NULL) return;
    printf("%s ", root->data);
    printPrefix(root->left);
    printPrefix(root->right);
}

// xây dựng biểu thức
Node* biuldTree()
{
    Node* a = createNode("a");
    Node* five = createNode("5");
    Node* mul1 = createNode("*");
    mul1->left = a;
    mul1->right = five;

    Node* b = createNode("b");
    Node* c = createNode("c");
    Node* six = createNode("6");
    Node* pow1 = createNode("^");
    pow1->left = c;
    pow1->right = six;


    Node* div1 = createNode("/");
    div1->left = pow1;
    Node* d = createNode("d");
    div1->right = d;

    Node* mul2 = createNode("*");
    mul2->left = b;
    mul2->right = div1;

    Node* sub1 = createNode("-");
    sub1->left = mul1;
    sub1->right = mul2;

    Node* h = createNode("h");
    Node* f = createNode("f");
    Node* sub2 = createNode("-");
    sub2->left = h;
    sub2->right = f;

    Node* one = createNode("1");
    Node* two = createNode("2");
    Node* div2 = createNode("/");
    div2->left = one;
    div2->right = two;

    Node* pow2 = createNode("^");
    Node* e = createNode("e");
    pow2->left = e;
    pow2->right = div2;

    Node* mul3 = createNode("*");
    mul3->left = sub2;
    mul3->right = pow2;

    Node* add = createNode("+");
    add->left = sub1;
    add->right = mul3;

    return add;   

}

int main()
{
    // Xây dựng biểu thức
    Node* expressionTree = biuldTree();

    // In biểu thức theo trung tố
    printf("Prefix notation: ");
    printPrefix(expressionTree);
    printf("\n");

    // In biểu thức theo hậu tố 
    printf("Postfix notation: ");
    printPostfix(expressionTree);
    printf("\n");

    // In biểu thức theo tiền tố
    printf("Infix notation: ");
    printInfix(expressionTree);
    printf("\n");

    return 0;
}