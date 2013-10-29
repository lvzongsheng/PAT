//
//  main.cpp
//  PAT1052
//  http://pat.zju.edu.cn/contests/pat-a-practise/1052
//  Solutions:
//  此题有两个陷阱：
//  1. 该链表可以是多个链表，需要我们去找出要排序的链表的节点个数
//  2. 当输入的起始节点为-1时，可以直接输出。
//  Created by 吕 宗胜 on 8/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

typedef struct {
    int address;
    int key;
    int next;
} Node;

bool compare(Node a, Node b){
    if(a.key<b.key){
        return true;
    }else
        return false;
}

void formatPrint(int s){
    if(s<10){
        printf("0000%d",s);
    }else if(s<100){
        printf("000%d",s);
    }else if(s<1000){
        printf("00%d",s);
    }else if(s<10000){
        printf("0%d",s);
    }else
        printf("%d",s);
}

int main(int argc, const char * argv[])
{

    Node link[100005];
    Node link2[100005];
    int n, first;
    scanf("%d%d",&n,&first);
    for(int i=0;i<n;i++){
        int flag;
        scanf("%d",&flag);
        link[flag].address = flag;
        scanf("%d%d",&link[flag].key,&link[flag].next);
        
    }
    if(first!=-1){
        int address = first;
        int index=0;
        while(address!=-1){
            link2[index++] = link[address];
            address = link[address].next;
        }
    
        sort(link2,link2+index,compare);
    
        printf("%d ",index);
        formatPrint(link2[0].address);
        printf("\n");
        for(int i=0;i<index-1;i++){
            formatPrint(link2[i].address);
            printf(" %d ",link2[i].key);
            formatPrint(link2[i+1].address);
            printf("\n");
        }
    
        formatPrint(link2[index-1].address);
        printf(" %d -1",link2[index-1].key);
    }
    else{
        printf("0 -1");
    }
    return 0;
}

