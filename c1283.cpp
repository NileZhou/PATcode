#include<cstdio>
#include<cstring>

const int N = 21;

void output(char* arr1, char* arr2, char* arr3) {
    char* a[3] = {arr1, arr2, arr3}; // 定义一个字符串指针数组
    char tmp[N];
    // 三变量的比较，还是冒泡算了
    for (int i=1; i<3; ++i) {
        for (int j=0; j<3-i; ++j) {
            if (strcmp(a[j], a[j+1]) > 0) {
                strcpy(tmp, a[j]);
                strcpy(a[j], a[j+1]);
                strcpy(a[j+1], tmp);
            }
        }
    }

    for (int i=0; i<3; ++i) {
        printf("%s\n", a[i]);
    }
}

int main() {
    char arr1[N], arr2[N], arr3[N];

    scanf("%s", arr1);
    scanf("%s", arr2);
    scanf("%s", arr3);

    output(arr1, arr2, arr3);

    return 0;
}
