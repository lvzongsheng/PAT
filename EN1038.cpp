//
//  main.cpp
//  PAT1038
//  http://pat.zju.edu.cn/contests/pat-a-practise/1038
//  Solutions:
//  此题有两个难点要注意：
//  1.如何找到数字片段的规律，此题的规律是假设有两数a，ab，a是两个数的共同部分，此时要把b和a进行递归的比较
//  2.前面不能输出0，应到第一个不是0的数开始输出，如果都是0，则输出0
//  Created by 吕 宗胜 on 13/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef struct{
    char n[9];
} Number;

bool compare(Number a, Number b){
    int i;
    for(i=0;i<9;i++){
        if(a.n[i]!='\0'&&b.n[i]!='\0'){
            if((a.n[i]-'0')<(b.n[i]-'0')){
                return true;
            }else if((a.n[i]-'0')>(b.n[i]-'0')){
                return false;
            }
            else
                continue;
        }else{
            break;
        }
    }
    
    if(a.n[i]=='\0'&&b.n[i]=='\0'){
        return true;
    }else if(a.n[i]=='\0'){
        if((b.n[i+1]-'0')<(a.n[0]-'0')){
            return false;
        }else return true;
    }else{
        if((a.n[i+1]-'0')<(b.n[0]-'0')){
            return true;
        }else return false;
    }
}

int compare(const void* aa, const void* bb){
    Number* a = (Number*) aa;
    Number* b = (Number*) bb;
    int i;
    for(i=0;i<9;i++){
        if(a->n[i]!='\0'&&b->n[i]!='\0'){
            if((a->n[i]-'0')<(b->n[i]-'0')){
                return -1;
            }else if((a->n[i]-'0')>(b->n[i]-'0')){
                return 1;
            }
            else
                continue;
        }else{
            break;
        }
    }
    
    if(a->n[i]=='\0'&&b->n[i]=='\0'){
        return 0;
    }else if(a->n[i]=='\0'){
        Number tem;
        strcpy(tem.n, b->n+i);
        Number* t = &tem;
        return compare(a, t);
    }else{
        Number tem;
        strcpy(tem.n, a->n+i);
        Number* t = &tem;
        return compare(t, b);
    }
}

int main(int argc, const char * argv[])
{
    int n;
    Number number[10000];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",number[i].n);
    }
    
    qsort(number, n, sizeof(Number), compare);
    bool isOK = true;
    for(int i=0;i<n;i++){
        for(int j=0;j<9;j++){
            if(number[i].n[j]=='\0'){
                break;
            }
            if(number[i].n[j]!='0'&&isOK){
                isOK = false;
            }
            if(!isOK){
                printf("%c",number[i].n[j]);
            }
        }
        
    }
    if(isOK){
        printf("0");
    }
    return 0;
}

