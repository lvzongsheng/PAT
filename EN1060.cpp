
//
//  main.cpp
//  PAT1060
//  http://pat.zju.edu.cn/contests/pat-a-practise/1060
//  Solutions:
//  此题要注意两个点：1 当两个数为0的时候，3 0 0 （YES 0.000*10^0）
//  2 当输入为5 0.001 0.001 时，输出为YES 0.1*10^-2
//  Created by 吕 宗胜 on 6/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 110

struct result{
    char r[MAX];
    int k;
};

result getResult(char a[MAX], int n) {
    result r;
    
    int index = 0 ;
    int firstPos = -1; //the position of first valueable number in a.
    int pointPos = -1; //the position of point.
    int i;
    for (i = 0; a[i] != 0; ++ i) {
        if (a[i] == '.') { //get position of point
            pointPos = i;
            continue;
        }
        
        if (a[i] == '0' && firstPos == -1) //ignore header 0s.
            continue;
        else {
            if (firstPos == -1 )
                firstPos = i;
            if (index < n)
                r.r[index ++] = a[i];
        }
    }
    r.r[index] = 0;
    
    if (pointPos == -1)
        pointPos = i;
    if (pointPos - firstPos < 0)
        r.k  = pointPos - firstPos + 1;
    else
        r.k = pointPos - firstPos;
    
    if (index == 0) { //zero case.
        int i;
        for (i = 0; i != n; ++ i)
            r.r[i] = '0';
        r.r[i] = 0;
        r.k = 0;
    }
    
    return r;
}

int main(int argc, const char * argv[])
{
    
    int n;
    char a[MAX], b[MAX];
    scanf("%d%s%s", &n, a, b);
    result r1 = getResult(a, n);
    result r2 = getResult(b, n);
    
    if (strcmp(r1.r, r2.r) == 0 && r1.k == r2.k)
        printf("YES 0.%s*10^%d\n", r1.r, r1.k);
    else
        printf("NO 0.%s*10^%d 0.%s*10^%d\n", r1.r, r1.k, r2.r, r2.k);
    
    return 0;
}
