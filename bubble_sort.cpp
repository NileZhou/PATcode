#include<cstdio>

const int N = 10;

int main() {
    int arr[N] = {3, 1, 2, 4, 0, -1, 7, 2, 6, 9};

    // bubble sort
    for (int i=1; i<N; ++i) { // 只需进行N-1轮，将最大的往右边移
        for (int j=0; j<N-i; ++j) {
            if (arr[j] > arr[j+1]) { // 只有左边比右边大时才交换，所以为稳定排序
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }

    // output
    for (int i=0; i<N; ++i) {
        printf("%d ", arr[i]);
    }

    return 0;
}
