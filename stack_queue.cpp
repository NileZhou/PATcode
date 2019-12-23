#include<cstdio>

#define MAX_SIZE 50
#define ELEM_TYPE int

typedef struct SqStack{
    ELEM_TYPE data[MAX_SIZE];
    int top = 0;
};

bool Push(SqStack &S, ELEM_TYPE x) {
    if (S.top == MAX_SIZE) return false; // 判断栈满
    S.data[S.top++] = x;
    return true;
};

// 下面的这个引用一定得加，加了才是引用传递，否则是值传递，相当于开辟一块新的struct空间
// 这点与Java区别很大
bool Pop(SqStack &S, ELEM_TYPE &x) {
    if (S.top == 0) return false; // 判断栈空
    x = S.data[--S.top];
    return true;
}

void Output(SqStack S) {
    for (int i=0; i<S.top; ++i) {
        printf("%d ", S.data[i]);
    }
    printf("\n");
}

int main() {
    SqStack S;
    int x = 0;

    Push(S, 2);
    Push(S, 1);
    Push(S, 3);
    Output(S);
    Pop(S, x);
    Output(S);
    printf("%d", x);

    return 0;
}
