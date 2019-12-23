#include<cstdio>
#include<vector>

using namespace std;

const int maxn = 1000;

int arr[maxn];

struct node{
    int num;
    node *lchild = nullptr;
    node *rchild = nullptr;
    node(){};
    node (int num){
        this->num = num;
    }
};

void insert_bst(node*& root, int x){
    if (root == nullptr) {
        root = new node(x);
        return;
    }
    if (root->num > x){
        insert_bst(root->lchild, x);
    }else{
        insert_bst(root->rchild, x);
    }
}

node* create_bst(int data[], int n){
    if (n == 0) return nullptr;
    node* root = nullptr;
    for (int i=0; i<n; ++i){
        insert_bst(root, data[i]);
    }
    return root;
}

void insert_mirror(node*& root, int x){
    if (root == nullptr){
        root = new node(x);
        return;
    }
    if (root->num <= x){
        insert_mirror(root->lchild, x);
    }else{
        insert_mirror(root->rchild, x);
    }
}

node* create_mirror(int data[], int n){
    if (n == 0) return nullptr;
    node* root = nullptr;
    for (int i=0; i<n; ++i){
        insert_mirror(root, data[i]);
    }
    return root;
}

vector<int> pre_order(node* root){
    vector<int> vi;
    if (root == nullptr) return vi;
    node* nodes[maxn];
    int cnt = 0;

    while (root){
        vi.push_back(root->num);
        nodes[cnt++] = root;
        root = root->lchild;
    }

    while (cnt > 0){
        node* cur = nodes[--cnt];
        if (cur->rchild){
            cur = cur->rchild;
            while (cur){
                vi.push_back(cur->num);
                nodes[cnt++] = cur;
                cur = cur->lchild;
            }
        }
    }

    return vi;
}

vector<int> post_order(node* root){
    vector<int> vi;
    if (root == nullptr) return vi;
    node* nodes[maxn];
    node* pre = nullptr;
    int cnt = 0;

    while (root){
        nodes[cnt++] = root;
        root = root->lchild;
    }

    while (cnt > 0){
        node* cur = nodes[--cnt];
        if (cur->rchild && (pre == nullptr || pre != cur->rchild)){
            nodes[cnt++] = cur;
            cur = cur->rchild;
            while (cur){
                nodes[cnt++] = cur;
                cur = cur->lchild;
            }
        }else{
            vi.push_back(cur->num);
            pre = cur;
        }
    }

    return vi;
}

bool check_match(int origin[], vector<int> vi, int n){
    for (int i=0; i<n; ++i){
        if (vi[i] != origin[i]) {
            return false;
        }
    }
    return true;
}

int main(){
    int N;

    scanf("%d", &N);
    for (int i=0; i<N; ++i){
        scanf("%d", &arr[i]);
    }

    node* root = create_bst(arr, N);
    vector<int> bst_order = pre_order(root);
    if (check_match(arr, bst_order, N)){
        printf("YES\n");
        vector<int> bst_post = post_order(root);
        for (int i=0; i<N; ++i){
            if (i != N-1){
                printf("%d ", bst_post[i]);
            }else{
                printf("%d", bst_post[i]);
            }
        }
    }else{
        node* root = create_mirror(arr, N);
        vector<int> mirror_pre = pre_order(root);
        if (check_match(arr, mirror_pre, N)){
            printf("YES\n");
            vector<int> mirror_post = post_order(root);
            for (int i=0; i<N; ++i){
                if (i != N-1){ m
                    printf("%d ", mirror_post[i]);
                }else{
                    printf("%d", mirror_post[i]);
                }
            }
        }else{
            printf("NO");
        }
    }

    return 0;
}
