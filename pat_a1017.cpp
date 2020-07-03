#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>


using namespace std;

const int N = 1e4;

struct node {
    int time;
    int ptime; // process time
}data[N];

int stime = 8 * 3600, etime = 17 * 3600;


int main() {
    int n, k;
    int h, m, sec;
    char s[10]; // 这里改为string的话，sscanf那里会报错

    cin >> n >> k;
    for (int i=0; i<n; ++i) {
        cin >> s >> data[i].ptime;
        sscanf(s, "%d:%d:%d", &h, &m, &sec);
        data[i].time = h * 24 * 3600 + m * 60 + sec;
    }

    for (int i=0; i<n; ++i) {
        printf("%d ", data[i].time);
    }

    return 0;
}
