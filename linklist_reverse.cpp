#include <cstdio>

#define ElemType int

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}*LinkList;

LinkList Reverse(LinkList L) {
    if (L == NULL || L->next == NULL) return L;
    LNode *pre = L->next;
    LNode *p = pre->next;
    while (p != NULL) {
        pre->next = p->next;
        p->next = L->next;
        L->next = p;
        p = pre->next;
    }

    return L;
}

LinkList InitLinkList(LinkList &L) {
    L = new LNode[1];
    L->next = NULL;

    int x;

    scanf("%d", &x);
    while (x != 9999) {
        LNode *node = new LNode[1];
        node->data = x;
        node->next = L->next;
        L->next = node;
        scanf("%d", &x);
    }

    return L;
}

void OutputLinkList(LinkList L){
    if (L == NULL || L->next == NULL) return;
    L = L->next;
    while (L != NULL) {
        printf("%d ", L->data);
        L = L->next;
    }
    printf("\n");
}

int main() {
    LinkList L;

    InitLinkList(L);
    OutputLinkList(L);
    Reverse(L);
    OutputLinkList(L);

    return 0;
}
