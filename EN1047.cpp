//
//  main.cpp
//  PAT1047
//
//  Created by 吕 宗胜 on 19/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

/*
 
 10 5
 ZOE1 2 4 5
 ANN0 3 5 2 1
 BOB5 5 3 4 2 1 5
 JOE4 1 2
 JAY9 4 1 2 5 4
 FRA8 3 4 2 5
 DON2 2 4 5
 AMY7 1 5
 KAT3 3 5 4 2
 LOR6 4 2 4 1 5
 */

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> course[2500];
char hname[5];

int hashname(char* name){
    return (name[0]-'A')*26*26*10+(name[1]-'A')*26*10+(name[2]-'A')*10+(name[3]-'0');
}

void getName(int n){
    hname[4] = '\0';
    hname[3] = n%10+'0';
    hname[2] = (n/10)%26+'A';
    hname[1] = (n/10/26)%26+'A';
    hname[0] = (n/10/26/26)%26+'A';
}

int main(int argc, const char * argv[])
{
    int stu, cou;
    scanf("%d%d",&stu,&cou);
    for(int i=0;i<stu;i++){
        char name[5];
        int n;
        scanf("%s%d",name,&n);
        int t = hashname(name);
        for(int i=0;i<n;i++){
            int c;
            scanf("%d",&c);
            course[c].push_back(t);
        }
    
    }
    for(int i=1; i<=cou; i++){
        printf("%d %d\n",i,(int)course[i].size());
        sort(course[i].begin(),course[i].end());
        for(int j=0;j<course[i].size();j++){
            int t = course[i].at(j);
            getName(t);
            printf("%s\n",hname);
        }
    }
    return 0;
}

