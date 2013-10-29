//
//  main.cpp
//  EN1009
//  http://pat.zju.edu.cn/contests/pat-a-practise/1009
//  Created by 吕 宗胜 on 27/9/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char * argv[])
{

    int m1,m2;
    float s1[1001],s2[1001],r[1000001];
    scanf("%d",&m1);
    for(int i=0;i<=1000;i++){
        s1[i] = s2[i] = 0;
    }
    
    for(int i=0; i<=1000000;i++){
        r[i] = 0;
    }
    
    for(int i=0;i<m1;i++){
        int co;
        float eff;
        scanf("%d %f",&co,&eff);
        s1[co] = eff;
    }
    scanf("%d",&m2);
    for(int i=0;i<m2;i++){
        int co;
        float eff;
        scanf("%d %f",&co,&eff);
        s2[co] = eff;
    }
    
    for(int i=0;i<=1000;i++){
        for(int j=0;j<=1000;j++){
            r[i+j] += s1[i]*s2[j];
        }
    }
    int count =0;
    for(int i=0;i<=1000000;i++){
        if(r[i]!=0){
            count++;
        }
    }
    printf("%d",count);
    for(int i=1000000;i>=0;i--){
        if(r[i]!=0){
            printf(" %d %.1f",i,r[i]);
        }
    }
    
    return 0;
}

