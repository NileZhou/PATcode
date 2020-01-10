#include<cstdio>
#include<cstdlib>

const int N = 11; // 阶乘时间复杂度

bool tags[N] = {false}; // tags[i] == true 代表i+1已填
int res[N];

void perm(int index, int n){
    if (index == n) {
        for (int i=0; i<n; ++i) {
            printf("%d ", res[i]);
        }
        printf("\n");
        return;
    }

    for (int i=0; i<n; ++i){
        if (tags[i] == false) {
            res[index] = i+1;
            tags[i] = true;
            perm(index+1, n);
            tags[i] = false;
        }
    }
}


int main() {
    perm(0, 4);

    return 0;
}
