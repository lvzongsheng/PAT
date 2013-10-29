//
//  main.cpp
//  PAT1056
//
//  Created by 吕 宗胜 on 8/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>


int mice[1000];
int order[1000];
int result[1000];



void cal(int index,int ng){
    int count = 0,re;
    int flag = 0;
    if(index%ng==0){
        count = index/ng;
        re = 0;
    }else{
        count = index/ng+1;
        re = index%ng;
    }
    
    int rank;
    if(index>1)
        rank= 1+count;
    else
        rank = 1;
    
    int i;
    for(i=0;i+ng<=index;i=i+ng){
        int max = -1;
        int in = -1;
        for(int j=0;j<ng;j++){
            result[order[i+j]] = rank;
            if(max<mice[order[i+j]]){
                max = mice[order[i+j]];
                in = order[i+j];
            }
        }
        order[flag++] = in;
    }
    
    if(re>0){
        int max = -1;
        int in = -1;
        for(int j=index-re;j<index;j++){
            result[order[j]] = rank;
            if(max<mice[order[j]]){
                max = mice[order[j]];
                in = order[j];
            }
        }
        order[flag++] = in;
    }
    
}

int main(int argc, const char * argv[])
{

    int np, ng;
    scanf("%d%d",&np,&ng);
    
    for(int i=0;i<np;i++){
        scanf("%d",mice+i);
    }
    for(int i=0;i<np;i++){
        scanf("%d",order+i);
    }
    
    int temp = np;
    while(temp>0){
        cal(temp,ng);
        if(temp==1){
            temp = 0;
        }else{
            if(temp%ng==0){
                temp = temp/ng;
            }else{
                temp = temp/ng+1;
            }
        }
    }
    
    for(int i=0;i<np;i++){
        if(i==0)
            printf("%d",result[i]);
        else
            printf(" %d",result[i]);
    }
    
    return 0;
}

