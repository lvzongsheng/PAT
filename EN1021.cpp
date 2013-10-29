//
//  main.cpp
//  PAT1021
//  http://pat.zju.edu.cn/contests/pat-a-practise/1021
//  Solutions:
//  此题使用的基本的DFS算法，由于时间足够，不过需要注意空间，直接使用二维数组会造成空间溢出，可以使用vector的一维数组。
//  Created by 吕 宗胜 on 26/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> gra[10001];
int cc[10001];
int k = 0;
bool isPrint = true;
vector<int> result;

void dfs(int id){
    cc[id]++;
    for(int i=0;i<gra[id].size();i++){
        int ii = gra[id].at(i);
        if(cc[ii]==0){
            dfs(ii);
        }
    }
}

int dfsn(int id){
    cc[id]++;
    int max = 1;
    for(int j=0;j<gra[id].size();j++){
        int jj = gra[id].at(j);
        if(cc[jj]==0){
            int temp = dfsn(jj);
            if(temp>max){
                max = temp;
            }
        }
    }
    return max+1;
}


int main(int argc, const char * argv[])
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cc[i] = 0;
    }
    
    for(int i=1;i<n;i++){
        int n1,n2;
        scanf("%d%d",&n1,&n2);
        gra[n1].push_back(n2);
        gra[n2].push_back(n1);
    }
    
    for(int i=1;i<=n;i++){
        if(cc[i]==0){
            k++;
            dfs(i);
        }
    }
    if(k>1){
        printf("Error: %d components",k);
    }else{
        
        int max = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cc[j] = 0;
            }
            int temp = dfsn(i);
            if(max<temp){
                result.clear();
                max = temp;
                result.push_back(i);
            }else if(max == temp){
                result.push_back(i);
            }

        }
        sort(result.begin(), result.end());
        for(int i=0;i<result.size();i++){
            printf("%d\n",result.at(i));
        }
        
    }
    
    return 0;
}

