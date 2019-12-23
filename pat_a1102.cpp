#include<cstdio>
#include<queue>

using namespace std;

const int maxn=10;
struct node{
    int lchild = -1;
    int rchild = -1;
}nodes[maxn];

bool record[maxn] = { false };

void level_order(int iroot, vector<int>& order){
    if (iroot == -1) return;
    queue<int> que;
    que.push(iroot);
    while (!que.empty()){
        int cur = que.front(); // 取出队首元素
        que.pop();
        order.push_back(cur);
        if (nodes[cur].rchild != -1) que.push(nodes[cur].rchild);
        if (nodes[cur].lchild != -1) que.push(nodes[cur].lchild);
    }
}

void in_order(int iroot, vector<int>& order){
    if (iroot == -1) return;
    in_order(nodes[iroot].rchild, order);
    order.push_back(iroot);
    in_order(nodes[iroot].lchild, order);
}

int main(){
    int N;
    char lchild, rchild;
    int iroot = -1;
    vector<int> levels, ins;

    freopen("inputs.txt", "r", stdin);

    scanf("%d", &N);
    for (int i=0; i<N; ++i){
        scanf("\n%c %c", &lchild, &rchild); // notice that we need last line's \n
        if (lchild != '-') {
            nodes[i].lchild = lchild - '0';
            record[nodes[i].lchild] = true;
        }
        if (rchild != '-') {
            nodes[i].rchild = rchild - '0';
            record[nodes[i].rchild] = true;
        }
    }

    for (int i=0; i<N; ++i){
        if (record[i] == false) {
            iroot = i;
            break;
        }
    }

    level_order(iroot, levels);

    for (int i=0; i<levels.size(); ++i){
        if (i < levels.size()-1){
            printf("%d ", levels[i]);
        }else{
            printf("%d\n", levels[i]);
        }
    }

    in_order(iroot, ins);

    for (int i=0; i<ins.size(); ++i){
        if (i < ins.size()-1){
            printf("%d ", ins[i]);
        }else{
            printf("%d", ins[i]);
        }
    }

    return 0;
}


