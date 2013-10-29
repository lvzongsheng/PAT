//
//  main.cpp
//  PAT1016
//  http://pat.zju.edu.cn/contests/pat-a-practise/1016
//  Solutions:
//  此题的难点有两个：
//  1.此题的排序问题，先按字母序，再按时间序，同时在查找的时候要进行一定的筛选
//  2.该题是分段计算的，可以采用如下的方法来进行分段计算：用起始时刻分阶段追赶结束时刻。追赶的过程分阶段，也就能计算好不同阶段的开销， 先将起始时间调整到跟结束时间为同一天，细节是先让分钟达到 0，再让小时迭代到 0，天进位，一直迭代到跟结束时间同天；再让起始时刻的小时数追平 结束时刻；最后让分钟追平。以此计算出最终话费
//  Created by 吕 宗胜 on 12/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef struct{
    char id[21];
    int month;
    int day;
    int hour;
    int minu;
    char status;
} Bill;

int price[24];

long calculateTime(int day1, int hour1,int min1, int day2, int hour2, int min2){
    long count = 0;
    if(min2<min1){
        hour2--;
        count=min2+60-min1;
    }else{
        count=min2-min1;
    }
    
    if(hour2<hour1){
        day2--;
        count+=(hour2+24-hour1)*60;
    }
    else{
        count+=(hour2-hour1)*60;
    }
    count+=(day2-day1)*24*60;
    
    return count;
}

int calculateMoney(int day1, int hour1,int min1, int day2, int hour2, int min2){
    int count = 0;
    int index=0;
    while(day1<day2){
        for(int i=hour1;i<24;i++){
            if(index==0){
                count = count+price[hour1]*(60-min1);
                index++;
            }else{
                count+=price[i]*60;
            }
        }
        day1++;
        hour1 = 0;
    }
    
    for(int i=hour1;i<hour2;i++){
        if(index==0){
            count+=price[hour1]*(60-min1);
            index++;
        }else{
            count+=price[hour1]*60;
        }
        hour1++;
    }
    if(index==0){
        count+=price[hour2]*(min2-min1);
    }else{
        count+=price[hour2]*min2;
    }
    
    return count;
}

int compare(const void* a, const void* b){
    Bill* aa = (Bill*) a;
    Bill* bb = (Bill*) b;
    
    int c = strcmp(aa->id, bb->id);
    if (c>0) {
        return 1;
    }else if(c<0){
        return -1;
    }else{
        if(aa->month!=bb->month) return aa->month - bb->month;
        if(aa->day!=bb->day) return aa->day - bb->day;
        if(aa->hour!=bb->hour) return aa->hour - bb->hour;
        if(aa->minu!=bb->minu) return aa->minu - bb->minu;
        
        return 0;
    }
}


int main(int argc, const char * argv[])
{
    
    for(int i=0;i<24;i++){
        scanf("%d",price+i);
    }
    
    int n;
    scanf("%d",&n);
    Bill bills[1000];
    for(int i=0;i<n;i++){
        char temp[21];
        scanf("%s%d:%d:%d:%d%s",bills[i].id,&bills[i].month,&bills[i].day,&bills[i].hour,&bills[i].minu,temp);
        bills[i].status = temp[1];
    }
    
    qsort(bills, n, sizeof(Bill), compare);
    
    Bill pre;
    double sum=0;
    bool isOK = false;
    int index=0;
    for(int i=0;i<n;i++){
        if(i==0){
            pre = bills[i];
        }else{
            if(strcmp(pre.id,bills[i].id)==0){
                if(pre.status=='n' && bills[i].status=='f'){
                    isOK = true;
                    if(index==0){
                        printf("%s %02d\n",bills[i].id,bills[i].month);
                        index++;
                    }
                    long time = calculateTime(pre.day,pre.hour, pre.minu,bills[i].day, bills[i].hour, bills[i].minu);
                    double money = (double)calculateMoney(pre.day,pre.hour, pre.minu,bills[i].day, bills[i].hour, bills[i].minu)/100;
                    printf("%02d:%02d:%02d %02d:%02d:%02d %ld $%.2f\n",pre.day,pre.hour,pre.minu,bills[i].day,bills[i].hour,bills[i].minu, time, money);
                    sum += money;
                }
            }else{
                if(isOK){
                    printf("Total amount: $%.2f\n",sum);
                    isOK = false;
                    sum = 0;
                }
                index=0;
            }
            pre = bills[i];
        }
    }
    if(isOK){
        printf("Total amount: $%.2f\n",sum);
    }
    return 0;
}

