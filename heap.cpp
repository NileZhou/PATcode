#include<cstdio>

const int maxn=100;
int heap[maxn], n=10;

void add(int x){
    heap[n++] = x;
    int p = n-1, f = (p - 1) / 2;
    while (f >= 0 && heap[p] > heap[f]){
        int tmp = heap[f];
        heap[f] = heap[p];
        heap[p] = tmp;
        p = f;
        f = (p - 1) / 2;
    }
}

void heapify(int p){
    while (2*p+1 < n){
        int next = 2*p+1;
        if (2*p+2 < n){
            if (heap[2*p+1] < heap[2*p+2]){
                next++;
            }
        }
        if (heap[p] >= heap[next]) break;
        int tmp = heap[p];
        heap[p] = heap[next];
        heap[next] = tmp;
        p = next;
    }
}

int pop(){
    int res = heap[0];
    heap[0] = heap[--n];
    heapify(0);

    return res;
}

void heap_sort(int len){
    if (len < 2) return;
    int p = len / 2;
    while (p >= 0){
        heapify(p);
        p--;
    }
    for (int i=len-1; i>=0; --i){
        heap[i] = pop();
    }

    for (int i=0; i<len; ++i){
        printf("%d ", heap[i]);
    }
}

int main(){
    heap[0] = 3;
    heap[1] = 6;
    heap[2] = 1;
    heap[3] = 6;
    heap[4] = 8;
    heap[5] = 3;
    heap[6] = 7;
    n = 7;
    heap_sort(n);

    return 0;
}
