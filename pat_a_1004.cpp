#include<cstdio>
#include<vector>
#include<cmath>

const int maxn = 105;

using namespace std;

vector<int> nodes[maxn];
int visit[maxn] = {0}; // store the num of every levels leaf child
int mx = 0; // the max level

void dfs(int id, int le){ // the id of current, the level of current
    mx = max(mx, le);
    if (nodes[id].size() == 0) {
        visit[le] += 1;
    } else {
        for (int i=0; i<nodes[id].size(); ++i) {
            dfs(nodes[id][i], le+1);
        }
    }
}

int main(){
    int nn, nl; // num of node and num of non-leaf node
    int id, nc, cid;

    scanf("%d %d", &nn, &nl);

    for (int i=0; i<nl; ++i) {
        scanf("%d %d", &id, &nc); // read the id of node, num of its child
        for (int j=0; j<nc; ++j) {
            scanf("%d", &cid);
            nodes[id].push_back(cid);
        }
    }

    dfs(1, 0); // the id of root, the level of root

    for (int i=0; i<mx; ++i) {
        printf("%d ", visit[i]);
    }
    printf("%d", visit[mx]);

    return 0;
}
