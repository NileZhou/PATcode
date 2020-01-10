#include<cstdio>
#include<cstring>

const int N = 1e5;
const int M = 1e9 + 7;

char arr[N] = {'\0'};

long res = 0;

int main() {
    scanf("%s", arr);
    int n_P = 0, n_T = 0;
    int n = strlen(arr);

    for (int i=0; i<n; ++i) {
        if (arr[i] == 'T') n_T++;
    }

    for (int i=0; i<n-1; ++i) {
        if (arr[i] == 'P') n_P++;
        else if (arr[i] == 'T') n_T--;
        else if (arr[i] == 'A') res = (res + n_P*n_T) % M;
    }

    printf("%ld\n", res);

    return 0;
}
