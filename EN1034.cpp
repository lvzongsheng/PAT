//
//  main.cpp
//  PAT1034
//
//  Created by 吕 宗胜 on 25/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 26*26*26

int m,n;
int father[MAX];
int weight[MAX];
int maximu[MAX];
int scales[MAX];
int rankes[MAX];
vector<int> result;
char name[4];

int getName(char name[]){
    return (name[0]-'A')*26*26+(name[1]-'A')*26+(name[2]-'A');
}

void setName(int n){
    name[3] = '\0';
    name[2] = n%26+'A';
    name[1] = n/26%26+'A';
    name[0] = n/26/26%26+'A';
}

int find(int id){
    if(father[id]==id){
        return id;
    }else{
        father[id] = find(father[father[id]]);
        return father[id];
    }
}

void unions(int f1, int f2, int w){
    if(rankes[f1]>rankes[f2]){
    father[f2] = f1;
    rankes[f1]+=rankes[f2];
    scales[f1]+=w;
    if(weight[maximu[f1]] < weight[maximu[f2]])
        maximu[f1] = maximu[f2];
    }else{
        father[f1] = f2;
        rankes[f2] += rankes[f1];
        scales[f2] += w;
        if(weight[maximu[f2]]<weight[maximu[f1]])
            maximu[f2] = maximu[f1];
    }

}

bool compare(int a, int b){
    if(maximu[a]<maximu[b]) return true;
    else return false;
}

int main(int argc, const char * argv[])
{
    
    for(int i=0;i<MAX;i++){
        father[i] = -1;
        weight[i] = 0;
        maximu[i] = -1;
        scales[i] = 0;
        rankes[i] = 0;
    }
    
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++){
        char n1[4],n2[4];
        int w;
        
        scanf("%s%s%d",n1,n2,&w);
        
        int id1 = getName(n1);
        if(father[id1]==-1){
            father[id1] = id1;
            maximu[id1] = id1;
            rankes[id1] = 1;
        }
        int id2 = getName(n2);
        if(father[id2]==-1){
            father[id2] = id2;
            maximu[id2] = id2;
            rankes[id2] = 1;
        }
        weight[id1]+=w;
        weight[id2]+=w;
        
        int f1 = find(id1);
        if(weight[maximu[f1]]<weight[id1]){
            maximu[f1] = id1;
        }
        
        int f2 = find(id2);
        if(weight[maximu[f2]]<weight[id2]){
            maximu[f2] = id2;
        }
        
        if(f1==f2){
            scales[f1]+=w;
        }else{
            unions(f1,f2,w);
        }
    }
    
    
    for(int i=0;i<MAX;i++){
        if(father[i]==i&&rankes[i]>2&&scales[i]>n){
            result.push_back(i);
            //setName(maximu[i]);
            //printf("%s %d\n",name, rankes[i]);
        }
    }
    if(result.size()<=0){
        printf("0");
        return 0;
    }
    sort(result.begin(),result.end(),compare);
    printf("%d\n",result.size());
    for(int i=0;i<result.size();i++){
        setName(maximu[result.at(i)]);
        printf("%s %d\n",name,rankes[result.at(i)]);
    }
     
    
    return 0;
}

