#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
//ノードの作成
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 先頭に追加
void addFirst(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// 末尾に追加
void addLast(Node** head, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}
//nodeを削除
void deleteNode(Node** head,int data){
    if(*head==NULL){
        return;
    }
    if((*head)->data==data){
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    Node* current = *head;
    Node* prev = NULL;
    while(current!=NULL&&current->data!=data){
        prev=current;
        current = current->next;
    }
    if(current==NULL){
        return;
    }
    prev->next = current->next;
    free(current);
    return;
}

// リストを一覧表示
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// リストを解放
void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Node* myList = NULL;

    addLast(&myList, 10);
    addLast(&myList, 20);
    addFirst(&myList, 5);
    addFirst(&myList, 2);
    printf("List: ");
    printList(myList);

    deleteNode(&myList,2);
    printf("List: ");
    printList(myList);

    freeList(myList);

    return 0;
}
