//
//  main.cpp
//  PAT1012
//  http://pat.zju.edu.cn/contests/pat-a-practise/1012
//  Solutions:
//  此题要注意如果出现排名相同的情况，则其下一位排名是多少的问题。比如说排名是1 2 2 4，最后一名是第4名而不是第3名。
//  Created by 吕 宗胜 on 11/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

typedef struct{
    int id;
    int number;
    int rank;
} Student;

void rankss(int n, Student s[]){
    int index=1;
    for(int i=0;i<n;i++){
        if(i==0){
            (s+i)->rank = index;
        }else{
            if((s+i)->number==(s+i-1)->number){
                (s+i)->rank = index;
            }else{
                index = i+1;
                (s+i)->rank = index;
            }
        }
    }
}

int ranks(int id, int n, Student s[]){
    for(int i=0;i<n;i++){
        if((s+i)->id==id){
            return (s+i)->rank;
        }
    }
    return -1;
}

bool compare(Student a, Student b){
    if(a.number>b.number)
        return true;
    else
        return false;
}

int main(int argc, const char * argv[])
{
    int n,m;
    Student cp[2000],ma[2000],en[2000],av[2000];
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        int id,cc,mm,ee;
        scanf("%d%d%d%d",&id,&cc,&mm,&ee);
        cp[i].id = ma[i].id = en[i].id = av[i].id = id;
        cp[i].number = cc;
        ma[i].number = mm;
        en[i].number = ee;
        av[i].number = (cc+mm+ee);
    }
    
    sort(cp,cp+n,compare);
    sort(ma,ma+n,compare);
    sort(en,en+n,compare);
    sort(av,av+n,compare);
    rankss(n,cp);
    rankss(n,ma);
    rankss(n,en);
    rankss(n,av);
    
    for(int i=0;i<m;i++){
        int id;
        scanf("%d",&id);
        int rankc = ranks(id,n,cp);
        if(rankc<0){
            printf("N/A\n");
            continue;
        }
        int rankm = ranks(id,n,ma);
        int ranke = ranks(id,n,en);
        int ranka = ranks(id,n,av);
        
        if(ranka<=rankc&&ranka<=rankm&&ranka<=ranke){
            printf("%d A\n",ranka);
        }else if(rankc<=rankm&&rankc<=ranke&&rankc<=ranka){
            printf("%d C\n",rankc);
        }else if(rankm<=rankc&&rankm<=ranke&&rankm<=ranka){
            printf("%d M\n",rankm);
        }else if(ranke<=rankc&&ranke<=rankm&&ranke<=ranka){
            printf("%d E\n",ranke);
        }
        
        
    }
    
    return 0;
}

