//
//  main.cpp
//  PAT1031
//
//  Created by 吕 宗胜 on 6/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <string>
#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{

    string input;
    int n1,n2;
    cin>>input;
    int size = (int)input.length();
    if((size+2)%3==0){
        n1 = (size+2)/3;
    }else{
        n1 = (size+2)/3;
    }
    n2 = size+2-2*n1;
    for(int i=0;i<n1-1;i++){
        printf("%c",input.at(i));
        for(int j=0;j<n2-2;j++){
            printf(" ");
        }
        printf("%c\n",input.at(size-1-i));
    }
    for(int i=0;i<n2;i++){
        printf("%c",input.at(n1-1+i));
    }
    return 0;
}

