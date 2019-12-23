#include<cstdio>

/**
* 带路径压缩的并查集
*/

const int maxn = 100;

int father[maxn];

// 一开始每个元素都是独立的集合
void init(int N){
    for (int i=0; i<N; ++i){
        father[i] = i;
    }
}

// 合并两个结点在的集合
void union_set(int a, int b){
    int fa = find_father(a), fb = find_father(b);
    if (fa == fb) return;
    father[fa] = fb; // 让集合a的根节点指向集合b的根节点
}

// 返回num所在集合的根节点(带路径压缩)
int find_father(int num){
    int root = num;
    while (root != father[root]){
        root = father[root];
    }

    while (num != root){
        int tmp = num;
        num = father[num];
        father[tmp] = root; // 原先的结点的父节点改为根节点
    }
}

int main(){



    return 0;
}

