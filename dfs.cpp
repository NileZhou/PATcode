#include<cstdio>

const int maxn = 100;
const int INF = 1e9;

// аз╫с╠М
int n, G[maxn][maxn];
bool vis[maxn] = {false};

void dfs(int u, int depth){
    vis[u] = true;
    for (int v=0; v<n; v++){
        if (vis[v] == false && G[u][v] != INF){
            dfs(v, depth+1);
        }
    }
}

void dfs_travel(){
    for(int u=0; u<n; u++){
        if (vis[u] == false){
            dfs(u, 1);
        }
    }
}

int main(){

    return 0;
}
