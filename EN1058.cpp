//
//  main.cpp
//  PAT1058
//  http://pat.zju.edu.cn/contests/pat-a-practise/1058
//  Created by 吕 宗胜 on 6/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char * argv[])
{

    int g1,s1,k1,g2,s2,k2;
    scanf("%d.%d.%d %d.%d.%d",&g1,&s1,&k1,&g2,&s2,&k2);
    int k = (k1+k2)%29;
    int s = ((k1+k2)/29+s1+s2)%17;
    int g = ((k1+k2)/29+s1+s2)/17+g1+g2;
    
    printf("%d.%d.%d",g,s,k);
    return 0;
}

