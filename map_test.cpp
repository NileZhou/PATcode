#include<cstdio>
#include<map>
#include<vector>

using namespace std;

int main() {
    map<int, int> mp;

    mp[1] = 2;
    mp[2] = 3;

    int num = mp[3];

    printf("%d", num);

    return 0;
}
