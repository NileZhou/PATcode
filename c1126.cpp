#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 100;

// 本题贪心的思路错了，一开始的贪心策略是将所有区间重合，再确定最后不想交的区间个数。其实大区间里一样可以有不相交的两个子区间
// 新的贪心策略: 每次找最小的right，这样给右边留的空最多

struct tv{
    int start;
    int end;
}arr[N];

bool cmp(tv a, tv b) {
    return a.start < b.start;
}

int main() {
    int n;
    int cnt = 0;
    int trash;

    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }
    scanf("%d", &trash);
    
    sort(arr, arr+n, cmp);

    int p=0, right=arr[p].end;

    // 边界不好处理

    while(p<n-1) {
        right = arr[p].end;
        // 极不情愿地扩张
        while(p < n-1 && right > arr[p+1].start) {
            if (right > arr[p+1].end) right = arr[p+1].end;
            p++;
        }
        cnt++;
        p++;
    }
    if (right < arr[n-1].start) cnt++;

    printf("%d", cnt);

    return 0;
}
