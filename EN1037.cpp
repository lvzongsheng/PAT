//
//  main.cpp
//  PAT1037
//  http://pat.zju.edu.cn/contests/pat-a-practise/1037
//  Solutions:
//  这题开始的时候出现了运行超时，自己最开始是用的vector，后来直接改成了数组。但是问题依然没有解决，再后来把自定义的compare函数去掉，就可以了。所以sort还是本题的关键。
//  Created by 吕 宗胜 on 6/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[])
{

    int nc,np;
    int nc1[100005],nc2[100005],np1[100005],np2[100005];
    nc1[0]=0;
    nc2[0]=0;
    np1[0]=0;
    np2[0]=0;
    scanf("%d",&nc);
    int index1=0,index2=0;
    for(int i=0;i<nc;i++){
        int t;
        scanf("%d",&t);
        if(t>=0){
            nc1[++index1]=t*-1;
            nc1[0]++;
        }
        else{
            nc2[++index2]=t;
            nc2[0]++;
        }
    }
    scanf("%d",&np);
    index1=0;
    index2=0;
    for(int i=0;i<np;i++){
        int t;
        scanf("%d",&t);
        if(t>=0){
            np1[++index1]=t*-1;
            np1[0]++;
        }
        else{
            np2[++index2]=t;
            np2[0]++;
        }
    }
    sort(nc1+1,nc1+nc1[0]+1);
    sort(nc2+1,nc2+nc2[0]+1);
    sort(np1+1,np1+np1[0]+1);
    sort(np2+1,np2+np2[0]+1);
    
    
    long result=0;
    for(int i=0;i<nc1[0]&&i<np1[0];i++){
        result+=nc1[i+1]*np1[i+1];
    }
    for(int i=0;i<nc2[0]&&i<np2[0];i++){
        result+=nc2[i+1]*np2[i+1];
    }
    
    printf("%ld",result);
    return 0;
}

