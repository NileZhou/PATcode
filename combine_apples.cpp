#include<cstdio>
#include<queue>

/**
* 经典的合并果子问题，可用优先队列进行实现(其实逻辑结构可以看作是哈夫曼树)
* 哈夫曼树是带权路径长度(WPL)最小的树
*/

using namespace std;

// 代表小顶堆的优先队列
priority_queue<long long, vector<long long>, greater<long long>> q;

int main(){
    int n;
    long long temp, x, y, ans=0;
    scanf("%d", &n);
    for (int i=0; i<n; ++i){
        scanf("%d", &temp);
        q.push(temp);
    }

    while (q.size() > 1){
        x = q.top();
        q.pop();
        y = q.top();
        q.pop();
        q.push(x + y);
        ans += x+y;
    }

    printf("%lld\n", ans);

    return 0;
}
