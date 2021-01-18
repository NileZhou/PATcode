#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 1000;

void josephus(int n, int m) { // a circle which has n persons, count to m then quit
    // O(n * m)
    int a[maxn];
    for (int i=0; i<n; ++i) {
        a[i] = i+1;
    }
    
    int p = 0, num = 1;
    for (int i=0; i<n; ++i) {
        for (int j=(p+1)%n; j<m) {
            
        }
    }
    
    int cnt = 0;
    while (cnt < n) {
        
    }

}

int main() {
    
    return 0;
}
