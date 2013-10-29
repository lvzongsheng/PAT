//
//  main.cpp
//  PAT1068
//  http://pat.zju.edu.cn/contests/pat-a-practise/1068
//  Solutions:
//  此题的解题关键在于理解动态规划，该题是0-1背包问题的变种，每个币值可以等价与重量和价值，要付的钱等价与背包容量。
//  该题可以先计算背包容量一定的时候价值的最大值。不过因为输出要是字典序，所以比较好的方法是重量逆序排列，然后从n..1的顺序开始遍历，满足条件就输出。
//  Created by 吕 宗胜 on 24/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int value[10001];
int n,m;
int c[10001][101];

//典型的0-1背包问题解法
void dproblem(int v[], int w[], int n, int W){
    c[0][0] = 0;
    for(int i=1;i<=n;i++){
        c[i][0] = 0;
    }
    for(int j=1;j<=W;j++){
        c[0][j] = 0;
    }
    
    for(int i=1;i<=n;i++){
        for(int ww=1;ww<=W;ww++){
            if(w[i]>ww){
                c[i][ww] = c[i-1][ww];
            }else{
                if(c[i-1][ww]>v[i]+c[i-1][ww-w[i]]){
                    c[i][ww] = c[i-1][ww];
                }else{
                    c[i][ww] = v[i]+c[i-1][ww-w[i]];
                }
            }
        }
    }
}

bool compare(int a, int b){
    if(a>b) return true;
    else return false;
}

int main(int argc, const char * argv[])
{
    
    scanf("%d%d",&n,&m);
    
    for(int i=1;i<=n;i++){
        scanf("%d",value+i);
    }
    //逆序输出。
    sort(value+1, value+n+1,compare);
    
    dproblem(value, value, n, m);
    int amount = m;
    int index = 0;
    for(int i=n;i>=1;i--){
        if(amount<value[i]) continue;
        if(c[i-1][amount-value[i]] == amount - value[i]){
            if(index == 0){
                printf("%d",value[i]);
                index++;
            }else{
                printf(" %d",value[i]);
            }
            amount-=value[i];
        }
    }
    if(index==0){
        printf("No Solution");
    }
    return 0;
}

