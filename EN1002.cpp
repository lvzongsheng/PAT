//
//  main.cpp
//  PAT1002
//  http://pat.zju.edu.cn/contests/pat-a-practise/1002
//  Created by 吕 宗胜 on 19/9/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    
    float v[2][1001];
    
    int k1,k2;
    
    for(int i=0; i<=1000; i++){
        v[0][i] = v[1][i] = 0.0;
    }
    
    scanf("%d",&k1);
    for(int i=0;i<k1;i++){
        int co;
        float eff;
        scanf("%d %f",&co,&eff);
        v[0][co] = eff;
    }
    
    scanf("%d",&k2);
    for(int i=0;i<k2;i++){
        int co;
        float eff;
        scanf("%d %f",&co,&eff);
        v[1][co] = eff;
    }
    
    int index = 0;
    for(int i = 0; i<=1000;i++){
        
        v[0][i] = v[0][i]+v[1][i];
        if(v[0][i] != 0.0){
            index++;
        }
    }
    
    printf("%d",index);
    for(int i=1000; i>=0;i--){
        if(v[0][i]!=0.0){
            printf(" %d %.1f",i,v[0][i]);
        }
    }
    
    
    
    return 0;
}

