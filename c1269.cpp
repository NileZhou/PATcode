#include<cstdio>

void output(int *a, int *b) {
    if (*a < *b) {
        printf("%d %d\n", *a, *b);
    } else {
        printf("%d %d\n", *b, *a);
    }
}

int main() {
    
    int a, b;

    scanf("%d %d", &a, &b);

    output(&a, &b);

    return 0;
}
