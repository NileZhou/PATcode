/**
* 通过前序+中序 或 后序+中序来重建一棵二叉树
*/

#include<cstdio>

const int maxn = 1000;

struct Node{
    int num;
    Node* left = nullptr;
    Node* right = nullptr;
};

int pre[maxn], in[maxn], post[maxn];

Node* pre_in(int preL, int preR, int inL, int inR){
    if (preL > preR) return nullptr; // preL == preR 可以
    int i = inL;
    for (i=inL; i<=inR; ++i){
        if (pre[preL] == in[i]) break;
    }
    int left_num = i-inL;
    Node* node = new Node;
    node->num = pre[preL];
    node->left = pre_in(preL+1, preL+left_num, inL, i-1);
    node->right = pre_in(preL+left_num+1, preR, i+1, inR);
    return node;
}

Node* post_in(int postL, int postR, int inL, int inR){
    if (inL > inR) return nullptr;
    int i = inL;
    for (; i <= inR; ++i){
        if (in[i] == post[postR]) break;
    }
    int left_num = i - inL;
    Node* node = new Node;
    node->num = post[postR];
    node->left = post_in(postL, postL + left_num - 1, inL, i-1);
    node->right = post_in(postL + left_num, postR - 1, i+1, inR);
    return node;
}

int main(){
    pre[0] = 2;
    pre[1] = 1;
    pre[2] = 3;

    in[0] = 3;
    in[1] = 1;
    in[2] = 2;

    post[0] = 3;
    post[1] = 1;
    post[2] = 2;

    // Node* root = pre_in(0, 2, 0, 2);
    Node* root = post_in(0, 2, 0, 2);

    printf("%d", root->left->num);

    return 0;
}


