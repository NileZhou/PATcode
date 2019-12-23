#include<cstdio>
#include<algorithm>

using namespace std;

struct node{
    int v, height;
    node *lchild = nullptr;
    node *rchild = nullptr;
};

node* new_node(int v){
    node* Node = new node;
    Node->v = v;
    Node->height = 1; // 初始高度为1
    return Node;
}

int get_height(node* root){
    if (root == nullptr) return 0;
    return root->height;
}

// 这个值必须在[-1, 1]之间
int get_balance_factor(node* root){
    return get_height(root->lchild) - get_height(root->rchild);
}

void update_height(node* root){
    root->height = max(get_height(root->lchild), get_height(root->rchild)) + 1;
}

// 纯查找操作
void search_node(node* root, int v){
    if (root == nullptr) return;
    if (root->v == v) {
        printf("%d\n", v);
    } else if (root->v > v){
        search_node(root->lchild, v);
    } else{
        search_node(root->rchild, v);
    }
}

// 左旋
void L(node* &root){
    node* tmp = root->rchild;
    root->rchild = tmp->lchild;
    tmp->lchild = root;
    update_height(root);
    update_height(tmp);
    root = tmp;
}

// 右旋
void R(node* & root){
    node* tmp = root->lchild;
    root->lchild = tmp->rchild;
    tmp->rchild = root;
    update_height(root);
    update_height(tmp);
    root = tmp;
}

void insert_node(node* &root, int v){
    if (root == nullptr) {
        root = new_node(v);
        return;
    }
    if (root->v > v){
        insert_node(root->lchild, v);
        update_height(root); // 是为了让上面的结点获取到失衡信息
        if (get_balance_factor(root) == 2){ // LL或LR型
            if (get_balance_factor(root->lchild) == 1) { // LL
                R(root);
            } else if (get_balance_factor(root->lchild) == -1){ // LR
                L(root->lchild); // 变为LL
                R(root);
            }
        }
    } else {
        insert_node(root->rchild, v);
        update_height(root);
        if (get_balance_factor(root) == -2){ // RR或RL
            if (get_balance_factor(root->rchild) == -1){ // RR
                L(root);
            }else if(get_balance_factor(root->rchild) == 1){ // RL
                R(root->rchild);
                L(root);
            }
        }
    }
}


node* create(int data[], int n){
    node* root = nullptr;
    for (int i=0; i<n; ++i){
        insert_node(root, data[i]);
    }
    return root;
}



int main(){
    int arr[20] = {3,5,6,7,1,2,3,4,5,6,0,9,8,7,6,5,4,3,2,1};

    node* root = create(arr, 20);

    printf("%d\n", root->lchild->v);

    return 0;
}



