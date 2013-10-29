//
//  main.cpp
//  PAT1050
//  http://pat.zju.edu.cn/contests/pat-a-practise/1050
//  Solutions:
//  此题要搞清楚三点：1.不要使用string，运行效率低 2.不要使用二重循环 3.搞懂ASCII的范围。
//  Created by 吕 宗胜 on 6/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


int main(int argc, const char * argv[])
{

    char s1[10001],s2[10001];
    bool s[10001];
    int size1=0,size2=0;
    
    for(int i=0;i<10001;i++){
        s[i] = false;
    }
    for(int i=0;i<10001;i++){
        char temp;
        scanf("%c",&temp);
        if(temp!='\n'){
            s1[i] = temp;
            size1++;
        }else
            break;
    }
    for(int i=0;i<10001;i++){
        char temp;
        scanf("%c",&temp);
        if(temp!='\n'){
            s2[i] = temp;
            s[temp] = true;
            size2++;
        }else
            break;
    }
    
    for(int i=0;i<size1;i++){
        if(!s[s1[i]])
            printf("%c",s1[i]);
    }
    return 0;
}

