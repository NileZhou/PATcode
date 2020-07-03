#include<cstdio>
#include<map>
#include<vector>

using namespace std;

const int maxn = 2005;

double exps[maxn] = {0};
map<int, double> polys;

int main() {
    int m, n;
    int e; // exponent
    double coef; // coeficient
    
    scanf("%d", &m);
    for (int i=0; i<m; ++i) {
        scanf("%d %lf", &e, &coef);  // 指数与系数
        polys[e] = coef;
    }
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        scanf("%d %lf", &e, &coef);
        for (auto &it : polys)  {
            exps[it.first + e] += it.second * coef; // 指数相加，系数相乘
        }
    }
    
    vector<double> vec;
    
    for (int i=maxn-1; i >= 0; --i) {
        if (exps[i] != 0) {
            vec.push_back(i);
            vec.push_back(exps[i]);
        }
    }

    long long vlen = vec.size();
    int cnt = vlen / 2; // 只能用 / 不能用 //
    
    printf("%d ", cnt);
    
    for (int i=0; i < cnt-1; ++i) {
        printf("%.0lf %.1lf ", vec[2*i], vec[2*i+1]);
    }
    if (cnt > 0) {
        printf("%.0lf %.1lf", vec[2*cnt-2], vec[2*cnt-1]);
    }
    
    return 0;
}
