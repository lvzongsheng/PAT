//
//  main.cpp
//  PAT1017
//
//  Created by 吕 宗胜 on 16/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

typedef struct{
    int hour;
    int min;
    int sec;
    int time;
    int rank_time;
} Customer;


bool compare(Customer a, Customer b){
    if(a.rank_time<b.rank_time) return true;
    else return false;
}

int main(int argc, const char * argv[])
{
    int n,k;
    Customer customer[10000];
    int time[100];
    int rank_time[100];
    scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++){
        time[i] = 0;
        rank_time[i] = 8*60*60;
    }
    for(int i=0;i<n;i++){
        scanf("%d:%d:%d%d",&customer[i].hour,&customer[i].min,&customer[i].sec,&customer[i].time);
        customer[i].rank_time = customer[i].hour*60*60+customer[i].min*60+customer[i].sec;
    }
    
    sort(customer,customer+n,compare);
    
    int count = 0;
    int totalTime = 0;
    int t = 0;
    while(t<n){
        int i;
        int min = 0;
        if(customer[t].rank_time>17*60*60){
            t++;
            continue;
        }
        for(i=0;i<k;i++){
            if(time[i]==0){
                time[i] = customer[t].time;
                if(customer[t].rank_time<rank_time[i]){
                    totalTime += rank_time[i] - customer[t].rank_time;
                    rank_time[i] += time[i]*60;
                    count++;
                    t++;
                }else{
                    totalTime+=0;
                    rank_time[i] = customer[t].rank_time+time[i]*60;
                    count++;
                    t++;
                }
            }
        }
        for(i=0;i<k;i++){
            if(i==0){
                min = time[i];
            }else{
                if(min>time[i]){
                    min = time[i];
                }
            }
        }
        for(i=0;i<k;i++){
            if(time[i]<=min){
                time[i] = 0;
            }else{
                time[i] = time[i]-min;
            }
        }
    }
    float result = (float)totalTime/60/count;
    printf("%.1f",result);
    return 0;
}

