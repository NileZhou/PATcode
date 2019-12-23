#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

// 这是邻接表版本(因为邻接表版本适用于结点数<=1000的场景)
// 同时求最短距离与最短路径

const int MAXV = 2000;
const int INF = 1e9;

struct Edge{
    int v, w; // v为这条边的目标顶点，w为边权
}

vector<Edge> Adj[MAXV]; // Adj[u]中存放可以从u出发到达的所有顶点
int n; // 结点数
bool visit[MAXV] = {false};
int lens[MAXV]; // 从起点到达各点的最短距离
int pre[MAXV] = {-1}; // pre[v]代表从起点到顶点v的最短路径上，v的前一个顶点编号(求最短路径时才需要)

void Dijkstra(int st) {
    fill(lens, lens+MAXV, INF);
    lens[st] = 0;
    pre[st] = -1;
    for (int i=0; i<n; ++i) {
        int u = -1, min_len = INF;
        for (int j=0; j<n; ++j) {
            if (visit[j] == false && lens[j] < min_len) {
                u = j;
                min_len = lens[j];
            }
        }
        if (u == -1) return; // 说明剩下的这些点都没有和起点连接
        visit[u] = true;
        for (int j=0; j<Adj[u].size(); ++j) {
            int v = Adj[u][j].v; // 获取目标顶点编号
            if (visit[j] == false && lens[u] + Adj[u][j].w < lens[v]) {
                lens[v] = lens[u] + Adj[u][v].w;
                pre[v] = u; // v的前驱结点是u
            }
        }
    }
}

// 用递归访问pre的方式获得最短路径
// st为出发结点, v为当前结点编号
void DFS(int st, int v) {
    if (v == st) {
        printf("%d\n", st);
        return;
    }
    DFS(st, pre[v]);
    printf("%d\n", v);
}

int main() {
    
    
        
    return 0;
}
