//
//  main.cpp
//  EN1008
//  http://pat.zju.edu.cn/contests/pat-a-practise/1006 
//  Created by 吕 宗胜 on 27/9/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{

    int number;
    scanf("%d",&number);
    int time = 0;
    int pre;
    for(int i=0;i<number;i++){
        int floor;
        scanf("%d",&floor);
        if(i==0){
            time += 6*floor+5;
            pre = floor;
        }else{
            if(floor>pre){
                time += 6*(floor-pre)+5;
            }else{
                time +=4*(pre-floor)+5;
            }
            pre = floor;
        }
    }
    
    printf("%d",time);
    return 0;
}

