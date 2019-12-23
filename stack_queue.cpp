#include<cstdio>

#define MAX_SIZE 50
#define ELEM_TYPE int

typedef struct SqStack{
    ELEM_TYPE data[MAX_SIZE];
    int top = 0;
};

bool Push(SqStack &S, ELEM_TYPE x) {
    if (S.top == MAX_SIZE) return false; // �ж�ջ��
    S.data[S.top++] = x;
    return true;
};

// ������������һ���üӣ����˲������ô��ݣ�������ֵ���ݣ��൱�ڿ���һ���µ�struct�ռ�
// �����Java����ܴ�
bool Pop(SqStack &S, ELEM_TYPE &x) {
    if (S.top == 0) return false; // �ж�ջ��
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
