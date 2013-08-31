//
//  main.cpp
//  EN1062
//  http://pat.zju.edu.cn/contests/pat-a-practise/1062
//  Solutions:
//  本题主要是写出compare函数，然后调用C++ sort。值得注意的是本题不适合使用Vector等容器，会超时。
//  所以应该采用数组，其效率高。
//  对于时间要求高的题目，不要使用cin和cout，它们的执行效率低，推荐使用printf和scanf。
//  Created by 吕 宗胜 on 30/8/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct{
    int id;
    int virgrade;
    int telgrade;
    int totla;
    int level;
}People;

People pList[100000];
int number, low, high;

int level(People a);

int compare(const void* aa, const void* bb){
    People a = *(People *)aa;
    People b = *(People *)bb;
    int levela = a.level;
    int levelb = b.level;
    if(levela==levelb){
        if(a.totla==b.totla){
            if(a.virgrade==b.virgrade){
                if(a.id>b.id){
                    return 1;
                }else{
                    return -1;
                }
            }else
                return b.virgrade-a.virgrade;
        }
        else
            return b.totla - a.totla;
    }else
        return levelb-levela;
}

int level(People a){
    if(a.virgrade>=high&&a.telgrade>=high){
        return 3;
    }else if(a.virgrade>=high){
        return 2;
    }else if(a.telgrade<high&&a.virgrade>=a.telgrade){
        return 1;
    }else
        return 0;
}

int main(int argc, const char * argv[])
{
    scanf("%d %d %d",&number, &low, &high);
    int count = 0;
    for(int i=0; i<number; i++){
        int id, virgrade, telgrade;
        //cin>>id>>virgrade>>telgrade;
        scanf("%d %d %d",&id, &virgrade, &telgrade);
        if(virgrade>=low&&telgrade>=low){
            People p;
            p.id = id;
            p.virgrade = virgrade;
            p.telgrade = telgrade;
            p.totla = virgrade+telgrade;
            p.level = level(p);
            pList[count] = p;
            count++;
        }
    }
    qsort(pList, count, sizeof(People), compare);
    printf("%d\n", count);
    for(int i=0;i<count;i++){
        printf("%d %d %d\n",pList[i].id,pList[i].virgrade,pList[i].telgrade);
    }
    
    return 0;
}

