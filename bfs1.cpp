#include <iostream>
#include <queue>

using namespace std;

// 邻接矩阵版
const int maxn = 1000;
int n = 100; // 当前结点数
int G[maxn][maxn];
bool inq[maxn] = {false}; // 是否入队

// bfs u 所在的联通块
void bfs(int u){
    queue<int> q;
    q.push(u);
    inq[u] = true; // 已经加入过队列
    while (!q.empty()){
        int u = q.front(); // 取出队首元素
        q.pop();
        for (int v=0; v<n; v++){
            if (!inq[v] && G[u][v] > 0){
                q.push(v);
                inq[v] = true;
            }
        }
    }
}

void bfs_travel(){
    for(int v=0; v<n; v++){
        if (!inq[v]){
            bfs(v);
        }
    }
}




