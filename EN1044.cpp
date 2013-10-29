//
//  main.cpp
//  PAT1044
//  http://pat.zju.edu.cn/contests/pat-a-practise/1044
//  Solutions：
//  此题的解题思路是记录每个起点和终点的值。主要是时间要求比较高。
//  优化点有：1. 把需要输出的点放入vector，减少输出时的遍历次数 2. 在计算时采用从0到n的顺序，当一段序列的值大于或等于m时，游标起点往前移一个，这样可以减少计算量。
//  Created by 吕 宗胜 on 21/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

/*
16 15
3 2 1 5 4 6 8 7 16 10 15 11 9 12 14 13
5 13
2 4 5 7 9
 */

#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

int main(int argc, const char * argv[])
{

    int n,m;
    int value[100000];
    int result[100000];
    int index[100000];
    vector<int> v1,v2;
    int min=100000000;
    bool isHas = true;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",value+i);
    }
    int sum = 0;
    if(m==0) sum = -1;
    int bindex=0, eindex=0;
    while(eindex<=n){
        if(sum<m){
            sum+=value[eindex++];
            continue;
        }else if(sum == m){
            isHas = false;
            index[eindex-1] = bindex;
            v1.push_back(eindex-1);
            sum-=value[bindex];
            bindex++;
        }else{
            if(min>sum){
                v2.clear();
                min = sum;
                v2.push_back(eindex-1);
                index[eindex-1] = bindex;
            }else if(min==sum){
                v2.push_back(eindex-1);
                index[eindex-1] = bindex;
            }
            sum-=value[bindex];
            bindex++;
        }
        
    }
    
    if(!isHas){
        for(int i=0;i<v1.size();i++){
            printf("%d-%d\n",index[v1.at(i)]+1,v1.at(i)+1);
        }
    }else{
        for(int i=0;i<v2.size();i++){
            printf("%d-%d\n",index[v2.at(i)]+1,v2.at(i)+1);
        }
    }
    
    
    return 0;
}

