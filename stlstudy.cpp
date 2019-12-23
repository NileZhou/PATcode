#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

vector<vector<int> > vvi;
vector<int> vi;

set<int> si;

map<int, int> mp;

//struct fruit{
//    string name;
//    int price;
//    friend bool operator < (fruit f1, fruit f2) {
//        return f1.price < f2.price; // 如果降序，将这里改为 > 即可
//    }
//};


bool cmp(int a, int b) {
    return a < b;
}

int main() {
    vvi.push_back(vi);
    vvi[0].push_back(1);
    vvi[0].push_back(2);
    vvi[0].push_back(2);
    vvi[0].pop_back(); // 删除尾部元素
    vvi[0].insert(vvi[0].begin() + 1, 3);
    // vvi[0].erase(vvi[0].begin() + 1); // 删除vvi[0][1]
    // vvi[0].erase(vvi[0].begin(), vvi[0].begin() + 2) // 删除[0,2)这个区间的元素
    for (int i=0; i<vvi[0].size(); ++i) {
        printf("%d ", vvi[0][i]);
    }
    printf("\n对容器排序:\n");
    sort(vvi[0].begin(), vvi[0].end(), cmp);
    for (int i=0; i<vvi[0].size(); ++i) {
        printf("%d ", vvi[0][i]);
    }
    vvi[0].clear();
    printf("\nsize of vector after clear: %d\n", vvi[0].size());

    si.insert(3); // set的作用是自动去重且按升序排序
    si.insert(5);
    si.insert(2);
    si.insert(3);
    for (set<int>::iterator it = si.begin(); it != si.end(); it++) {
        printf("%d ", *it);
    }
    // 查找某一元素是否在集合中
    // set<int>::iterator it = si.find(2);
    printf("\n2 is in si? : %d", *(si.find(3))); // 若是找不到会返回si.size()
    printf("\n if si count 30: %d", si.count(30));

    mp[10] = 20;
    mp[10] = 22; // 覆盖
    mp[20] = 30;
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
        printf("\n%d %d", it->first, it->second);
    }
    // 查找
    map<int, int>::iterator mpit = mp.find(70);
    printf("\n find from map:%d, %d", mpit->first, mpit->second); // 如果找不到，将返回mpit.size(), 0
    // 最直接
    printf("\n if map count 30: %d", mp.count(30)); // 取值要么为0, 要么为1

    priority_queue<int> q; // 等价于 priority_queue<int, vector<int>, less<int> > q;
    q.push(3);
    q.push(4);
    q.push(1);
    printf("\n the top of priority queue: %d", q.top());
    if (!q.empty()) q.pop();
    printf("\n the top of priority queue: %d", q.top());

    // 自定义sort
    int arr[5] = {3, 4, 1, 2, 0};
    sort(arr, arr+5, cmp);

    // lower_bound 与 upper_bound
    int arr2[10] = {1, 2, 2, 3, 3, 3, 3, 5, 6, 7};
    printf("\nthe first index of >= 3: %d\n", lower_bound(arr2, arr2+10, 3) - arr2);
    printf("\nthe first index of > 3:  %d\n", upper_bound(arr2, arr2+10, 3) - arr2);

    return 0;
}

