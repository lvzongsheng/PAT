//
//  main.cpp
//  PAT1045
//  http://pat.zju.edu.cn/contests/pat-a-practise/1045
//  Solutions:
//  此题要使用动态规划，可以查看“最长递增子序列”的动态规划算法。
//  Created by 吕 宗胜 on 11/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{

    int n;
    scanf("%d",&n);
    int m;
    scanf("%d",&m);
    int order[200];
    int input[10000];
    int result[10000];
    int count=1;
    for(int i=0;i<200;i++){
        order[i] = 0;
    }
    for(int i=0;i<m;i++){
        int temp;
        scanf("%d",&temp);
        order[temp] = count++;
    }
    int k;
    scanf("%d",&k);
    int index=0;
    for(int i=0;i<k;i++){
        int temp;
        scanf("%d",&temp);
        if(order[temp]>0){
            input[index++] = temp;
        }
    }
    
    for(int i=0;i<index;i++){
        if(i==0){
            result[i] = 1;
        }else{
            int max = 0;
            for(int j=0;j<i;j++){
                if(order[input[j]]<=order[input[i]]){
                    if(result[j]+1>max){
                        max = result[j]+1;
                    }
                }else{
                    if(max<1){
                        max=1;
                    }
                }
            }
            result[i] = max;
        }
    }
    int max = 0;
    for(int i=0;i<index;i++){
        if(i==0) max = result[i];
        else{
            if(result[i]>max){
                max = result[i];
            }
        }
    }
    printf("%d",max);
    return 0;
}

