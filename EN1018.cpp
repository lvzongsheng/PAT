//
//  main.cpp
//  PAT1018
//
//  Created by 吕 宗胜 on 28/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;

#define MAX_INT ((unsigned)(-1) >> 1)

long long gra[501][501];
int bikes[501];
int dist[501];
bool isVisited[501];
vector<int> record[501];
vector<vector<int>> result;
int flag = 0;

int amount, stops, dest, path;

void initial(){
    for(int i=0;i<=500;i++){
        for(int j=0;j<=500;j++){
            if(i==j)
                gra[i][j] = 1;
            else
                gra[i][j] = 0;
        }
        isVisited[i] = false;
    }
}

void dijkstra(){
    for (int i = 1; i <= stops; ++ i)
        dist[i] = MAX_INT;
        typedef pair<int,int>pii;
        priority_queue<pii,vector<pii>,greater<pii> >q;
        q.push(make_pair(0, 0));

        while(!q.empty()) {
            int node = q.top().second;
            int curDist = q.top().first;
            q.pop();
    
            if (isVisited[node])
                continue;
            isVisited[node] = true;
    
            for (int i = 0; i <= stops; ++ i)
                if (gra[node][i] && i != node && !isVisited[i])
                    if (dist[node] + gra[node][i] == dist[i])
                        record[i].push_back(node);
                    else if (dist[node] + gra[node][i] < dist[i]) {
                        dist[i] = dist[node] + gra[node][i];
                        record[i].clear();
                        record[i].push_back(node);
                        q.push(make_pair(dist[i], i));
                    }
        }
}

void bikedfs(int node, vector<int> * path){
    path->push_back(node);
    if (node == 0)
        result.push_back(*path);
    else
        for (int i = 0; i != record[node].size(); ++ i)
            bikedfs(record[node][i], path);
    path->pop_back();
}

int main(int argc, const char * argv[])
{

    initial();
    scanf("%d%d%d%d",&amount,&stops,&dest,&path);
    for(int i=1;i<=stops;i++){
        scanf("%d", bikes+i);
    }
    
    for(int i=0;i<path;i++){
        int node1, node2;
        long long distance;
        scanf("%d%d%lld",&node1,&node2,&distance);
        gra[node1][node2] = distance;
        gra[node2][node1] = distance;
    }
    
    dijkstra();
    vector<int> path;
    bikedfs(dest, &path);
    
    int minSend = MAX_INT, minBack = MAX_INT, min = MAX_INT;
    for (int j = 0; j != result.size(); ++ j){
        int send = 0, back = 0;
        for (int i = result[j].size() - 2; i >= 0 ; -- i) {
            int tmp = amount/2 - bikes[result[j][i]];
            if (tmp < 0)
                back += -tmp;
            else if (tmp > back) {
                send += tmp - back;
                back = 0;
            }else
                back -= tmp;
        }
        
        if (minSend > send ||( minSend == send && minBack > back)){
            minBack = back;
            minSend = send;
            min = j;
        }
    }
    
    printf("%d 0", minSend);
    for (int i =  result[min].size() - 2; i >= 0; -- i)
        printf("->%d",result[min][i]);
    printf(" %d\n", minBack);

    return 0;
}

