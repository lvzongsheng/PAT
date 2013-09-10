//
//  main.cpp
//  PAT1004
//  http://pat.zju.edu.cn/contests/pat-a-practise/1004
//  Solutions:
//  此题在于如何构建树，如果陷入传统的链式结构，将会比较麻烦，所以可以使用数组来表示树结构
//  另外使用队列来遍历树，此时可以层次遍历树的结构，与题意相符。
//  Created by 吕 宗胜 on 3/9/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

int main(int argc, const char * argv[])
{
    int tree[100];
    
    int treenode, nonleafnode;
    scanf("%d %d",&treenode,&nonleafnode);
    
    for(int i=0;i<nonleafnode;i++){
        int parent_node;
        scanf("%d",&parent_node);
        int nodenum;
        scanf("%d",&nodenum);
        
        for(int j=1;j<=nodenum;j++){
            int child_node;
            scanf("%d",&child_node);
            tree[child_node] = parent_node;
        }
    }
    
    queue<int> treequeue;
    int count = 1;
    treequeue.push(1);
    bool isBegin = false;
    while(!treequeue.empty()){
        int levelcount=0;
        int temp = 0;
        for(int i=0;i<count;i++){
            int node = (int) treequeue.front();
            treequeue.pop();
            bool flag = false;
            for(int i=1; i<=treenode;i++){
                if(tree[i]==node){
                    treequeue.push(i);
                    temp++;
                    flag = true;
                }
            }
            if(!flag)
                levelcount++;
        }
        count=temp;
        if(!isBegin){
            printf("%d",levelcount);
            isBegin = true;
        }else{
            printf(" %d", levelcount);
        }
        
    }
    return 0;
}

