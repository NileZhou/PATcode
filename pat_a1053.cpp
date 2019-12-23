#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int maxn = 100;

struct Node{
    int num;
    vector<Node*> childs;
};

bool cmp(Node* node1, Node* node2){
    return node1->num > node2->num;
}

void dfs(vector<int> nums, int sum, int target, Node* root){
    if (root == nullptr) return;
    sum += root->num;
    if (sum == target){
        if (root->childs.size() != 0) return; // it's not the leaf node
        for (int i=0; i<nums.size(); ++i){
            printf("%d ", nums[i]);
        }
        printf("%d\n", root->num);
    } else if (sum < target){
        nums.push_back(root->num);
        // 不用退出一个. 因为递归会默认保存函数状态, 然后进行压栈与退栈
        for (int i=0; i<root->childs.size(); ++i){
            dfs(nums, sum, target, root->childs[i]);
        }
    }
}

int main(){
    int N, M, S, id, n_child, id_child;
    vector<int> nums;

    scanf("%d %d %d", &N, &M, &S);

    Node* tree[maxn];

    for (int i=0; i<N; ++i){
        tree[i] = new Node;
        scanf("%d", &tree[i]->num);
    }

    for (int i=0; i<M; ++i){
        scanf("%d", &id);
        scanf("%d", &n_child);
        for (int j=0; j<n_child; j++){
            scanf("%d", &id_child);
            tree[id]->childs.push_back(tree[id_child]);
        }
        sort(tree[id]->childs.begin(), tree[id]->childs.end(), cmp);
    }

    dfs(nums, 0, S, tree[0]);

    // printf("%d", sizeof(int*)); // 32位程序, 这里为4, 64位程序为8

    return 0;
}
