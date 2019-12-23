// 邻接表版
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxv = 1000;
int n;
bool inq[maxv] = {false};

vector<int> G[maxv]; // G[u] 枚举从u出发可以到达的所有结点

void bfs(int u){
    queue<int> q;
    q.push(u);
    inq[u] = true;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int i=0; i<G[u].size(); ++i){
            if (!inq[G[u][i]]){
                q.push(G[u][i]);
                inq[G[u][i]] = true;
            }
        }
    }
}

void bfs_travel(){
    for (int i=0; i<n; ++i){
        if (!inq[i]){
            bfs(i);
        }
    }
}