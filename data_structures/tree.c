#include <stdio.h>
#include <stdlib.h>

typedef struct node{
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
        if(){

        }else{

        }
    }
}