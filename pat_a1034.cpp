#include<cstdio>
#include<string>
#include<map>

using namespace std;

const int MAXV = 1005;

map<string, int> si; // name -> id
map<int, string> is; // id -> name 输出结果需要
map<string, int> res; // name -> cnt 保存结果

int ws[MAXV] = {0};
bool vis[MAXV] = {false};
int G[MAXV][MAXV] = {0};

void dfs(int cur, int n, int& max_id, int& total, int& cnt){
    vis[cur] = true;
    cnt++;
    if (ws[cur] > ws[max_id]){
        max_id =  cur;
    }
    for (int i=0; i<n; ++i){
        if (vis[i] == false && G[cur][i] != 0) {
            total += G[cur][i]; // total 应该是加上边权而不是加上结点权值
            // 需要剪断回来的边
            G[i][cur] = G[cur][i] = 0;
            dfs(i, n, max_id, total, cnt);
        }
    }
}

void dfs_travel(int n, int k){
    for (int i=0; i<n; ++i){
        if (vis[i] == false){
            int max_id=i, total=0, cnt=0;
            dfs(i, n, max_id, total, cnt);
            if (cnt > 2 && total > k){
                res[is[max_id]] = cnt;
            }
        }
    }
}

int main(){
    string name1, name2;
    int time;
    int id1, id2;
    int n, k;
    int n_person = 0;

    scanf("%d %d", &n, &k);
    for (int i=0; i<n; ++i) {
        scanf("%s %s %d", &name1, &name2, &time);
        if (si.find(name1) == si.end()) {
            si[name1] = n_person;
            n_person += 1;
        }
        if (si.find(name2) == si.end()) {
            si[name2] = n_person;
            n_person += 1;
        }
        id1 = si[name1];
        id2 = si[name2];

        printf("%d %d\n", id1, id2);

        is[id1] = name1;
        is[id2] = name2;

        ws[id1] += time;
        ws[id2] += time;

        G[id1][id2] += time;
        G[id2][id1] += time;
    }

    printf("%d\n", n_person);

    dfs_travel(n, k);
    for (map<string, int>::iterator it = res.begin(); it != res.end(); it++){
        printf("%s %d", it->first, it->second);
    }

    return 0;
}
