#include<cstdio>

void fun(int x[5]){
    int a[5][6] = {0};
    printf("%d\n", sizeof(x)); // 32: 4 64: 8
    printf("%d\n", sizeof(x[0])); // 4
    printf("%d\n", sizeof(a));// 120
    printf("%d\n", sizeof(a+0));// 32: 4 64: 8
    printf("%d\n", sizeof(&a));// 32: 4 64: 8
}

int main(){
    int x[5] = {0};
    fun(x);

    return 0;
}
