//
//  main.cpp
//  PAT1057
//
//  Created by 吕 宗胜 on 26/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int stack[100001];
int restack[100001];

int sum(int x)
{
    int sum = 0;
    while(x){
        sum += restack[x];
        x -= (x & -x);
    }
    return sum;
}
    
void update(int x, int delta)
{
    while(x < 100001) {
        restack[x] += delta;
        x += (x & -x);
    }
}

int main(int argc, const char * argv[])
{

    int n;
    int index = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char key[11];
        int number;
        scanf("%s", key);
        if(key[1]=='u'){
            scanf("%d",&number);
            index++;
            stack[index] = number;
            update(number,1);
        }else if(key[1]=='e'){
            if(index<=0){
                printf("Invalid\n");
            }else{
                int temp;
                if((index)%2==0){
                    temp = (index)/2;
                }else{
                    temp = (index+1)/2;
                }
                int high = 100000, low = 1, median;
        		while(low <= high) {
                	median = (high + low)/2;
                	int leftSum = sum(median - 1);
                	int medianSum = sum(median);
                	if (leftSum < temp && medianSum >=  temp) //由于树状数组tr[x]记录的是x之前的所有值之和，即小于x的值的个数，做二分时的条件判断跟传统有些不同。
                        break;
                	else if (leftSum >= temp)
                        high = median;
                	else
                        low = median;
        		}
        		/*for(int i=1;i<=100000;i++){
        			if(sum(i)>=temp){
        				printf("%d\n",i);
        				break;
        			}
        		}*/
        		printf("%d\n",median);
            }
        }else{
            if(index<=0){
                printf("Invalid\n");
            }else{
                printf("%d\n",stack[index]);
                update(stack[index],-1);
                index--;
            }
        }
    }
    
    return 0;
}

