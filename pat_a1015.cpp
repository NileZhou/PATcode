#include<cstdio>


int real_val(int num, int radix) {
    if (radix == 10) return num;

    int res = 0, accum = 1;
    
    while (num) {
        res += (num % radix) * accum;
        num /= radix;
        accum *= radix;
    }

    return res;
}

bool is_prime(int num) {
    for (int i=2; i*i<=num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int reverse(int num) {
    int nums[6] = {0};
    int i=0;
    while (num) {
        nums[5-i] = num % 10;
        num /= 10;
        ++i;
    }

    int res = 0, accu = 1;
    for (int j=6-i; j<6; ++j) {
        res += nums[j] * accu;
        accu *= 10;
    }

    return res;
}

int main() {
    int n, d, val;
    
    while (scanf("%d", &n) != EOF) {
        if (n < 0) break;
        scanf("%d", &d);
        val = real_val(n, d);
        printf("\nthe real val of val: %d", val);
        if (is_prime(val) && is_prime(reverse(val))) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    
    return 0;
}
