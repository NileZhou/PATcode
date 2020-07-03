#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

struct Node {
    string name;
    int status, month, time, day, hour, minute;
};

# map-link结构可以做 map<string, <vector> >
# 两重sort是关键

int main() {
    int fees[24];

    for (int i=0; i<24; ++i) {
        scanf("%d", &fees[i]);
    }

    
    return 0;
}
