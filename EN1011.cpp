//
//  main.cpp
//  En1011
//  http://pat.zju.edu.cn/contests/pat-a-practise/1011
//  Created by 吕 宗胜 on 28/9/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{

    float s[3][3];
    char tag[3] = {'W','T','L'};
    float result = 0.0;
    for(int i=0;i<3;i++){
        int index = 0;
        float max = 0.0;
        for(int j=0;j<3;j++){
            scanf("%f",&s[i][j]);
            if(s[i][j]>max){
                max = s[i][j];
                index = j;
            }
        }
        if(i==0){
            result = max;
        }else{
            result = result*max;
        }
        printf("%c ",tag[index]);
    }
    printf("%.2f",(result*0.65-1)*2);
    
    return 0;
}

