//
//  main.cpp
//  EN1006
//  http://pat.zju.edu.cn/contests/pat-a-practise/1006
//  Created by 吕 宗胜 on 26/9/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

typedef struct{
    string id;
    int h1,m1,s1;
    int h2,m2,s2;
}People;

int main(int argc, const char * argv[])
{

    int count;
    scanf("%d",&count);
    vector<People> people;
    for(int i=0;i<count;i++){
        People p;
        cin>>p.id;
        scanf("%d:%d:%d %d:%d:%d",&p.h1,&p.m1,&p.s1,&p.h2,&p.m2,&p.s2);
        people.push_back(p);
    }
    
    People max1,max2;
    for(int i=0;i<people.size();i++){
        if(i==0){
            max1 = people.at(i);
            max2 = people.at(i);
        }else{
            People pp = people.at(i);
            if(pp.h1<max1.h1){
                max1 = pp;
            }else if(pp.h1 == max1.h1 && pp.m1<max1.m1){
                max1 = pp;
            }else if(pp.h1 == max1.h1 && pp.m1==max1.m1 && pp.s1<max1.s1){
                max1 = pp;
            }
            
            if(pp.h2>max2.h2){
                max2 = pp;
            }else if(pp.h2 == max2.h2 && pp.m2<max2.m2){
                max2 = pp;
            }else if(pp.h2 == max2.h2 && pp.m2==max2.m2 && pp.s2<max2.s2){
                max2 = pp;
            }
        }
    }
    
    cout<<max1.id<<" "<<max2.id;
    
    return 0;
}

