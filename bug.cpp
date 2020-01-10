#include<cstdio>

typedef struct {
    int a[2];
    double d;
}T;

double fun(int i) {
    volatile T s;
    s.d = 3.14;
    s.a[i] = 1073741824;
    return s.d;
}

int main() {
    printf("%.14lf\n", fun(0));
    printf("%.14lf\n", fun(1));
    printf("%.14lf\n", fun(2));
    printf("%.14lf\n", fun(3));
    printf("%.14lf\n", fun(4));

    return 0;
}
