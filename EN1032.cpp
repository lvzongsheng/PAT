//
//  main.cpp
//  PAT1032
//
//  Created by 吕 宗胜 on 7/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


typedef struct{
    char data;
    int next;
    int count;
} Node;

void printresult(int a){
    if(a<10){
        printf("0000%d",a);
    }else if(a<100){
        printf("000%d",a);
    }else if(a<1000){
        printf("00%d",a);
    }else if(a<10000){
        printf("0%d",a);
    }else
        printf("%d",a);
}

int main(int argc, const char * argv[])
{

    int begin1,begin2;
    int number;
    Node nodes[100000];
    
    scanf("%d%d%d",&begin1,&begin2,&number);
    for(int i=0;i<number;i++){
        int flag;
        scanf("%d",&flag);
        scanf("%s",&nodes[flag].data);
        scanf("%d",&nodes[flag].next);
        nodes[flag].count = 0;
    }
    int address = 0;
    int i=begin1;
    while(i!=-1){
        nodes[i].count++;
        i = nodes[i].next;
    }
    i=begin2;
    while(i!=-1){
        nodes[i].count++;
        i = nodes[i].next;
    }
    i=begin2;
    while(i!=-1){
        if(nodes[i].count>1){
            address = i;
            break;
        }
        i = nodes[i].next;
    }
    if(address!=0)
        printresult(address);
    else
        printf("-1");
    return 0;
}

