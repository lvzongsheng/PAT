//
//  main.cpp
//  EN1043
//  http://pat.zju.edu.cn/contests/pat-a-practise/1043
//  Solutions：
//  首先要判断该树是BST还是mirror image of BST。一旦树是偏斜的，就很难根据值的大小来判断是BST还是mirror of BST，所以要遍历两次，分别为BST和mirror of BST。
//  其次重要的是判断左子树和右子树的起始和终止位置，根据BST的特性，这个容易找到，要注意的是当该树偏斜的时候，该终止位置为最后一个元素。
//  要得到树的后序遍历，可以把root压栈，然后右子树，再左子树。
//  Created by 吕 宗胜 on 6/9/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <stack>
using namespace std;

int node[1000];
bool result = true;
bool isMirror = false;
stack<int> tree;

void isTrue(int begin, int end, bool isMirror){
    int root;
    if(begin>end){
        return;
    }else if(begin==end){
        root = node[begin];
        tree.push(root);
        return;
    }else{
        root = node[begin];
        tree.push(root);
    }
   
    int rend=0;
    int i=0;
    for(i=begin+1;i<=end;i++){
        if(isMirror){
            if(node[i]<root){
                rend = i-1;
                break;
            }
        }else{
            if(node[i]>=root){
                rend = i-1;
                break;
            }
        }
    }
    if(i>end){
        rend = end;
    }
    
    for(int i=rend+1;i<=end;i++){
        if(isMirror&&node[i]>=root){
            result = false;
        }else if (!isMirror&&node[i]<root){
            result = false;
        }
    }
    
    if(result){
        isTrue(rend+1, end, isMirror);
        isTrue(begin+1, rend, isMirror);
    }

}

int main(int argc, const char * argv[])
{

    int number;
    scanf("%d",&number);
    
    for(int i=0;i<number;i++){
        scanf("%d",&node[i]);
    }
    
    isTrue(0, number-1, false);
    if(!result){
        result = true;
        while (!tree.empty()){
            tree.pop();
        }
        isTrue(0,number-1,true);
    }
    
    if(!result){
        printf("NO");
    }else{
        printf("YES\n");
        bool f = false;
        while(!tree.empty()){
            if(!f){
                printf("%d",tree.top());
                f = true;
            }else{
                printf(" %d",tree.top());
            }
            
            tree.pop();
        }
    }
    
    return 0;
}