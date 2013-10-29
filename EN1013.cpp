//
//  main.cpp
//  PAT1013
//  http://pat.zju.edu.cn/contests/pat-a-practise/1013
//  Solutions:
//  此题只要沿着DFS的思路来应该就问题不大，要注意的是一些图中单独的点也要考虑进去，即原图可以不是联通的。
//  Created by 吕 宗胜 on 24/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int dia[1000][1000];
bool isVisited[1000];
int n,m,k;

int dfs(int c){
    isVisited[c] = true;
    for(int i=0;i<n;i++){
        if(i!=c&&dia[c][i]==1&&isVisited[i]==false){
            dfs(i);
        }
    }
    
    return 0;
}

int main(int argc, const char * argv[])
{
    scanf("%d%d%d",&n,&m,&k);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                dia[i][j] = 1;
            }else{
                dia[i][j] = 0;
            }
        }
    }
    
    for(int i=0;i<m;i++){
        int s,e;
        scanf("%d%d",&s,&e);
        dia[s-1][e-1] = 1;
        dia[e-1][s-1] = 1;
    }
    
    for(int i=0;i<k;i++){
        int city;
        scanf("%d",&city);
        for(int p=0;p<n;p++){
            isVisited[p] = false;
        }
        city--;
        int path = 0;
        isVisited[city] = true;
        for(int j=0;j<n;j++){
            if(j!=city&&dia[city][j]==1&&isVisited[j]==false){
                dfs(j);
                int count = 0;
                for(int pp=0;pp<n;pp++){
                    if(isVisited[pp] == true){
                        count++;
                    }
                }
                if(count<n){
                    path++;
                }
            }
        }
        int index = 0;
        for(int pp=0;pp<n;pp++){
            if(isVisited[pp] == false){
                isVisited[pp] = true;
                if(index==0){
                    index++;
                }else
                    path++;
                dfs(pp);
            }
        }
        printf("%d\n",path);
    }
    return 0;
}

