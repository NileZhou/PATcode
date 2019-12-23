#include<cstdio>
#include<cstdlib>

struct node{
    int num;
    node* lchild = nullptr;
    node* rchild = nullptr;
};

void search_node(node* root, int x){
    if (root == nullptr){
        printf("search failed\n");
        return;
    }

    if (root->num < x){
        search_node(root->rchild, x);
    }else{
        search_node(root->lchild, x);
    }
}

void insert_node(node* &root, int x){
    if (root == nullptr){
        root = new node;
        root->num = x;
        return; // 曾因为这里缺少语句而错
    }
    if (root->num < x){
        insert_node(root->rchild, x);
    }else{
        insert_node(root->lchild, x);
    }
}

node* create(int nums[], int n){
    if (n == 0) return nullptr;
    node* root = nullptr; // 一定要赋值为nullptr
    for (int i=0; i<n; ++i){
        insert_node(root, nums[i]);
    }
    return root;
}

node* find_max(node* root){
    if (root == nullptr) return root;
    while (root->rchild){
        root = root->rchild;
    }
    return root;
}

node* find_min(node* root){
    if (root == nullptr) return root;
    while (root->lchild){
        root = root->lchild;
    }
    return root;
}

void delete_node(node*& root, int num){
    if (root == nullptr) return;
    if (root->num == num){
        // 进行删除处理
        if (root->lchild == nullptr && root->rchild == nullptr){
            free(root);
            root = nullptr;
        } else if (root->lchild != nullptr){ // 先删除root的前驱结点
            node* tmp = nullptr;
            if (root->lchild->rchild == nullptr) { // 如果root的左结点就该被删除
                tmp = root->lchild;
                root->num = tmp->num;
                root->lchild = root->lchild->lchild;
            } else{
                node* p = root->lchild;
                while (p->rchild->rchild != nullptr){
                    p = p->rchild;
                }
                tmp = p->rchild; // tmp 代表要删除的结点
                root->num = tmp->num;
                p->rchild = p->rchild->lchild;
            }
            free(tmp);
        } else{ // 只能删除root结点的后继
            node* tmp = nullptr;
            if (root->rchild->lchild == nullptr){ // 若root得右结点应被删除
                tmp = root->rchild;
                root->num = tmp->num;
                root->rchild = root->rchild->rchild;
            }else{
                node* p = root->rchild;
                while (p->lchild->lchild != nullptr){
                    p = p->lchild;
                }
                tmp = p->lchild;
                root->num = tmp->num;
                p->lchild = p->lchild->rchild;
            }
            free(tmp);
        }
    } else if (root->num < num){
        delete_node(root->rchild, num);
    } else{
        delete_node(root->lchild, num);
    }
}

// 对二叉查找树进行中序遍历, 遍历结果是有序的
void inorder(node* root){
    if (root == nullptr) return;
    node* nodes[10];
    int cnt = 0;
    while (root){
        nodes[cnt++] = root;
        root = root->lchild;
    }
    while (cnt > 0){
        node* cur = nodes[--cnt];
        printf("%d ", cur->num);
        if (cur->rchild){
            node* p = cur->rchild;
            while (p){
                nodes[cnt++] = p;
                p = p->lchild;
            }
        }
    }
}

int main(){
    int data[7] = {5, 3, 7, 2, 4, 6, 8};

    node* root = create(data, 7);
    printf("%d\n", root->rchild->lchild->num);
    delete_node(root, 6);
    printf("%d\n", root->rchild->lchild);

    inorder(root);

    return 0;
}
