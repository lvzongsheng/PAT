//
//  main.cpp
//  EN1019
//  http://pat.zju.edu.cn/contests/pat-a-practise/1019
//  Created by 吕 宗胜 on 28/9/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

int main(int argc, const char * argv[])
{

    long number, base;
    vector<long> result;
    scanf("%ld%ld",&number,&base);
    while (number>=base) {
        result.push_back(number%base);
        number = number/base;
    }
    
    result.push_back(number);
    
    bool isPar = true;
    for(int i=0;i<result.size()/2;i++){
        if(result.at(i)!=result.at(result.size()-i-1)){
            isPar = false;
            break;
        }
    }
    
    if(isPar)
        printf("Yes\n");
    else
        printf("No\n");
    
    for(int i=(int)(result.size()-1);i>=0;i--){
        if(i!=0){
            printf("%ld ",result.at(i));
        }else{
            printf("%ld",result.at(i));
        }
    }
    return 0;
}

