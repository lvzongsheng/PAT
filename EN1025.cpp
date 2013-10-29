//
//  main.cpp
//  PAT1025
//  http://pat.zju.edu.cn/contests/pat-a-practise/1025
//  Solutions:
//  此题要主要registration number是13位（long），可以是0开头的，所以最后输出的时候注意使用%013ld
//  Created by 吕 宗胜 on 13/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct{
    long id;
    int fr;
    int ln;
    int lr;
    int score;
}Test;

bool compare(Test a, Test b){
    if(a.score>b.score) return true;
    else if(a.score<b.score) return false;
    else{
        if(a.id<=b.id) return true;
        else return false;
    }
}

Test test[30000];
int main(int argc, const char * argv[])
{

    int n;
    int k[100];
    scanf("%d",&n);
    
    int sum = 0;
    for(int i=0;i<n;i++){
        scanf("%d",&k[i]);
        for(int j=0;j<k[i];j++){
            scanf("%ld%d",&test[sum+j].id,&test[sum+j].score);
            test[sum+j].ln = i+1;
        }
        sort(test+sum,test+sum+k[i],compare);
        int index = 1;
        for(int j=0;j<k[i];j++){
            if(j==0){
                test[sum+j].lr = index;
            }else{
                if(test[sum+j].score==test[sum+j-1].score){
                    test[sum+j].lr = index;
                }else{
                    index = j+1;
                    test[sum+j].lr = index;
                }
            }
        }
        sum+=k[i];
    }
    
    sort(test,test+sum,compare);
    int index = 1;
    printf("%d\n",sum);
    for(int i=0;i<sum;i++){
        if(i==0){
            test[i].fr = index;
        }else{
            if(test[i].score==test[i-1].score){
                test[i].fr = index;
            }else{
                index = i+1;
                test[i].fr = index;
            }
        }
        printf("%013ld %d %d %d\n",test[i].id,test[i].fr, test[i].ln, test[i].lr);
    }
    
    return 0;
}

