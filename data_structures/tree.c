#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* right;
    struct Node* left;
}Node;

Node* craeteNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}
Node* insertNode(Node* root,int data){
    if(root==NULL){
        craeteNode(data);
    } else {
        if(data <= root->data){
            root->left = insertNode(root->left,data);
        }else{
            root->right = insertNode(root->right,data);
        }
    }
}
Node* deleteNode(Node* a){

}

void preorderTraversal(Node* root){
    if(root != NULL){
        printf("%d、",root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
void inorderTraversal(Node* root){
    if(root != NULL){
        inorderTraversal(root->left);
        printf("%d、",root->data);
        inorderTraversal(root->right);
    }
}
void postorderTraversal(Node* root){
    if(root != NULL){
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d、",root->data);
    }
}
void freeTree(Node* root){
    if(root!=NULL){
        freeTree(root->left);
        freeTree(root->left);
        free(root);
    }
}
int main(){
    Node* root = NULL;

    root = insertNode(root,8);
    root = insertNode(root,3);
    root = insertNode(root,10);
    root = insertNode(root, 1);
    root = insertNode(root, 6);
    root = insertNode(root, 14);
    root = insertNode(root, 4);
    root = insertNode(root, 7);
    root = insertNode(root, 13);

    printf("前順: ");
    preorderTraversal(root);
    printf("\n");

    printf("中順: ");
    inorderTraversal(root);
    printf("\n");

    printf("後順: ");
    postorderTraversal(root);
    printf("\n");

    // メモリを解放
    freeTree(root);

    return 0;
}