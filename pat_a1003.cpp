#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXV = 500;
const int INF = 1e9;

int G[MAXV][MAXV];
int team[MAXV];
int tm[MAXV]; // 记录每个城市最大救援队数量
int lens[MAXV];
int path[MAXV];
bool visit[MAXV];

int N, M; // 城市数量，路径数量

void Dijkstra(int st){
    // 养成习惯，初始化放在函数里(以后有可能会有多个实例共同运行的时候)
    fill(lens, lens+MAXV, INF);
    // memset是对每一个字节做赋值
    memset(path, 0, sizeof(path));
    memset(visit, 0, sizeof(visit));
    memset(tm, 0, sizeof(tm));

    lens[st] = 0;
    path[st] = 1;
    tm[st] = team[st];
    int cur, min_len;

    for (int i=0; i<N; ++i) {
        cur = -1;
        min_len = INF;
        for (int j=0; j<N; ++j){
            if (visit[j] == false && lens[j] < min_len){
                cur = j;
                min_len = lens[j];
            }
        }
        if (cur == -1) return;
        visit[cur] = true;

        for (int j=0; j<N; ++j){
            if (visit[j] == false && G[cur][j] != INF){
                if (lens[cur] + G[cur][j] < lens[j]) {
                    lens[j] = lens[cur] + G[cur][j];
                    tm[j] = tm[cur] + team[j];
                    path[j] = path[cur];
                } else if (lens[cur] + G[cur][j] == lens[j]) {
                    path[j] += path[cur];
                    if (tm[cur] + team[j] > tm[j]){
                        tm[j] = tm[cur] + team[j];
                    }
                }
            }
        }
    }
}

int main(){
    int st, ed; // 开始城市，到达城市
    int src, det, len; // 每条路径的开始城市，到达城市，路径长度

    fill(G[0], G[0] + MAXV*MAXV, INF);

    scanf("%d %d %d %d", &N, &M, &st, &ed);
    for (int i=0; i<N; ++i){
        scanf("%d", &team[i]);
    }
    for (int i=0; i<M; ++i){
        scanf("%d %d %d", &src, &det, &len);
        G[src][det] = G[det][src] = len;
    }
    
    // Dijkstra
    Dijkstra(st);
    
    printf("%d %d\n", path[ed], tm[ed]);

    return 0;
}
