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
        return; // ����Ϊ����ȱ��������
    }
    if (root->num < x){
        insert_node(root->rchild, x);
    }else{
        insert_node(root->lchild, x);
    }
}

node* create(int nums[], int n){
    if (n == 0) return nullptr;
    node* root = nullptr; // һ��Ҫ��ֵΪnullptr
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
        // ����ɾ������
        if (root->lchild == nullptr && root->rchild == nullptr){
            free(root);
            root = nullptr;
        } else if (root->lchild != nullptr){ // ��ɾ��root��ǰ�����
            node* tmp = nullptr;
            if (root->lchild->rchild == nullptr) { // ���root������͸ñ�ɾ��
                tmp = root->lchild;
                root->num = tmp->num;
                root->lchild = root->lchild->lchild;
            } else{
                node* p = root->lchild;
                while (p->rchild->rchild != nullptr){
                    p = p->rchild;
                }
                tmp = p->rchild; // tmp ����Ҫɾ���Ľ��
                root->num = tmp->num;
                p->rchild = p->rchild->lchild;
            }
            free(tmp);
        } else{ // ֻ��ɾ��root���ĺ��
            node* tmp = nullptr;
            if (root->rchild->lchild == nullptr){ // ��root���ҽ��Ӧ��ɾ��
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

// �Զ�������������������, ��������������
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
