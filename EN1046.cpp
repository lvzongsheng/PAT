//
//  main.cpp
//  PAT1046
//  http://pat.zju.edu.cn/contests/pat-a-practise/1046
//  Solutions:
//  该题一定要把时间控制好，运用线性的算法，重点就是先算好距离，不能在每次case中进行重复计算，在每个case中只进行一次减法运算
//  Created by 吕 宗胜 on 6/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char * argv[])
{

    int n;
    int ip[100000];
    scanf("%d",&n);
    int sum=0;
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        ip[i]=sum;
        sum+=temp;
        
    }
    
    int round;
    scanf("%d",&round);
    for(int i=0;i<round;i++){
        int begin,end;
        int su=0;
        scanf("%d%d",&begin,&end);
        if(begin<end){
            su = ip[end-1]-ip[begin-1];
        }else{
            su = ip[begin-1]-ip[end-1];
        }
        int suu = sum-su;
        if(su>suu)
            printf("%d\n",suu);
        else
            printf("%d\n",su);
    }
    return 0;
}

