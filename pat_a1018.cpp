#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

const int N=501;
const int INF = 2*1e9;

int n, hf;
int G[N][N];
int tos[N], caps[N] = {0}, dis[N];
bool vis[N] = {false};
vector<int> path, tmp_path;
vector<int> pre[N];

void dijkstra(int src) {
    fill(dis, dis+n+1, INF);
    dis[src] = 0;
    for (int i=0; i<=n; ++i) {
        int u=-1, min_d=INF;
        for (int v=0; v<=n; ++v) {
            if (!vis[v] && dis[v] < min_d) {
                u = v;
                min_d = dis[v];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v=0; v<=n; ++v) {
            if (!vis[v] && G[u][v] < INF) {
                if (dis[u] + G[u][v] < dis[v]) {
                    dis[v] = dis[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (dis[u] + G[u][v] == dis[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

int main() {
    int sp, m, si, sj, tij;

    fill(tos, tos+n+1, INF);
    fill_n(&G[0][0], sizeof(G) / sizeof(**G), INF);
    cin >> hf >> n >> sp >> m;
    hf /= 2;
    for (int i=1; i<=n; ++i) {
        cin >> caps[i];
    }
    for (int i=0; i<m; ++i) {
        cin >> si >> sj >> tij;
        G[si][sj] = G[sj][si] = tij;
    }
    
    return 0;
}
