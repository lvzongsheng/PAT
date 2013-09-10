//
//  main.cpp
//  PAT1064
//  http://pat.zju.edu.cn/contests/pat-a-practise/1064
//  Solutions:
//  此题在于如何构建完全二叉搜索树，然后进行层级遍历。这里用到了一个比较好的方法。
//  1 利用数组来表示完全二叉树，n为根，则2n和2n+1为孩子节点。
//  2 对给定的节点排序。由于二叉搜索树的中序遍历是从小到大的序列，留待第三步完成。
//  3 对完全二叉树进行中序遍历，并把排序好的点填入到相应位置。
//  Created by 吕 宗胜 on 2/9/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n;
int c=1;
int result[1001];
int origin[1000];
void poster(int index){
    if(index*2<=n&&index*2+1<=n){
        poster(index*2);
        result[index] = origin[c-1];
        c++;
        poster(index*2+1);
    }else if(index*2>n){
        result[index]=origin[c-1];
        c++;
    }else if(index*2+1>n){
        poster(index*2);
        result[index]=origin[c-1];
        c++;
    }
}

int main(int argc, const char * argv[])
{

    
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",origin+i);
    }
    sort(origin,origin+n);
    
    poster(1);
    
    for(int i=1;i<n;i++){
        printf("%d ",result[i]);
    }
    printf("%d",result[n]);
    return 0;
}

