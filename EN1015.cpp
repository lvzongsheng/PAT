//
//  main.cpp
//  PAT1015
//  http://pat.zju.edu.cn/contests/pat-a-practise/1015
//  Solutions
//  此题关键在于把数先转化成radix基数的数，然后再取reverse，再转化成10进制数来判断。
//  另外一个陷阱是1不是质数，所以这里要剔除1才行。
//  Created by 吕 宗胜 on 10/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

long long getReverseNumber(long long number, int radix){
    long long result=0;
    int index = 1;
    while(number>0){
        long long temp = number%radix;
        result = result*index + temp;
        number = number/radix;
        if(index==1)
            index = index*10;
    }
    return result;
}

long long getNumber(long long number,int radix){
    long long result = 0;
    int index = 1;
    while(number>0){
        long long temp = number%10;
        result = result + temp*index;
        number = number/10;
        index = index*radix;
    }
    return result;
}

bool isPrime(long long number){
    bool isPrime = true;
    for(int i=2;i<=number/2;i++){
        if(number%i==0){
            isPrime = false;
            break;
        }
    }
    return isPrime;
}

int main(int argc, const char * argv[])
{

    long long number;
    scanf("%lld",&number);
    while(number>=0){
        int radix;
        scanf("%d",&radix);
        long long num1 = getReverseNumber(number,radix);
        long long num2 = getNumber(num1,radix);
        if(isPrime(number)&&isPrime(num2)&&number!=1&&num2!=1&&number!=0){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
        scanf("%lld",&number);
    }
    return 0;
}

