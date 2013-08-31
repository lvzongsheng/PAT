//
//  main.cpp
//  EN1061
//  http://pat.zju.edu.cn/contests/pat-a-practise/1061
//  Created by 吕 宗胜 on 30/8/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[])
{

    string input[4];
    string wk[7] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
    for(int i=0; i<4; i++){
        getline(cin, input[i]);
    }
    
    bool flag = false;
    char week, hour;
    int min;
    for(int i=0; i<input[0].size(); i++){
        char temp = input[0].at(i);
        if(!flag){
            if(temp>='A'&&temp<='G'){
                if(i<input[1].size()){
                    char res = input[1].at(i);
                
                    if(temp==res){
                        week = temp;
                        flag = true;
                    }
                }
            }
        }else{
            if((temp>='A'&&temp<='N')||(temp>='0'&&temp<='9')){
                if(i<input[1].size()){
                    char res = input[1].at(i);
                    
                    if(temp==res){
                        hour = temp;
                        break;
                    }
                }
            }
        }
    }
    
    for(int j=0; j<input[2].size(); j++){
        
        char temp = input[2].at(j);
        
        if((temp>='A'&&temp<='Z')||(temp>='a'&&temp<='z')){
            if(j<input[3].size()){
                    char res = input[3].at(j);
                    
                    if(temp==res){
                        min = j;
                        break;
                    }
            }
          }
    }
    
    cout<<wk[week-'A']<<" ";
    if(hour>='0'&&hour<='9'){
        cout<<'0'<<hour<<":";
    }else{
        cout<<hour-'A'+10<<":";
    }
    if(min>=0&&min<=9){
        cout<<'0'<<min;
    }else{
        cout<<min;
    }
    
    return 0;
}

