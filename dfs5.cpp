#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;

const int maxn = 10;

int visited[maxn] = {0};
int path[maxn] = {-1};

vector<int> graph[maxn];

void FindPath(int u, int v, int path[], int d) {
    int w;

    d++;                // 路径长度加1
    path[d] = u;        // 将当前结点加入到路径中
    visited[u] = 1;     // 将u标记为已访问
    if (u == v) {       // 如果目标结点既是v, 对路径进行打印输出
        for (int j=1; j<=d; ++j) {
            printf("%d ", path[j]);
        }
        printf("\n");
    }
    // 以下递归访问u相邻的结点
    for (int i=0; i<graph[u].size(); ++i) {
        w = graph[u][i];
        if (visited[w] == 0)
            FindPath(w, v, path, d);
    }

    visited[u] = 0;
}
/**
构建图
输入数据:
2 5 9
1 4
1 7
2 4
2 5
3 5
4 6
5 6
6 7
5 8
*/
int main() {
    int src, det;
    int u, v;
    int d = 0;
    int cnt = 0;       //总边数

    scanf("%d %d %d", &u, &v, &cnt);
    while (cnt--) {
        scanf("%d %d", &src, &det);
        graph[src].push_back(det);
        graph[det].push_back(src);
    }
    printf("result: \n");
    FindPath(u, v, path, d);

    return 0;
}
