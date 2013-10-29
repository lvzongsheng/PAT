//
//  main.cpp
//  1035
//
//  Created by 吕 宗胜 on 6/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct pass{
    string name;
    string password;
}Password;

int main(int argc, const char * argv[])
{

    int n;
    cin>>n;
    vector<Password> v;
    for(int i=0;i<n;i++){
        Password p;
        cin>>p.name>>p.password;
        v.push_back(p);
    }
    int count=0;
    int size = (int)v.size();
    for(int i=0;i<size;i++){
        string t = v.at(i).password;
        int j;
        for(j=0;j<t.length();j++){
            if(t.at(j)=='1'||t.at(j)=='l'||t.at(j)=='0'||t.at(j)=='O'){
                count++;
                break;
            }
        }
        if(j<t.length()){
            v.push_back(v.at(i));
        }
    }
    if(count>0)
        cout<<count<<endl;
    else if(n==1){
        cout<<"There is "<<n<<" account and no account is modified";
    }else{
        cout<<"There are "<<n<<" accounts and no account is modified";
    }
    for(int i=n;i<v.size();i++){
        cout<<v.at(i).name<<" ";
        string p = v.at(i).password;
        for(int i=0;i<p.length();i++){
            if(p.at(i)=='1')
                cout<<'@';
            else if(p.at(i)=='0')
                cout<<'%';
            else if(p.at(i)=='l')
                cout<<'L';
            else if(p.at(i)=='O')
                cout<<'o';
            else
                cout<<p.at(i);
        }
        cout<<endl;
    }
    
    return 0;
}

