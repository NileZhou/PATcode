#include<cstdio>
#include<map>

using namespace std;

const int maxn = 20;

int exps[maxn];
map<int, double> polys;

int main() {
    int m, n;
    int e; // exponent
    double coef; //coeficient

    scanf("%d", &m);
    for (int i=0; i<m; ++i) {
        scanf("%d %lf", &e, &coef);
    }
    scanf("%d", n);
    for (int i=0; i<n; ++i) {
        scanf("%d %lf", &e, &coef);
    }

    return 0;
}
