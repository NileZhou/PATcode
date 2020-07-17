#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N=501, INF=0x7fffffff;
int G[N][N], dis[N], cap[N]={INF}, n, half, src, op1=INF, op2=INF;
bool vis[N]={false};
vector<int> path, tmp_path, pre[N];

void dijkstra(int dest) {
    fill(dis, dis+n+1, INF);
    dis[src] = 0;
    for (int i=0; i<=n; ++i) {
        int u=-1, mind=INF;
        for (int v=0; v<=n; ++v) {
            if (!vis[v] && dis[v] < mind) {
                u = v;
                mind = dis[v];
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
                } else if (dis[u] + G[u][v] == dis[v]) pre[v].push_back(u);
            }
        }
    }
}

void dfs(int dest) {
    tmp_path.push_back(dest);
    if (dest == src) {
        int bring=0, back=0, plen=tmp_path.size();
        for (int i=plen-2; i>=0; --i) {
            if (back + cap[tmp_path[i]] > half) back = back + cap[tmp_path[i]] - half;
            else {
                bring += half - back - cap[tmp_path[i]];
                back = 0;
            }
        }
        if (bring < op1 || bring == op1 && back < op2) {
            path = tmp_path;
            op1 = bring;
            op2 = back;
        }
    } else {
        for (int i=0; i<pre[dest].size(); ++i) dfs(pre[dest][i]);
    }
    tmp_path.pop_back();
}

int main() {
    int sp, m, si, sj, tij;
    cin >> half >> n >> sp >> m;
    half /= 2;
    for (int i=1; i<=n; ++i) cin >> cap[i];
    fill(G[0], G[0]+N*N, INF);
    for (int i=0; i<m; ++i) {
        cin >> si >> sj >> tij;
        G[si][sj] = G[sj][si] = tij;
    }
    dijkstra(sp);
    dfs(sp);
    cout << op1 << " ";
    for (int i=path.size()-1; i>0; --i) cout << path[i] << "->";
    cout << sp << " " << op2;
    
    return 0;
}
