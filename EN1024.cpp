//
//  main.cpp
//  PAT1024
//  http://pat.zju.edu.cn/contests/pat-a-practise/1024
//  Solution：
//  这个题目大小是10的10次方，经过相加，最大会到10的12次方，这时64不够表示，所以要采用字符串来表示。
//  通过这个题目，要搞清楚C++中字符串的拼接等相关操作。建议做个总结。
//  Created by 吕 宗胜 on 28/9/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

bool isPar(string number){
    bool isP = true;
    for(int i=0,k=(int)number.length()-1;i<number.length();i++,k--){
        if(number.at(i)!=number.at(k)){
            isP = false;
            break;
        }
    }
    
    return isP;
}

string getRenum(string number){
    int carry = 0;
    string s;
    for(int i=(int)number.length()-1;i>=0;i--){
        int temp = (number.at(i)-'0')+(number.at((number.length()-1-i))-'0')+carry;
        carry = temp/10;
        char t[1];
        sprintf(t, "%d", temp%10);
        s = t+s;

    }
    if(carry>0){
        char t[1];
        sprintf(t, "%d", carry);
        s = t+s;
    }
    return s;
}

int main(int argc, const char * argv[])
{

    string number;
    int step;
    cin>>number;
    scanf("%d",&step);
    int index = 0;
    int i;
    for(i=1;i<=step;i++){
        if(isPar(number)){
            index = i-1;
            cout<<number<<endl;
            printf("%d",index);
            break;
        }else{
            number = getRenum(number);
        }
    }
    if(i>step){
        cout<<number<<endl;
        printf("%d",step);
    }
    return 0;
}

