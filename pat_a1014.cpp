//#include<iostream>
//#include<queue>
//
//using namespace std;
//
//int main() {
//    // times[i]与time_start[i]是根据输入顺序来的
//    // line是实时处理
//    int n, m, k, t, q, times[1000], time_start[1000], i, j;
//    queue <int> line[20]; // line每个队列里面放的是各个顾客的结束时间
//
//    cin >> n >> m >> k >> q;
//    for(i = 0; i < min(k, n*m); ++i) { // 可以无脑按顺序放
//        cin >> t;
//        if (i / n == 0) { // 如果是第一轮放置
//            line[i % n].push(t);
//            time_start[i] = 0; // time_start里面进行放置各个顾客(进入的)开始时间
//        } else {
//            time_start[i] = line[i % n].back(); // 开始时间是可以确定的，因为不同队列时间是并行的
//            line[i % n].push(time_start[i] + t); // 按照处理queue时间依次累加
//        }
//        times[i] = line[i % n].back();
//    }
//  
//    if (k > n*m) { // 需要见缝插针的情况
//        for(; i < k; ++i) { // 最好这么用，因为用while可能会忘掉++i
//            cin >> t;
//            // 吃掉一块最小的队头, 选择最小的line去加入
//            // 因为每次填充一个，所以选择最短的line其实这句话是没有意义的，应该是选择队头最快消失的line
//            int min_wait = line[0].front(), min_i = 0;
//            for(j = 1; j<n; j++) {
//                if(line[j].front() < min_wait) {
//                   min_wait = line[j].front();
//                   min_i = j;
//                }
//            }
//            time_start[i] = line[min_i].back(); // 将当前块放到那个队的队尾, 只要进入yellow line即开始计时
//            times[i] = line[min_i].back() + t; // times[i]是第i个顾客的结束时间
//            line[min_i].pop();
//            line[min_i].push(times[i]);
//        }
//    }
//    
//    int h;
//    for(i = 0; i < q; i++) {
//        cin >> h;
//        // who cannot be served before 17:00  所以应该是开始时间 < 17:00
//        if(time_start[h - 1] < 540) {
//            printf("%02d:%02d\n", times[h-1] / 60 + 8, times[h-1] % 60);
//        } else {
//            printf("Sorry\n");
//        }
//    }
//    
//    return 0;
//}

// 自己的写法
#include<cstdio>
#include<queue>

using namespace std;

const int N = 20, K = 1000;

queue<int> line[N];
int etimes[K], stimes[K];

int main() {
    int n, m, k, q, t, i=0;

    scanf("%d %d %d %d", &n, &m, &k, &q);

    for (; i < min(k, n*m); ++i) {
        scanf("%d", &t);
        if (i / n == 0) {
            stimes[i] = 0;
            line[i].push(t);
        } else {
            stimes[i] = line[i % n].back();
            line[i % n].push(stimes[i] + t);
        }
        etimes[i] = line[i % n].back(); // 记录按输入顺序的每个cust的处理结束时间
    }

    if (k > n*m) {
        for (; i < k; ++i) {
            scanf("%d", &t); // 输入一个，消去一个，入队一个
            int min_t = line[0].front(), min_i = 0; // 以后不要起名为这样，因为min_t很有可能被看作min_i
            for (int j=1; j<n; ++j) {
                if (line[j].front() < min_t) {
                    min_t = line[j].front();
                    min_i = j;
                }
            }

            stimes[i] = line[min_i].back();
            etimes[i] = line[min_i].back() + t;
            line[min_i].pop();
            line[min_i].push(etimes[i]);
        }
    }

    int w;
    for (int j=0; j<q; ++j) {
        scanf("%d", &w);
        if (stimes[w - 1] < 540) {
            // 错因: 这里写错成了stimes
            printf("%02d:%02d\n", etimes[w - 1] / 60 + 8, etimes[w - 1] % 60);
        } else {
            printf("Sorry\n");
        }
    }

    return 0;
}
