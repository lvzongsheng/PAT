//
//  main.cpp
//  EN1027
//  http://pat.zju.edu.cn/contests/pat-a-practise/1027
//  Created by 吕 宗胜 on 6/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void printDeci(int n){
    int temp = n%13;
    int ntemp = n/13;
    if(ntemp>=13){
        printDeci(ntemp);
    }else{
        if(ntemp>=0&&ntemp<=9)
            printf("%d",ntemp);
        else{
            char s = 'A'+ (ntemp -10);
            printf("%c",s);
        }
    }
    
    if(temp>=0&&temp<=9)
        printf("%d",temp);
    else{
        char s = 'A'+ (temp -10);
        printf("%c",s);
    }
}
int main(int argc, const char * argv[])
{

    
    printf("#");
    for(int i=0;i<3;i++){
        int n;
        scanf("%d",&n);
        printDeci(n);
    }
    return 0;
}

