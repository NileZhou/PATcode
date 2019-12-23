#include<cstdio>
#include<set>

using namespace std;

const int maxn = 1e4;

int pairs[maxn][2];
int color[maxn];

int n; // 结点数
int m; // 边的数量

int main(){
    scanf("%d %d", &n, &m);

    for (int i=0; i<m; ++i) {
        scanf("%d %d", &pairs[i][0], &pairs[i][1]);
    }

    int K;

    scanf("%d", &K);
    for (int i=0; i<K; ++i) {
        set<int> colors;
        for (int j=0; j<n; ++j) {
            scanf("%d", &color[j]);
            colors.insert(color[j]);
        }

        int can_color = true;
        for (int k=0; k<m; ++k) {
            if (color[pairs[k][0]] == color[pairs[k][1]]) {
                can_color = false;
                break;
            }
        }

        if (can_color) {
            printf("%lu-coloring", colors.size());
        } else {
            printf("No");
        }

        if (i < K-1) {
            printf("\n");
        }
    }

    return 0;
}
