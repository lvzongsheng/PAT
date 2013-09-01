//
//  main.cpp
//  EN1063
//  http://pat.zju.edu.cn/contests/pat-a-practise/1063
//  Solutions:
//  此题难度不大，做法是把数组进行排序，然后分别对两个数组使用游标进行遍历，方法类似于归并排序游标的使用方法。
//  可以针对此题把这种类型的算法写法掌握起来。
//  Created by 吕 宗胜 on 1/9/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

void check(long sets[], int &index, long &temp){
    while(true){
        if(index+1>sets[0]){
            index++;
            break;
        }
        if(temp==sets[index+1]){
            index++;
            
        }else{
            temp=sets[++index];
            break;
        }
    }
}

int main(int argc, const char * argv[])
{
    int setnum=0;
    long sets[51][10001];
    scanf("%d",&setnum);
    for(int i=1; i<=setnum; i++){
        long vnum = 0;
        scanf("%ld",&vnum);
        sets[i][0] = vnum;
        for(int j=0;j<vnum;j++){
            long temp;
            scanf("%ld",&temp);
            sets[i][j+1] = temp;
        }
    }
    
    int loopnum;
    scanf("%d",&loopnum);
    
    for(int i=0; i<loopnum;i++){
        int begin, end;
        scanf("%d %d",&begin, &end);
        sort(sets[begin]+1,sets[begin]+sets[begin][0]+1);
        sort(sets[end]+1,sets[end]+sets[end][0]+1);
        int bindex = 0;
        int eindex = 0;
        int commnum = 0;
        int diffnum = 0;
        long b = sets[begin][++bindex];
        long e = sets[end][++eindex];
        while(bindex<=sets[begin][0]&&eindex<=sets[end][0]){
            if(b==e){
                commnum++;
                diffnum++;
                check(sets[begin],bindex,b);
                check(sets[end],eindex,e);
            }else if(b<e){
                diffnum++;
                check(sets[begin],bindex,b);
            }else{
                diffnum++;
                check(sets[end],eindex,e);
            }
        }
        if(bindex>sets[begin][0]&&eindex<=sets[end][0]){
            diffnum = diffnum+(int)sets[end][0]-eindex+1;
        }
        if(bindex<=sets[begin][0]&&eindex>sets[end][0]){
            diffnum = diffnum+(int)sets[begin][0]-bindex+1;
        }
        
        float result = (float)commnum/diffnum*100;
        
        printf("%.1lf%%\n",result);
    }
    
    return 0;
}

