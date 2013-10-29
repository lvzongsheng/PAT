//
//  main.cpp
//  PAT1055
//
//  Created by 吕 宗胜 on 19/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

typedef struct{
    char name[9];
    //int age;
    int weight;
}People;

bool compare(People a, People b){
    if(a.weight>b.weight) return true;
    else if(a.weight<b.weight) return false;
    else{
        int isok = strcmp(a.name, b.name);
        if(isok<0) return true;
        else return false;
    }
}

vector<People> ages[201];
int cc[201];
int main(int argc, const char * argv[])
{

    int people, query;
    People p;
    scanf("%d%d",&people,&query);
    
    for(int i=0;i<people;i++){
        int age;
        scanf("%s%d%d",p.name,&age,&p.weight);
        ages[age].push_back(p);
    }
    
    for(int i=1;i<=200;i++){
        sort(ages[i].begin(),ages[i].end(),compare);
    }
    
    for(int i=0;i<query;i++){
        int count;
        int ageb,agee;
        scanf("%d%d%d",&count,&ageb,&agee);
        printf("Case #%d:\n",i+1);
        int amount = 0;
        while(amount<count){
            if(amount==0){
                for(int i=1;i<=200;i++){
                    cc[i] = 0;
                }
            }
            int max = -10000000;
            int j;
            int index = 0;
            for(j=ageb;j<=agee;j++){
                if(cc[j]==ages[j].size()){
                    continue;
                }
                if(max<ages[j].at(cc[j]).weight){
                    max = ages[j].at(cc[j]).weight;
                    index = j;
                }
            }
            if(max == -10000000){
                if(amount==0){
                    printf("None\n");
                    break;
                }else{
                    break;
                }
            }else{
                printf("%s %d %d\n",ages[index].at(cc[index]).name,index,max);
                cc[index]++;
                amount++;
            }
        }
    }
    return 0;
}

