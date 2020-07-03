#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>

using namespace std;

const int N = 2005;

struct Stu{
    int id;
    int a, c, m, e;
    int arg[4]; // 代表排序的序号 + 1
}stu[N];

bool cmpa(Stu a, Stu b) {
    return a.a > b.a;
}

bool cmpc(Stu a, Stu b) {
    return a.c > b.c;
}

bool cmpm(Stu a, Stu b) {
    return a.m > b.m;
}

bool cmpe(Stu a, Stu b) {
    return a.e > b.e;
}


int main() {
    int n, m;    
    
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; ++i) {
        scanf("%d %d %d %d", &stu[i].id, &stu[i].c, &stu[i].m, &stu[i].e);
        stu[i].a = round((stu[i].c + stu[i].m + stu[i].e) / 3);
    }

    sort(stu, stu+n, cmpa);
    for (int i=0; i<n; ++i) {
        stu[i].arg[0] = i+1;
    }
    sort(stu, stu+n, cmpc);
    for (int i=0; i<n; ++i) {
        stu[i].arg[1] = i+1;
    }
    sort(stu, stu+n, cmpm);
    for (int i=0; i<n; ++i) {
        stu[i].arg[2] = i+1;
    }
    sort(stu, stu+n, cmpe);
    for (int i=0; i<n; ++i) {
        stu[i].arg[3] = i+1;
    }

    map<int, int> id2num;
    for (int i=0; i<n; ++i) {
        id2num[stu[i].id] = i;
    }

    int id, num;
    map<int, int>::iterator it_find;
    char pr[5] = {'A', 'C', 'M', 'E'};
    for (int i=0; i<m; ++i) {
        scanf("%d", &id);
        // 怎么找到对应num对应的student呢，只能用map了
        it_find = id2num.find(id);
        if (it_find == id2num.end()) {
            printf("N/A");
            continue;
        } else {
            num = it_find->second;
        }

        int j=0, arg_max=0;
        for (j=1; j<4; ++j) {
            if (stu[num].arg[j] < stu[num].arg[arg_max]) {
                arg_max = j;
            }
        }
        printf("%d %c\n", stu[num].arg[arg_max], pr[arg_max]);
    }

    return 0;
}
