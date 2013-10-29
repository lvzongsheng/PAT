//
//  main.cpp
//  PAT1067
//  http://pat.zju.edu.cn/contests/pat-a-practise/1067
//  Solutions:
//  此题的解题思路不是很难，就是每次交换都尽量实现一个数的正确排序，即0跟0所在的位置的数进行交换。比如说0在7的位置上，则0跟7交换，值得注意的是当0回到0的位置上而整个序列未排序的话，需要使0跟任何不是排序好的数交换，以此类推。
//  此题对时间要求较高，自己用了两个优化思路，1. 用空间换时间，记录每个数所在的位置 2. 在0到0位置时，进行判断记录起点游标，减少比较量。
//  Created by 吕 宗胜 on 21/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{

    int n;
    scanf("%d",&n);
    int per[100000];
    int erp[100000];
    
    for(int i=0;i<n;i++){
        scanf("%d",per+i);
        erp[per[i]] = i;
    }
    int count = 0;
    int index = 0;
    for(int i=index;i<n;i++){
        if(per[i]==i){
            continue;
        }
        index = i;
        if(per[0]==0){
            int tm = per[i];
            per[0] = tm;
            per[i] = 0;
            erp[0] = i;
            erp[tm] = 0;
            count++;
        }
        while(per[0]!=0){
            int temp = erp[0];
            int tt = erp[temp];
            per[tt] = 0;
            per[temp] = temp;
            erp[0] = tt;
            count++;
        }
    }
    
    printf("%d",count);
    return 0;
}

