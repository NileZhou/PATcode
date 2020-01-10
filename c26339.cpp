#include<cstdio>
#include<cstring>

const int N = 100;

void reverse(char arr[N]) {
    int n = strlen(arr);
    int left = 0, right = n-1;

    while (left < right) {
        char tmp = arr[left];
        arr[left++] = arr[right];
        arr[right--] = tmp;
    }
}

int main(){
    char arr[N];

    while (~scanf("%s", arr)) {
        reverse(arr);
        printf("%s", arr);
    }

    return 0;
}
