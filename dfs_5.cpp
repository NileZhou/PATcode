#include<cstdio>
#define MaxVertexNum 10 //顶点数最大为10

int visited[MaxVertexNum] = {0};
int record[MaxVertexNum] = {0}; // hash, 记录是否被存储

typedef struct ArcNode {        // 边表结点
    int adjvex;         // 该弧所指向的顶点的位置
    struct ArcNode *nextarc;   // 下一条弧
};

typedef struct VNode {        // 顶点表结点
    int data;           // 顶点信息
    struct ArcNode *firstarc;  // 指向第一条依附于该结点的弧
}AdjList[MaxVertexNum];

typedef struct AGraph {
    AdjList adjlist;    // 邻接表
    int vexnum, arcnum; // 图的顶点数和弧数
};

// 递归查找并打印所有u->v的简单路径
void FindPath(AGraph *G, int u, int v, int path[], int d) {
    int w, i;
    ArcNode *p;
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
    p = G->adjlist[u].firstarc;
    while (p != NULL) {
        w = p->adjvex;
        if (visited[w] == 0)
            FindPath(G, w, v, path, d);
        p = p->nextarc;
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
    // 构建图
    AGraph graph;
    int src, det;
    int u, v;
    int path[MaxVertexNum] = {-1};
    int d = 0;
    int cnt = 0;       //总边数

    scanf("%d %d %d", &u, &v, &cnt);
    while (cnt--) {
        scanf("%d %d", &src, &det);
        ArcNode s2d, d2s; // 从src到det的弧，从det到src的弧
        s2d.adjvex = det;
        d2s.adjvex = src;
        s2d.nextarc = NULL;
        d2s.nextarc = NULL;
        if (record[src] == 0) {
            graph.adjlist[src].firstarc = &s2d;
            graph.vexnum++;
            record[src] = 1;
        } else {
            s2d.nextarc = graph.adjlist[src].firstarc->nextarc;
            graph.adjlist[src].firstarc = &s2d;
        }
        if (record[det] == 0) {
            graph.adjlist[det].firstarc = &d2s;
            graph.vexnum++;
            record[det] = 1;
        } else {
            d2s.nextarc = graph.adjlist[det].firstarc->nextarc;
            graph.adjlist[det].firstarc = &d2s;
        }

        graph.arcnum += 2;
    }

    printf("result: \n");
    FindPath(&graph, u, v, path, d);

    return 0;
}
