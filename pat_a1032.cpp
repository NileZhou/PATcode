#include<cstdio>
#include<map>
#include<algorithm>

using namespace std;

const int N = 1e5;

struct Node{
    int here; // 这个结点的地址
    char c;
    int to; // 链接到下一个结点的地址
};

Node arr[N];

map<int, int> mp; // 把抽象地址转换成地址

int get_len(int head){
    Node cur = arr[mp[head]]; // cur指向的是结点
    int cnt = 1;

    while (cur.to != -1) {
        cur = arr[mp[cur.to]];
        cnt += 1;
    }

    return cnt;
}

int jump(int head, int num) { // 跳Num步
    while (num--) {
        head = arr[mp[head]].to; // head 指向的是结点地址
        //printf("%d\n", head);
    }

    return head;
}

int main(){
    int h1, h2, num;
    
    scanf("%d %d %d", &h1, &h2, &num);
    
    for (int i=0; i<num; ++i) {
        scanf("%d %c %d", &arr[i].here, &arr[i].c, &arr[i].to);
        mp[arr[i].here] = i;
    }

    //for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
    //    printf("%d %d\n", it->first, it->second);
    //}

    int len1 = get_len(h1), len2 = get_len(h2);
    int p1 = h1, p2 = h2;

    if (len1 > len2) {
        p1 = jump(p1, len1 - len2);
    } else if (len1 < len2) {
        p2 = jump(p2, len2 - len1);
    }

    int from = -1, cnt = 0; // 记录重复开始的抽象地址与重复的结点总数
    int n = min(len1, len2);
    
    // printf("%d %d", p1, p2);

    for (int i=0; i<n; ++i) {
        if (arr[mp[p1]].c == arr[mp[p2]].c) {
            if (from == -1) {
                from = p1; // 在第一次修改的地方，标记为起点
            }
            cnt += 1;
        } else {
            from = -1;
            cnt = 0;
        }

        p1 = arr[mp[p1]].to;
        p2 = arr[mp[p2]].to;
        // printf("%d %d\n", p1, p2);
    }


    if (cnt > 0) {
        printf("%05d", from);
    } else {
        printf("-1");
    }

    return 0;
}
