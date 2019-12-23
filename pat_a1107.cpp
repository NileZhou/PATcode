#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

const int maxn = 1010;

int hobbies[maxn] = {0}; // ������
int human[maxn] = {0}; // ֻ�о���

int find_father(int a){ // find father
    int root = a;
    while (root != human[root]){
        root = human[root];
    }

    while (human[a] != a){
        int tmp = a;
        a = human[a];
        human[tmp] = root;
    }
    return root;
}

void union_set(int a, int b){ // �ϲ�������human������
    if (human[a] == 0) human[a] = a;
    if (human[b] == 0) human[b] = b;
    int fa = find_father(a), fb = find_father(b);
    if (fa != fb) human[fa] = fb;
}

bool cmp(int a, int b){
    return a > b;
}

int main(){
    int N, cnt, num;

    freopen("inputs.txt", "r", stdin);

    scanf("%d", &N);
    for (int i=1; i<=N; ++i){ // �˵ı�Ŵ�1��ʼ���ܿ�0
        scanf("%d: ", &cnt);
        if (human[i] == 0) human[i] = i;
        for (int j=0; j<cnt; ++j){
            scanf("%d", &num);
            if (hobbies[num] == 0){
                hobbies[num] = i;
            }
            union_set(i, find_father(hobbies[num]));
        }
    }

    // ���������߼����ҵ��¿���2��
    map<int, int> mp; // ����
    for (int i=1; i<=N; ++i){
        if (human[i] != 0){ // �����Ϊ0, ���м����ı�Ҫ
            int tmp = find_father(human[i]);
            if (mp[tmp] == 0){
                mp[tmp] = 1;
            }else{
                mp[tmp] = mp[tmp] + 1;
            }
        }
    }

    vector<int> vec;
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it){
        vec.push_back(it->second);
    }

    sort(vec.begin(), vec.end(), cmp);

    printf("%d\n", vec.size());
    for (int i=0; i<vec.size(); ++i){
        if (i != vec.size()-1){
            printf("%d ", vec[i]);
        }else{
            printf("%d", vec[i]);
        }
    }

    return 0;
}
