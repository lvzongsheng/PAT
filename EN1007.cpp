//
//  main.cpp
//  PAT1007
//  http://pat.zju.edu.cn/contests/pat-a-practise/1007
//  Solutions:
//  此题要使用动态规划来做
//  result[i]表示以i结尾的最大子序列的和
//  result[i] = max {result[i-1]+input[i], input[i]}
//  Created by 吕 宗胜 on 11/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{

    int n;
    scanf("%d",&n);
    int max = 0;
    int index = 0;
    int input[100000];
    int result[100000];
    for(int i=0;i<n;i++){
        scanf("%d",input+i);
    }
    
    for(int i=0;i<n;i++){
        if(i==0){
            result[0] = input[0];
        }else{
            if(input[i]>(input[i]+result[i-1])){
                result[i] = input[i];
            }else
                result[i] = result[i-1]+input[i];
        }
    }
    for(int i=0;i<n;i++){
        if(i==0){
            max=result[0];
            index = 0;
        }else{
            if(result[i]>max){
                max=result[i];
                index = i;
            }
        }
    }
    if(max>=0){
        printf("%d ",max);
        int j;
        for(j=index;j>=0;j--){
            if(max-input[j]==0){
                break;
            }
            else
                max = max-input[j];
        }
        printf("%d %d",input[j],input[index]);
    }
    else
        printf("0 %d %d",input[0],input[n-1]);
    
    return 0;
}

