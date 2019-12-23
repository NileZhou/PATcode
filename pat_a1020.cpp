#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

const int maxn = 30;

int post[maxn], in[maxn];

struct Node{
    int num;
    Node* lchild = nullptr;
    Node* rchild = nullptr;
};

Node* rebuild(int postL, int postR, int inL, int inR){
    if (postL > postR) return nullptr;
    int i=inL;
    for (; i <= inR; ++i){
        if (in[i] == post[postR]) break;
    }
    int left_num = i-inL;
    Node* node = new Node;
    node->num = post[postR];
    node->lchild = rebuild(postL, postL+left_num-1, inL, i-1);
    node->rchild = rebuild(postL+left_num, postR-1, i+1, inR);
    return node;
}

void layer_traversal(Node* root, int cnt){
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    int i=0;
    while (!q.empty()){
        Node* cur = q.front();
        q.pop();
        printf("%d", cur->num);
        if (i < cnt-1) {
            printf(" ");
            i += 1;
        }
        if (cur->lchild) q.push(cur->lchild);
        if (cur->rchild) q.push(cur->rchild);
    }
}


int main(){
    int n;

    while (~scanf("%d", &n)){
        for (int i=0; i<n; ++i) scanf("%d", &post[i]);
        for (int i=0; i<n; ++i) scanf("%d", &in[i]);

        Node* root = rebuild(0, n-1, 0, n-1);
        layer_traversal(root, n);
    }

    return 0;
}

