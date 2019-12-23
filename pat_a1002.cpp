#include<cstdio>
#include<algorithm>
#define K 10

using namespace std;

struct Node{
    int exp=0;
    double coef=0;
};

Node nodes[2*K];

bool less(Node node1, Node node2){
    return node1.exp < node2.exp; // 通过指数确定大小
}

int main(){
    int n;
    int p=0;
    scanf("%d", &n);
    for (int i=0; i<n; ++i){
        scanf("%d", &nodes[p].exp);
        scanf("%lf", &nodes[p].coef);
        p+=1;
    }
    scanf("%d", &n);
    for (int i=0; i<n; ++i){
        scanf("%d", &nodes[p].exp);
        scanf("%lf", &nodes[p].coef);
        p+=1;
    }

    sort(nodes, nodes+p, less);

    // 因为指数没有负数
    int cur = 1;
    int pre = 0;
    int cnt = 0;
    while (cur < p){
        if (nodes[cur].exp == nodes[pre].exp){
            nodes[pre].coef += nodes[cur].coef;
            if (nodes[pre].coef == 0){
                nodes[pre].exp = -1; // 还要消除之前的指数
                cnt += 1;
            }
            nodes[cur].exp = -1; // 代表将当前的指数进行消除
            cnt += 1;
        } else {
            pre = cur;
        }
        cur += 1;
    }

    cnt = p - cnt; // 总的减去被消除的，就剩下了还剩下的

    if (cnt > 0){
        printf("%d ", cnt);
        for (int i=p-1; i>=0; --i){
            if (nodes[i].exp != -1){
                if (cnt > 1){
                    printf("%d %.1lf ", nodes[i].exp, nodes[i].coef);
                    cnt -= 1;
                }else{
                    printf("%d %.1lf", nodes[i].exp, nodes[i].coef);
                }
            }
        }
    } else {
        printf("0");
    }

    return 0;
}

