#include<cstdio>

using namespace std;

const int maxn = 105;

int arr[maxn] = {0};
char maps[10][6] = {{"zero"}, {"one"}, {"two"}, {"three"}, {"four"}, {"five"}, {"six"}, {"seven"}, {"eight"}, {"nine"}};

// �Ժ����ⲻҪ��string, �ö�άchar������
// ��ס�����char��ά���鸳ֵ����

int main(){
    int res = 0;
    char ch;
    while((ch=getchar()) != '\n') {
        res += (ch - '0');
    }

    int a, i=0;
    while (res != 0) {
        a = res % 10;
        res /= 10;
        arr[i++] = a;
    }

    i -= 1;
    while (i > 0){
        printf("%s ", maps[arr[i]]);
        i--;
    }
    printf("%s", maps[arr[0]]);

    return 0;
}
