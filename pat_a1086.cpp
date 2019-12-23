#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>


/**
* ����⣬ָ���Ӧ�����˺���
*
* ��Ҫ������������:
* �Լ����: �����ǰ��push, ����һ������Ҳ��push, �����������˵, �����Ϊ��һ��������, ����Ϊ��һ�����ҽ��
* PAT��: push�൱��������ǰ�����, pop�൱�������������, ���Ա���Ϊ����ǰ������������
*/

using namespace std;

struct node{
    int num;
    node* lchild = nullptr;
    node* rchild = nullptr;
    node () {}
    node(int num) {
        this->num = num;
    }
};

void post_order(node* root, vector<int>& vi){
    if (root == nullptr) return;
    stack<node*> sta;
    node* pre = nullptr;
    int cnt = 0;

    while (root){
        sta.push(root);
        root = root->lchild;
    }

    while (!sta.empty()){
        node* cur = sta.top();
        sta.pop();
        if (cur->rchild && (pre == nullptr || cur->rchild != pre)){
            sta.push(cur);
            cur = cur->rchild;
            while (cur){
                sta.push(cur);
                cur = cur->lchild;
            }
        }else{
            vi.push_back(cur->num);
            pre = cur;
        }
    }
}

stack<node*> nodes;
stack<node*> pres;
vector<int> orders;

int main(){
    int n, cnt=0, pre_push=0, pre_i=0;
    char op[5];
    node* root = nullptr;

    scanf("%d", &n);
    for (int i=0; i<2*n; ++i){
        scanf("%s", op);
        if (strcmp(op, "Push") == 0){
            node* cur = new node();
            scanf("%d", &cur->num);
            if (root == nullptr){
                root = cur;
            }else{
                if (pre_push){
                    nodes.top()->lchild = cur;
                }else{
                    pres.top()->rchild = cur;
                }
            }
            nodes.push(cur);
            pre_push = 1;
        }else{
            pres.push(nodes.top());
            nodes.pop();
            pre_push = 0;
        }
    }

    post_order(root, orders);

    for(int i=0; i<orders.size(); ++i){
        if (i == orders.size()-1){
            printf("%d", orders[i]);
        }else{
            printf("%d ", orders[i]);
        }
    }

    return 0;
}


