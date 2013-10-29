//
//  main.cpp
//  PAT1054
//
//  Created by 吕 宗胜 on 8/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int result[16777216];
int main(int argc, const char * argv[])
{

    int m,n;
    scanf("%d%d",&m,&n);
    
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int temp;
            scanf("%d",&temp);
            result[temp]++;
        }
    }
    int max=0;
    int color=0;
    for(int i=0;i<16777216;i++){
        if(max<result[i]){
            max = result[i];
            color = i;
        }
    }
    
    printf("%d",color);
    return 0;
}

