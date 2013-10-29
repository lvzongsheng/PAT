//
//  main.cpp
//  PAT1036
//
//  Created by 吕 宗胜 on 6/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

typedef struct{
    string name;
    string sex;
    string course;
    int grade;
}Student;
int main(int argc, const char * argv[])
{

    int n;
    cin>>n;
    Student maxF;
    Student minM;
    bool isFirstF = true;
    bool isFirstM = true;
    bool isMi = false;
    
    for(int i=0;i<n;i++){
        Student s;
        cin>>s.name>>s.sex>>s.course>>s.grade;
        if(s.sex=="M"){
            if(isFirstM){
                minM = s;
                isFirstM = false;
            }else{
                if(minM.grade>s.grade){
                    minM = s;
                }
            }
        }
        else{
            if(isFirstF){
                maxF = s;
                isFirstF = false;
            }else{
                if(maxF.grade<s.grade){
                    maxF = s;
                }
            }
        }
    }
    if(isFirstF){
        cout<<"Absent"<<endl;
        isMi = true;
    }else{
        cout<<maxF.name<<" "<<maxF.course<<endl;
    }
    
    if(isFirstM){
        cout<<"Absent"<<endl;
        isMi = true;
    }else{
        cout<<minM.name<<" "<<minM.course<<endl;
    }
    
    if(isMi){
        cout<<"NA";
    }
    else
        cout<<maxF.grade-minM.grade;
    return 0;
}

