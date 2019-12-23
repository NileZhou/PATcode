#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

const int N = 1005;
int n, m, k; // number of city, number of highway, number of check

vector<int> G[N];
bool vis[N];
int cur; // 代表当前删除结点的编号

void dfs(int p) {
    if (p == cur) return;
    vis[p] = true;
    for (int i=0; i<G[p].size(); ++i) {
        int id = G[p][i];
        if (!vis[id]) {
            dfs(id);
        }
    }
}

int check() {
    memset(vis, false, sizeof(vis));
    // 直接算当这个点为时，连通块的个数
    int block = 0;
    while (true) {
        int id = -1;
        for (int i=0; i<n; ++i) {
            if (i != cur && !vis[i]) {
                id = i;
                break;
            }
        }
        if (id == -1) break;
        dfs(id);
        block++;
    }

    return block-1;
}

int main() {
    int from, to;

    scanf("%d %d %d", &n, &m, &k);
    for (int i=0; i<m; ++i) {
        scanf("%d %d", &from, &to);
        from--;
        to--;
        G[from].push_back(to);
        G[to].push_back(from);
    }

    for (int i=0; i<k; ++i) {
        scanf("%d", &cur);
        cur--;
        printf("%d\n", check());
    }

    return 0;
}
