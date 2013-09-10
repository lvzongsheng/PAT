//
//  main.cpp
//  EN1020
//  http://pat.zju.edu.cn/submissions/201060
//  Solutions:
//  后序遍历可以确定root节点，而中序遍历可以确定左右子树。不过重点在于此题写法上要小心为上，不然小问题很多。
//  Created by 吕 宗胜 on 6/9/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

int postorder[30];
int inorder[30];
int postcount;
typedef struct node{
    int id;
    struct node* left;
    struct node* right;
}Tree;

queue<Tree> result;

Tree* buildtree(int begin, int end){
    if(begin>end)
        return NULL;
    Tree* t = (Tree*)malloc(sizeof(Tree));
    t->id = postorder[postcount];
    t->left = NULL;
    t->right = NULL;
    postcount--;
    for(int j=begin;j<=end;j++){
        if(inorder[j]==postorder[postcount+1]){
            t->right = buildtree(j+1,end);
            t->left = buildtree(begin,j-1);
            break;
        }
    }
    return t;
}



int main(int argc, const char * argv[])
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++){
        scanf("%d",&postorder[i]);
    }
    for(int i=0;i<number;i++){
        scanf("%d",&inorder[i]);
    }
    
    postcount = number-1;
    Tree* tr = buildtree(0,number-1);
    
    result.push(*tr);
    bool flag = true;
    while(!result.empty()){
        Tree tt = result.front();
        result.pop();
        if(tt.left!=NULL) result.push(*tt.left);
        if(tt.right!=NULL) result.push(*tt.right);
        if(flag){
            printf("%d",tt.id);
            flag = false;
        }
        else{
            printf(" %d",tt.id);
        }
    }
    
    return 0;
}

