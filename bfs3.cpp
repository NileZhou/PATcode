// 有顶点层号需求的bfs
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int maxn = 1000;
int n = 100;
struct Node{
    int v; // 顶点编号
    int layer; // 层号
};

bool inq[maxn] = {false};
vector<Node> G[maxn];

void bfs(int v){
    queue<Node> q;
    Node start;
    start.v = v;
    start.layer = 0;
    q.push(start);
    inq[v] = true;
    while(!q.empty()){
        Node cur = q.front();
        q.pop();
        for (int i=0; i<G[cur.v].size(); ++i){
            Node next = G[cur.v][i];
            // next.layer = cur.layer + 1; // 看这行是加在这里还是下面，看具体情况
            if (!inq[next.v]){
                next.layer = cur.layer + 1;
                q.push(next);
                inq[next.v] = true;
            }
        }
    }
}
