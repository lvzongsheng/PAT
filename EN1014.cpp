//
//  main.cpp
//  PAT1014
//  http://pat.zju.edu.cn/contests/pat-a-practise/1014
//  此题有两个点要注意：1. 在模拟出队时要注意不出队的窗口要减去一段时间 2. 不能执行的人应该是17：00之前还没开始执行的人，即16：59开始执行都是可以的，但是17：00开始不行
//  Created by 吕 宗胜 on 16/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int vector[1000];
    int count;
    int time;
    int index;
} Windows;
int n,m,k,q;
int time[1000];
Windows windows[20];

void initial(){
    for(int i=0;i<n;i++){
        windows[i].count = 0;
        windows[i].index = 0;
        windows[i].time = 0;
    }
    for(int i=0;i<k;i++){
        if(i<n*m&&windows[i%n].count<m){
            int index = i%n;
            windows[index].vector[windows[index].count] = i;
            windows[index].count++;
            windows[index].time = time[windows[index].vector[windows[index].index]];
        }else{
            break;
        }
    }
    
}

int main(int argc, const char * argv[])
{
    int result[1000];
    scanf("%d%d%d%d",&n,&m,&k,&q);
    for(int i=0;i<k;i++){
        scanf("%d",time+i);
    }
    initial();
    int i=m*n;
    while(i<k){
        int min = 0;
        for(int j=0;j<n;j++){
            if(j==0){
                min = windows[j].time;
            }else{
                if(min>windows[j].time){
                    min = windows[j].time;
                }
            }
        }
        for(int j=0;j<n;j++){
            if(windows[j].time<=min){
                windows[j].vector[windows[j].count] = i;
                windows[j].count++;
                windows[j].index++;
                windows[j].time = time[windows[j].vector[windows[j].index]];
                i++;
                if(i>=k){
                    break;
                }
            }else{
                windows[j].time = windows[j].time- min;
            }
            
        }
        
    }
    
    for(int i=0;i<n;i++){
        int p = windows[i].count;
        int t = 0;
        for(int j=0;j<p;j++){
            int pp = windows[i].vector[j];
            t += time[pp];
            result[pp] = t;
        }
    }
    for(int i=0;i<q;i++){
        int per;
        scanf("%d",&per);
        if(result[per-1]>=540+time[per-1]){
            printf("Sorry\n");
        }else{
            int t = result[per-1]%60;
            int tt = result[per-1]/60;
            printf("%02d:%02d\n",8+tt,t);
        }
    }
    return 0;
}

