//
//  main.cpp
//  PAT1023
//
//  Created by 吕 宗胜 on 7/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[])
{

    string input;
    int result[21];
    int count[10];
    
    for(int i=0;i<10;i++){
        count[i]=0;
    }
    
    cin>>input;
    int carry;
    int index=0;
    for(int i=(int)(input.length()-1);i>=0;i--){
        count[input.at(i)-'0']++;
        int sum = (input.at(i)-'0')*2+carry;
        carry = sum/10;
        result[index++] = sum%10;
    }
    if(carry!=0){
        result[index++] = carry;
    }
    for(int i=0;i<index;i++){
        count[result[i]]--;
    }
    int i;
    for(i=0;i<10;i++){
        if(count[i]!=0){
            cout<<"No"<<endl;
            break;
        }
    }
    if(i==10){
        cout<<"Yes"<<endl;
    }
    for(int k=index-1;k>=0;k--){
        cout<<result[k];
    }
    
    
    return 0;
}

