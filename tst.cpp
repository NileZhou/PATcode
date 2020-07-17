#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

const double PI = acos(-1.0);
const double EPS = 1e-6;
const int INF = 0x7fffffff;
const int N = 4;

int arr[N] = {INF}; // 这样只会把第一个格子替换为INF, 其它格子还是0
int arr2[N];
int G[N][N] = {INF}; // 如果 = {INF}, 还是只能把第一个格子转化为INF

int main() {
    size_t a;
    size_t *b;
    printf("sizeof size_t: %lu , sizeof size_t*: %lu\n", sizeof(a), sizeof(b));
    int c;
    int *d;
    printf("sizeof int: %lu, sizeof int*: %lu\n", sizeof(c), sizeof(d));
    for (int i=0; i<N; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    fill(arr2, arr2+N, INF);
    for (int i=0; i<N; ++i) {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    // fill(G, G+N*N, INF); 不能这样做
    // fill_n(&G[0][0], sizeof(G)/sizeof(**G), INF); // 这样可以做到填满整个二维数组
    printf("sizeof(G): %lu\n", sizeof(G));
    printf("sizeof(**G): %lu\n", sizeof(**G));
    fill_n(&G[0][0], N*N, INF);
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

