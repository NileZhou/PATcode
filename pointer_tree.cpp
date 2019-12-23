#include<cstdio>

/**
* this is an ordinary binary tree
*/

const int maxn = 1000;

struct Node{
    int num;
    Node* left = NULL;
    Node* right = NULL;
};

void search_node(Node* root, Node*& res, int num){
    if (root == NULL) return;
    if (root->num == num){
        res = root;
    }else{
        search_node(root->left, res, num);
        search_node(root->right, res, num);
    }
}

void insert_node(Node*& root, int num){
    if (root == NULL) {
        root = new Node;
        root->num = num;
        return;
    }
    // 这里的1应该根据实际情况进行调整
    if (1){
        insert_node(root->left, num);
    }else{
        insert_node(root->right, num);
    }
}

// 普通创建二叉树的办法
Node* create(int nums[], int n){
    Node* root = NULL;
    for (int i=0; i<n; ++i){
        insert_node(root, nums[i]);
    }

    return root;
}

// 根据自定义的数组进行二叉树的创建
// space 代表不能进行操作的空位
Node* create_tree(int nums[], int n, int space){
    if (n == 0) return NULL;

    Node* nodes[n];

    for (int i=0; i<n; ++i){
        if (nums[i] != space){
            nodes[i] = new Node;
            nodes[i]->num = nums[i];
        }
    }

    Node* root = nodes[0];
    for (int i=0; (2*i+1)<n; ++i){
        if (nums[i] != space){
            int left = 2*i+1, right = 2*i+2;
            if (left < n && nums[left] != space){
                nodes[i]->left = nodes[left];
            }
            if (right < n && nums[right] != space){
                nodes[i]->right = nodes[right];
            }
        }
    }

    return root;
}

void pre_order(Node* root){
    if (root == NULL) return;
    printf("%d ", root->num);
    if (root->left != NULL){
        pre_order(root->left);
    }
    if (root->right != NULL){
        pre_order(root->right);
    }
}

void pre_order2(Node* root){
    // 压栈的时候进行输出
    if (root == NULL) return;
    int cnt = 0;
    Node* nodes[maxn];

    Node* p = root;

    while (p){
        printf("%d ", p->num);
        nodes[cnt++] = p;
        if (p->left) p = p->left;
    }

    while (cnt > 0){
        p = nodes[--cnt];
        if (p->right){
            p = p->right;
            while (p){
                printf("%d ", p->num);
                nodes[cnt++] = p;
                if (p->left) p = p->left;
            }
        }
    }
}


void in_order(Node* root){
    if (root == nullptr) return;
    if (root->left) in_order(root->left);
    printf("%d ", root->num);
    if (root->right) in_order(root->right);
}

void in_order2(Node* root){
    // 弹出的时候进行输出
    if (root == nullptr) return;
    Node* nodes[maxn];
    int cnt = 0;
    Node* p = root;

    while (p){
        nodes[cnt++] = p;
        p = p->left;
    }

    while (cnt > 0){
        p = nodes[--cnt];
        printf("%d ", p->num);
        if (p->right){
            p = p->right;
            while (p){
                nodes[cnt++] = p;
                p = p->left;
            }
        }
    }
}

void post_order(Node* root){
    if (root == nullptr) return;
    if (root->left) post_order(root->left);
    if (root->right) post_order(root->right);
    printf("%d ", root->num);
}

void post_order2(Node* root){
    if (root == nullptr) return;
    Node* nodes[maxn];
    int cnt = 0;
    Node* p = root;
    Node* pre = nullptr;
    while (p){
        nodes[cnt++] = p;
        p = p->left;
    }

    while (cnt > 0){
        p = nodes[--cnt]; // 弹出之后压右边的
        if (p->right && (pre == nullptr || pre != p->right)){
            nodes[cnt++] = p;// 弹出以后还要再压回去
            p = p->right;
            while (p){
                nodes[cnt++] = p;
                p = p->left;
            }
        }else{
            printf("%d ", p->num);
            pre = p;
        }
    }
}

void level_order(Node* root){
    if (root == nullptr) return;
    Node* nodes[maxn]; // create a queue
    Node* p = nullptr;
    int head = 0, tail = 0;
    nodes[tail++] = root;

    while (head < tail){
        p = nodes[head++];
        printf("%d ", p->num);
        if (p->left) nodes[tail++] = p->left;
        if (p->right) nodes[tail++] = p->right;
    }
}


int main(){
    int nums[10] = {1, 2, 3, 4, 5, 0, 6};
    Node* root = create_tree(nums, 7, 0);

    return 0;
}
