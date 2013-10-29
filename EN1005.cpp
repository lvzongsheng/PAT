//
//  main.cpp
//  EN1005
//  http://pat.zju.edu.cn/contests/pat-a-practise/1005
//  Solutions:
//  该题并没有什么难点，重点是要搞清楚10的100次方有多大，所以这里不能用long long等内型来保存，而应该使用String来保存
//  Created by 吕 宗胜 on 26/9/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <stack>
#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{

    string strnum[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    
    string number;
    cin>>number;
    
    if(number == "0"){
        cout<<strnum[0];
    }
    
    long long count = 0;
    for(int i=0;i<number.length();i++){
        count += number.at(i)-'0';
    }
    
    
    stack<int> result;
    while(count>0){
        result.push(count%10);
        count = count/10;
    }
    
    bool flag =false;
    
    while(!result.empty()){
        if(!flag){
            cout<<strnum[result.top()];
            result.pop();
            flag = !flag;
        }else{
            cout<<" "<<strnum[result.top()];
            result.pop();
        }
    }
    
    return 0;
}

