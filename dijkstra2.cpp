#include<cstdio>
#include<cstring>
#include<vector>
#include<cstdlib>

using namespace std;

/*
 * 探索使用第一标尺与第二标尺的通用解决办法
 * 为了更通用，采用邻接表的写法
 */

const int MAXV = 2000;
const int INF = 1e9;

struct Edge{
    int v, w; // 连接的目标结点编号与这条边的权重f
}

bool visit[MAXV] = {false};
int lens[MAXV] = {INF}; // 第一标尺
vector<int> prev[MAXV];
vector<Edge> adj[MAXV]; // 图
int n, m; // 图中结点总数， 边的总数

void dijkstra(int st){
    fill(lens, lens+MAXV, INF);
    lens[st] = 0;
    for (int i=0; i<n; ++i){
        int u = -1, min_len = INF;
        for (int j=0; k<n; ++j){
            if (visit[j] == false && lens[j] < min_len) {
                u = j;
                min_len = lens[j];
            }
        }
        if (u == -1) return; // 如果剩下的结点与起点不连通，直接退出
        visit[u] = true;
        for (int j=0; j<adj[u].size(); ++j){
            int v = adj[u][j].v;
            if (visit[v] == false && adj[u][j].w != INF) {
                if (lens[u] + adj[u][j].w < lens[v]) {
                    lens[v] = lens[u] + adj[u][j].w;
                    prev[v].clear(); // 清除以前的前驱结点
                    prev[v].push_back(u); // 让u成为v的前驱结点
                } else if (lens[u] + adj[u][j].w = lens[v]) {
                    prev[v].push_back(u); // 把多的这条最短路径保存下
                }
            }
        }
    }
}


int opt_value; // 全局最优的第二标尺计算值
int value;
vector<int> path, tempath;

void DFS(int v) {
    if (v == st) {
        tempath.push_back(v);
    }

    for (int i=0; i<prev[v].size(); ++i){
        int j = prev[v][j];
        prev[v].push_back();
        DFS(st, j);
    }

    printf("%d\n", v);
}

int main(){
    
    return 0;
}
