//
//  main.cpp
//  EN1001
//  http://pat.zju.edu.cn/contests/pat-a-practise/1001
//  Solutions:
//  这个题目本身不难，一个容易忽略的问题就是当后面部分计算出的数字少于3位的时候要填够3位，
//  其他的就是使用一个递归。
//  Created by 吕 宗胜 on 31/8/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>

void print(int res){
    if(res>999){
        print(res/1000);
        int rem = res%1000;
        if(rem>99){
            printf(",%d",rem);
        }else if(rem>9){
            printf(",0%d",rem);
        }else
            printf(",00%d",rem);
    }else
        printf("%d",res);
}

int main(int argc, const char * argv[])
{

    int a,b,sum;
    scanf("%d %d",&a, &b);
    sum = a+b;
    bool flag;
    if(sum>=0){
        flag = true;
    }else{
        flag = false;
        sum = 0-sum;
        printf("-");
    }
    
    print(sum);
    
    
    return 0;
}

