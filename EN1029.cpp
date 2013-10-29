//
//  main.cpp
//  PAT1029
//
//  Created by 吕 宗胜 on 13/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define INFINITE 1000


long se[2000000];

int main(int argc, const char * argv[])
{

    long n;
    scanf("%ld",&n);
    for(long i=0;i<n;i++){
        scanf("%ld",&se[i]);
    }
    
    long k;
    scanf("%ld",&k);
    for(long i=0;i<k;i++){
        scanf("%ld",&se[n+i]);
    }
    
    long index;
    long long sum = n+k;
    if(sum%2==0)
        index = (long)sum/2-1;
    else
        index = (long)sum/2;
    
    long i=0,j=0,p=0;
    long result;
    while(i<n&&j<k&&p<=index){
        if(se[i]<se[n+j]){
            result = se[i];
            i++;
            p++;
        }else{
            result = se[n+j];
            j++;
            p++;
        }
    }
    while(i<n&&p<=index){
        result = se[i];
        i++;
        p++;
    }
    while(j<k&&p<=index){
        result = se[n+j];
        j++;
        p++;
    }
    printf("%ld",result);
    return 0;
}

