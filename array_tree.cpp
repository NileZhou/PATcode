#include<cstdio>
#include<vector>

using namespace std;

/**
* introduce the statistical write way of binary tree
**/

const int maxn = 1000;

struct Node{
    int num;
    int lchild = -1; // use -1 or maxn to express empty, because the range of lchild between [0, maxn-1]
    int rchild = -1;
}tree[maxn];

int index = 0;

// return the index at the tree
int new_node(int num){
    tree[index].num = num;
    tree[index].lchild = -1;
    tree[index].rchild = -1;
    return index++;
}

int create_node(int num){

}

int main(){


    return 0;
}
