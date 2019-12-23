#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 1010;
int father[N];
int is_root[N] = {0};
int course[N] = {0};

int find_father(int x){
    int root = x;
    while (root != father[root]){
        root = father[root];
    }

    while (x != father[x]){
        int tmp = x;
        x = father[x];
        father[tmp] = root;
    }

    return root;
}

void union_set(int a, int b){
    int fa = find_father(a), fb = find_father(b);
    if (fa != fb){
        father[fa] = fb;
    }
}

void init(int n){
    for (int i=1; i<=n; ++i){
        father[i] = i; // 一开始初始化了
        is_root[i] = false;
    }
}

bool cmp(int a, int b){
    return a > b;
}

int main(){
    int n, k, h;

    freopen("inputs.txt", "r", stdin);

    scanf("%d", &n);
    init(n);
    for (int i=1; i<=n; ++i){
        scanf("%d:", &k);
        for (int j=0; j<k; ++j){
            scanf("%d", &h);
            if (course[h] == 0){
                course[h] = i;
            }
            union_set(i, course[h]);
        }
    }

    for (int i=1; i<=n; ++i){
        is_root[find_father(i)]++;
    }
    int ans = 0;
    for (int i=1; i<=n; ++i){
        if (is_root[i]){
            ans++;
        }
    }

    printf("%d\n", ans);
    sort(is_root+1, is_root+1+n, cmp);
    for (int i=1; i<=ans; ++i){
        printf("%d", is_root[i]); // is_root其实是用来计数的
        if (i < ans) printf(" ");
    }

    return 0;
}
