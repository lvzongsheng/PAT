//
//  main.cpp
//  PAT1066
//
//  Created by 吕 宗胜 on 23/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    int height;
    node * left;
    node * right;
}Node;

int getHeight(Node *p){
    if(p==NULL){
        return -1;
    }else{
        return p->height;
    }
}

int max(int a, int b){
    if(a>b) return a;
    else return b;
}

Node* singleRotateWithLeft(Node* T){
    Node * temp;
    temp = T->left;
    T->left = temp->right;
    temp->right = T;
    T->height = max(getHeight(T->left),getHeight(T->right))+1;
    temp->height = max(getHeight(temp->left),T->height)+1;
    return temp;
}

Node* singleRotateWithRight(Node* T){
    Node * temp;
    temp = T->right;
    T->right = temp->left;
    temp->left = T;
    T->height = max(getHeight(T->left),getHeight(T->right))+1;
    temp->height = max(getHeight(temp->right),T->height)+1;
    return temp;
}

Node* doubleRotateWithLeft(Node* T){
    T->left = singleRotateWithRight(T->left);
    return singleRotateWithLeft(T);
}

Node* doubleRotateWithRight(Node* T){
    T->right = singleRotateWithLeft(T->right);
    return singleRotateWithRight(T);
}


Node * insert(int value, Node* T){
    if(T==NULL){
        T = (Node*)malloc(sizeof(Node));
        T->value = value;
        T->height = 0;
        T->left = T->right = NULL;
    }else if(value<T->value){
        T->left = insert(value, T->left);
        if(getHeight(T->left)-getHeight(T->right)==2){
            if(value<T->left->value){
                T = singleRotateWithLeft(T);
            }else{
                T = doubleRotateWithLeft(T);
            }
        }
    }else if(value>T->value){
        T->right = insert(value, T->right);
        if(getHeight(T->right)-getHeight(T->left)==2){
            if(value>T->right->value){
                T = singleRotateWithRight(T);
            }else{
                T = doubleRotateWithRight(T);
            }
        }
    }
    
    T->height = max(getHeight(T->left),getHeight(T->right))+1;
    return T;
}

int main(int argc, const char * argv[])
{

    int n;
    scanf("%d",&n);
    Node* tree;
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        tree = insert(temp, tree);
    }
    printf("%d",tree->value);
    return 0;
}

