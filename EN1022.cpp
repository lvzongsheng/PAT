//
//  main.cpp
//  PAT1022
//
//  Created by 吕 宗胜 on 7/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#define MAX 10000
using namespace std;

typedef struct {
    string id;
    string title;
    string author;
    string keywords;
    string publisher;
    string year;
}Book;

int number;
Book books[MAX];

bool compare(Book a, Book b){
    if(a.id<b.id)
        return true;
    else
        return false;
}

void getResult(string search,string id){
    //Book result[MAX];
    int index=0;
    for(int i=0;i<number;i++){
        if(id=="1"){
            if(books[i].title==search){
                //result[index++] = books[i];
                cout<<books[i].id<<endl;
                index++;
            }
        }else if(id=="2"){
            if(books[i].author==search){
                cout<<books[i].id<<endl;
                index++;
            }
        }else if(id=="3"){
            if(books[i].keywords.find(search)!= books[i].keywords.npos){
                cout<<books[i].id<<endl;
                index++;
            }
        }else if(id=="4"){
            if(books[i].publisher==search){
                cout<<books[i].id<<endl;
                index++;
            }
        }else if(id=="5"){
            if(books[i].year==search){
                cout<<books[i].id<<endl;
                index++;
            }
        }
    }
    if(index==0){
        cout<<"Not Found"<<endl;
    }
}

int main(int argc, const char * argv[])
{
    cin>>number;
    string temp;
    getline(cin,temp);
    for(int i=0;i<number;i++){
        //getline(cin,books[i].id);
        getline(cin,books[i].id);
        getline(cin,books[i].title);
        getline(cin,books[i].author);
        getline(cin,books[i].keywords);
        getline(cin,books[i].publisher);
        getline(cin,books[i].year);
    }
    sort(books,books+number,compare);
    int count;
    cin>>count;
    getline(cin, temp);
    for(int i=0;i<count;i++){
        string search;
        getline(cin,search);
        cout<<search<<endl;
        string s = search.substr(3);
        string id = search.substr(0,1);
        getResult(s,id);
    }
    return 0;
}

