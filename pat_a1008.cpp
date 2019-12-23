#include<cstdio>

int main() {
    int N;
    int a = -1, b, t = 0;

    scanf("%d", &N);
    for (int i=0; i<N; ++i) {
        scanf("%d", &b);
        if (a != -1) {
            if (a < b) {
                t += (b-a) * 6 + 5;
            } else {
                t += (a-b) * 4 + 5;
            }
        } else {
            t += b * 6 + 5;
        }
        a = b;
    }

    printf("%d", t);

    return 0;
}
