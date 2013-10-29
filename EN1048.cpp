//
//  main.cpp
//  PAT1048
//  http://pat.zju.edu.cn/contests/pat-a-practise/1048
//  Solutions:
//  此题关键在于同一面值的硬币是可以出现了，抓住了这一点就比较好做了
//  Created by 吕 宗胜 on 10/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char * argv[])
{

    int coin[100001];
    for(int i=0;i<=100000;i++){
        coin[i] = 0;
    }
    int nc,np;
    scanf("%d%d",&nc,&np);
    for(int i=0;i<nc;i++){
        int temp;
        scanf("%d",&temp);
        coin[temp]++;
    }
    int i;
    for(i=1;i<=np;i++){
        if(coin[i]>0){
            if(i<np){
                if(np-i==i){
                    if(coin[i]>1){
                        printf("%d %d",i,np-i);
                        break;
                    }
                }
                else if(coin[np-i]>0){
                    printf("%d %d",i,np-i);
                    break;
                }
            }
        }
    }
    if(i>np){
        printf("No Solution");
    }
    return 0;
}

