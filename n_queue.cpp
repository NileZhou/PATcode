#include<cstdio>
#include<cmath>

using namespace std;

const int N = 10;

bool cols[N] = {false};
int res[N];

int cnt = 0; // counter

void arrange(int index, int n) {
    if (index == n) {
        for (int i=0; i<n; ++i) {
            // 2: 这里的+1不要放到下面去了，因为res[i]参与距离计算
            printf("%d ", res[i] + 1);
        }
        printf("\n");
        cnt++;
    }

    for (int i=0; i<n; ++i) {
        if (cols[i] == false) {
            bool peace = true;
            // 只要其中一个冲突，就不能放置
            for (int j=0; j<index; ++j) {
                // 1: 这里要清楚仔细些
                // index-j: 纵向差距
                // i-res[j]: 横向差距
                if (abs(index-j) == abs(i-res[j])) {
                    peace = false;
                    break;
                }
            }
            if (peace) {
                cols[i] = true;
                res[index] = i;
                arrange(index+1, n);
                cols[i] = false;
            }
        }
    }
}


int main() {
    arrange(0, 8);
    printf("\nnum of all arrange: %d\n", cnt);

    return 0;
}

