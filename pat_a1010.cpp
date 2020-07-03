#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>


using namespace std;

const int N = 11;

long long get_actual_val(char s[], int slen, int radix) {
    long long val = 0L;
    long long radix_accum = 1L;
    for (int i=slen - 1; i>=0; --i) {
        if (s[i] >= '0' && s[i] <= '9') {
            val += (s[i] - '0') * radix_accum;
        } else { // 前提是radix得大于10进制
            val += ((s[i] - 'a') + 10) * radix_accum;
        }

        radix_accum *= radix;
    }

    return val;
}

int main() {
    char src[N] = {0}, dest[N] = {0}, tmp[N] = {0};
    int tag;
    int radix;

    scanf("%s %s %d %d", src, dest, &tag, &radix);
    if (tag == 2) {
        strcpy(tmp, src);
        strcpy(src, dest);
        strcpy(dest, tmp);
    }
    
    int slen = strlen(src), dlen = strlen(dest);
    long long res = 2;
    long long val = get_actual_val(src, slen, radix); // 得出数的真实值
    long long tmp_val = 0L;
    
    int max_base = 0;
    for (int i=0; i<dlen; ++i) {
        int num = 0;
        if (dest[i] >= '0' && dest[i] <= '9') {
            num = dest[i] - '0' + 1;
        } else {
            num = dest[i] - 'a' + 1;
        }

        if (num > max_base) max_base = num;
    }

    // 坑点: 试的时候应该要用二分法而不能顺序搜索
    long long left = max_base, right = val;

    while (left <= right) {
        long long mid = ((right - left) >> 1) + left;
        long long num = get_actual_val(dest, dlen, mid);
        if (num > val) {
            right = mid - 1;
        } else if (num < val) {
            left = mid + 1;
        } else {
            printf("%lld", mid);
            return 0;
        }
    }

    printf("Impossible");

    // 最大的缺陷: 有可能根本不止36进制
    // while (res <= 36) {
    //     tmp_val = get_actual_val(dest, dlen, res);
    //     // printf("now the value: %lld\n", tmp_val);
    //     if (tmp_val == val) {
    //         printf("%d", res);
    //         return 0;
    //     } else if (tmp_val > val) {
    //         printf("Impossible");
    //         return 0;
    //     }
    //     ++res;
    // }
    
    return 0;
}
