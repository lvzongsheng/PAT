//
//  main.cpp
//  PAT1033
//
//  Created by 吕 宗胜 on 14/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef struct{
    float price;
    int distance;
    float gas;
} Station;

int compare(const void* aa, const void* bb){
    Station* a = (Station*)aa;
    Station* b = (Station*)bb;
    
    return a->distance-b->distance;
}

int main(int argc, const char * argv[])
{
    int max,dist,average,number;
    Station s[501];
    scanf("%d%d%d%d",&max,&dist,&average,&number);
    for(int i=0;i<number;i++){
        scanf("%f%d",&s[i].price,&s[i].distance);
    }
    s[number].price = -1;
    s[number].distance = dist;
    qsort(s,number+1,sizeof(Station),compare);
    
    
    bool isReach = true;
    float distance = 0;
    float cost = 0;
    
    if(s[0].distance!=0){
        isReach = false;
        printf("The maximum travel distance = %.2f",0.0);
        return 0;
    }
    int i=0;
    float left = 0;
    while(i<=number){
        if(s[i].price==-1){
            break;
        }
        int d = max*average+s[i].distance;
        int j;
        if(s[i+1].distance>d){
            distance = s[i].distance;
            isReach = false;
            break;
        }
        for(j=i+1;j<=number;j++){
            if(s[j].distance>d){
                break;
            }
            if(s[j].price<s[i].price){
                break;
            }
        }
        if(s[j].distance<=d){
            cost+=(float)s[i].price*((float)(s[j].distance-s[i].distance)/average-left);
            i = j;
            distance = s[i].distance;
            left = 0;
        }else{
            float minPrice;
            int index = 0;
            for(j=i+1;j<=number;j++){
                if(s[j].distance<=d){
                    if(j==i+1){
                        index = j;
                        minPrice = s[j].price;
                    }
                    if(minPrice>s[j].price){
                        minPrice = s[j].price;
                        index = j;
                    }
                }else break;
            }
            cost+=(float)s[i].price*(float)(max-left);
            left = (float)max-(float)(s[index].distance-s[i].distance)/average;
            i = index;
            distance = s[index].distance;
        }
    }
    
    if(isReach){
        printf("%.2f",cost);
    }else{
        printf("The maximum travel distance = %.2f",distance+average*max);
    }
    return 0;
}

