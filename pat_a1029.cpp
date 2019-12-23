#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn = 2*1e5;

int arr1[maxn], arr2[maxn];

int main(){
    int N1, N2;

    scanf("%d", &N1);
    for (int i=0; i<N1; ++i) {
        scanf("%d", &arr1[i]);
    }
    scanf("%d", &N2);
    for (int i=0; i<N2; ++i) {
        scanf("%d", &arr2[i]);
    }

    int l1 = 0, r1 = N1-1, l2 = 0, r2 = N2-1;
    int m1, m2;
    int len;
    int m;
    bool find = false;
    while (l1 < r1 && l2 < r2) {
        m1 = (l1 + r1) / 2;
        m2 = (l2 + r2) / 2;
        if (arr1[m1] == arr2[m2]){
            m = arr1[m1];
            find = true;
            break;
        } else if (arr1[m1] < arr2[m2]) {
            // 一定是左右两边扔掉同样长度的数字
            len = min(m1-l1, r2-m2); // 保证长度相等
            if (len == 0) len = 1;
            l1 += len;
            r2 -= len;
        }else{
            // m1 > m2,扔掉数组1的右边，数组2的左边
            len = min(r1-m1, m2-l2);
            if (len == 0) len = 1;
            r1 -= len;
            l2 += len;
        }
    }

    if (!find){
        if (l1 == r1) {
            m = arr1[l1];
        } else {
            m = arr2[l2];
        }
    }

    printf("%d", m);

    return 0;
}
