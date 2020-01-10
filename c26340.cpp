#include<cstdio>
#include<cstring>

const int N = 100;

void vowels(char s1[], char s2[]) { // 将s1的元音字母保存到s2
    int n = strlen(s1);
    int p = 0;

    for (int i=0; i<n; ++i) {
        if (s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u') {
            s2[p++] = s1[i];
        }
    }
}

int main() {
    char s1[N];
    char s2[N];

    while (~scanf("%s", s1)) {
        memset(s2, 0, sizeof(char) * N);
        vowels(s1, s2);
        printf("%s\n", s2);
    }
    
    return 0;
}
