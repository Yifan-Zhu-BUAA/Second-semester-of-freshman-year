#include <stdio.h>
#include <stdlib.h>

//data多的时候可以按照下面的来

struct node
{
    struct data
    {
        int n;
        int time;
    } data;
    struct node *next;
};

// 定义链表节点
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 创建新节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(-1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 添加节点到链表的末尾
void addNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if(*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// 从链表中删除节点
void deleteNode(Node** head, int key) {
    Node* temp = *head, *prev;
    if(temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

// 修改链表中的节点
void modifyNode(Node* node, int oldData, int newData) {
    while(node != NULL) {
        if(node->data == oldData) {
            node->data = newData;
        }
        node = node->next;
    }
}

// 在链表中查找节点
Node* searchNode(Node* head, int data) {
    Node* current = head;
    while(current != NULL) {
        if(current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main()
{
    printf("1");
}
