//
//  main.cpp
//  PAT1010
//
//  Created by 吕 宗胜 on 29/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long radixVaule(char* num, long long rad){
    long long r=0;
    for(int i=0;i<=10;i++){
        char t = num[i];
        if(t=='\0')
            break;
        int n;
        if(t>'9'){
            n = t-'a'+10;
        }else{
            n = t-'0';
        }
        if(n>rad) return -1;
        r = r*rad+n;
    }
    return r;
}

int getMinRad(char* num){
    int max = -1;
    for(int i=0;i<=10;i++){
        char t = num[i];
        if(t=='\0')
            break;
        int n;
        if(t>'9'){
            n = t-'a'+10;
        }else{
            n = t-'0';
        }
        if(max<n){
            max = n;
        }
    }
    return max+1;
}

long long getMaxRad(long long min, long long r){
    long long max;
    if(min>r) max = min;
    else max = r;
    return max;
}

bool getRadix(char* n,long long r){
    bool isOk = true;
    long long ra = getMinRad(n);
    long long raa = getMaxRad(ra, r);
    while(true){
        long long midra = (ra+raa)/2;
        
        
        long long rr=0;
        for(int i=0;i<=10;i++){
            char t = n[i];
            if(t=='\0')
                break;
            int nn;
            if(t>'9'){
                nn = t-'a'+10;
            }else{
                nn = t-'0';
            }
            rr = rr*midra+nn;
            
            if(rr>r){
                break;
            }
        }
        //rr = radixVaule(n, midra);
        
        
        if(rr == r){
            printf("%lld",midra);
            break;
        }else if(rr<r){
            ra = midra+1;
        }else{
            raa = midra-1;
        }
        if(ra>raa){
            isOk = false;
            break;
        }
    }
    return isOk;
}

int main(int argc, const char * argv[])
{

    char n1[11],n2[11];
    int tag;
    long long radix;
    scanf("%s%s%d%lld",n1,n2,&tag,&radix);
    
    if(strlen(n1)==1&&strlen(n2)==1&&n1[0]==1&&n2[0]==1){
        printf("2");
        return 0;
    }
    
    if(strcmp(n1, n2)==0){
        printf("%lld",radix);
        return 0;
    }
    
    long long r1=0,r2=0;
    if(tag==1){
        r1 = radixVaule(n1, radix);
        if(r1==-1){
            printf("Impossible");
            return 0;
        }
    }else{
        r2 = radixVaule(n2, radix);
        if(r1==-1){
            printf("Impossible");
            return 0;
        }
    }
    
    bool isOk = true;
    
    if(tag==1){
        isOk = getRadix(n2, r1);
    }else{
        isOk = getRadix(n1, r2);
    }
    
    if(!isOk){
        printf("Impossible");
    }
    return 0;
}

