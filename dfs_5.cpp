#include<cstdio>
#define MaxVertexNum 10 //���������Ϊ10

int visited[MaxVertexNum] = {0};
int record[MaxVertexNum] = {0}; // hash, ��¼�Ƿ񱻴洢

typedef struct ArcNode {        // �߱���
    int adjvex;         // �û���ָ��Ķ����λ��
    struct ArcNode *nextarc;   // ��һ����
};

typedef struct VNode {        // �������
    int data;           // ������Ϣ
    struct ArcNode *firstarc;  // ָ���һ�������ڸý��Ļ�
}AdjList[MaxVertexNum];

typedef struct AGraph {
    AdjList adjlist;    // �ڽӱ�
    int vexnum, arcnum; // ͼ�Ķ������ͻ���
};

// �ݹ���Ҳ���ӡ����u->v�ļ�·��
void FindPath(AGraph *G, int u, int v, int path[], int d) {
    int w, i;
    ArcNode *p;
    d++;                // ·�����ȼ�1
    path[d] = u;        // ����ǰ�����뵽·����
    visited[u] = 1;     // ��u���Ϊ�ѷ���
    if (u == v) {       // ���Ŀ�������v, ��·�����д�ӡ���
        for (int j=1; j<=d; ++j) {
            printf("%d ", path[j]);
        }
        printf("\n");
    }
    // ���µݹ����u���ڵĽ��
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
����ͼ
��������:
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
    // ����ͼ
    AGraph graph;
    int src, det;
    int u, v;
    int path[MaxVertexNum] = {-1};
    int d = 0;
    int cnt = 0;       //�ܱ���

    scanf("%d %d %d", &u, &v, &cnt);
    while (cnt--) {
        scanf("%d %d", &src, &det);
        ArcNode s2d, d2s; // ��src��det�Ļ�����det��src�Ļ�
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
