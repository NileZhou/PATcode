// head of a gang
#include<map>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

const int maxn = 2000; // 有可能这1000个电话都是不同的人

map<string, int> s2i; // name -> id
map<int, string> i2s; // id -> name
map<string, int> res; // name -> cnt map中元素自动按键从小到大排序

int G[maxn][maxn] = {0}; // 初始化图
int n_person = 0;
bool via[maxn] = {false};
int i2w[maxn] = {0}; // id -> id's weight

int node_id(string name){
    if (s2i.find(name) == s2i.end()){ // 代表没找到
        s2i[name] = n_person;
        i2s[n_person] = name;
        n_person += 1;
        return n_person - 1;
    }else{
        return s2i[name];
    }
}

/**
 *
 * @param cur 当前结点
 * @param n 当前团体的总人数
 * @param gang gang的id
 * @param total 总权重
 */
void dfs(int cur, int& n, int& gang, int& total){
    n++;
    via[cur] = true;
    if (i2w[cur] > i2w[gang]){
        gang = cur;
    }

    for (int i=0; i<n_person; ++i){
        if (G[cur][i] > 0){
            total += G[cur][i];
            G[cur][i] = G[i][cur] = 0; // 以免回走
            if (!via[i]){ // 这一步是精华
                dfs(i, n, gang, total);
            }
        }
    }
}

/**
 * bfs相当难写, 这道题还是dfs好写
 * @param k 阈值
 */
void dfs_travel(int k){
    for (int i=0; i<n_person; ++i){
        if (!via[i]){
            int gang = i, total = 0, n = 0;
            dfs(i, n, gang, total);
            if (total > k && n > 2){
                res[i2s[gang]] = n;
            }
        }
    }
}

int main(){
    int n, k, w; // num of phone calls and weight threshold
    string s1, s2;
    int id1, id2;

    ios::sync_with_stdio(false); // 与stdin等同步会造成iostream不必要的开销

    cin >> n >> k;
    for (int i=0; i<n; ++i){
        cin >> s1 >> s2 >> w;
        id1 = node_id(s1);
        id2 = node_id(s2);
        G[id1][id2] += w;
        G[id2][id1] += w;
        i2w[id1] += w;
        i2w[id2] += w;
    }

    dfs_travel(k);

    cout << res.size() << endl;

    // 小trick:
    map<string, int>::iterator it;
    for (it = res.begin(); it != res.end(); ++it){
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}
