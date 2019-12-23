#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 500;
const int INF = 1e9;

struct Edge{
    int det, dist, cost;
};

bool vis[N] = {false};
vector<Edge> Adj[N]; // 图
int n; // 结点数量
int lens[N]; // 起点到达各点的最短长度
int costs[N]; // 起点到各节点的最小代价
int father[N]; // 记录各个结点的父结点

vector<int> path; // 存储最后的结点路径

void Dijkstra(int src){
    fill(lens, lens+n, INF);
    fill(costs, costs+n, INF);
    fill(father, father+n, -1);

    lens[src] = 0;
    costs[src] = 0;

    for (int i=0; i<n; ++i) {
        int min_len = INF;
        int next = -1;

        for (int j=0; j<n; ++j) {
            if (vis[j] == false && lens[j] < min_len) {
                next = j;
                min_len = lens[j];
            }
        }

        if (next == -1) return;
        vis[next] = true; // 占领next点
        for (int j=0; j<Adj[next].size(); ++j) {
            int id = Adj[next][j].det;
            if (vis[id] == false && lens[next] + Adj[next][j].dist < lens[id]) {
                lens[id] = lens[next] + Adj[next][j].dist;
                costs[id] = costs[next] + Adj[next][j].cost;
                father[id] = next;
            } else if (vis[id] == false && lens[next] + Adj[next][j].dist == lens[id]) {
                if (costs[next] + Adj[next][j].cost < costs[id]) {
                    costs[id] = costs[next] + Adj[next][j].cost;
                    father[id] = next;
                }
            }
        }
    }
}

void DFS(int src, int det) {
    int cur = det;
    while (cur != src) {
        path.push_back(cur);
        cur = father[cur];
    }
    path.push_back(src);
}

int main(){
    int nc, nh, src, det; // number of city, highwags, id of src, dest
    int from, to, dist, cost;

    scanf("%d %d %d %d", &nc, &nh, &src, &det);

    n = nc;

    for (int i=0; i<nh; ++i){
        scanf("%d %d %d %d", &from, &to, &dist, &cost);
        Edge src_node, det_node;
        src_node.det = to;
        src_node.dist = dist;
        src_node.cost = cost;
        det_node.det = from;
        det_node.dist = dist;
        det_node.cost = cost;
        Adj[from].push_back(src_node);
        Adj[to].push_back(det_node);
    }

    Dijkstra(src);
    DFS(src, det);
    
    for (int i=path.size()-1; i>=0; --i) {
        printf("%d ", path[i]);
    }

    printf("%d %d", lens[det], costs[det]);

    return 0;
}
