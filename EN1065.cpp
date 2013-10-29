//
//  main.cpp
//  PAT1065
//
//  Created by 吕 宗胜 on 21/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

long long max = 9223372036854775807;
long long nmax = -9223372036854775808;

int main(int argc, const char * argv[])
{
    int size;
    scanf("%d",&size);

    long long n1,n2,n3;
    for(int i=0;i<size;i++){
        scanf("%lld%lld%lld",&n1,&n2,&n3);
        printf("Case #%d: ",i+1);
        if(n1>=0&&n2>=0){
            if((n1-max+n2)>0){
                printf("true\n");
            }else{
                if(n1+n2>n3){
                    printf("true\n");
                }else{
                    printf("false\n");
                }
            }
        }else if((n1>=0&&n2<0)||(n1<0&&n2>=0)){
            if(n1+n2>n3){
                printf("true\n");
            }else{
                printf("false\n");
            }
        }else{
            if(n3>=0){
                printf("false\n");
            }else{
                if((n1-nmax+n2)<0){
                    printf("false\n");
                }else{
                    if(n1+n2>n3){
                        printf("true\n");
                    }else{
                        printf("false\n");
                    }
                }
            }
        }
        
    }
    
    return 0;
}

