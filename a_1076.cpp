#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int const maxn = 1000;

struct Node{
    int id;
    int layer;
};

bool G[maxn][maxn] = {false}; // G[i][j] 从i->j i关注j
bool inq[maxn] = {false};

int main(){
    int N, L, k, cnt, num;

    cin >> N >> L;
    for (int i=0; i<N; ++i){
        cin >> cnt;
        for (int j=0; j<cnt; ++j){
            cin >> num;
            G[num][i] = true; // user[num] follows user[i]
        }
    }
    cin >> k;
    for (int i=0; i<k; ++i){
        memset(inq, false, sizeof(inq));
        cin >> num;

    }

    return 0;
}

