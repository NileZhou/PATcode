#include<cstdio>
#include<cmath>

const double eps = 1e-8;
#define Equ(a, b) ((fabs((a) - (b))) < (eps))

bool sqrt_integer(double num){
    double tmp = sqrt(num);
    return Equ(tmp * tmp, num);
}



int main(){
    long long n, cnt, val;

    while (~scanf("%lld", &n)){
        cnt = 0;
        val = n;
        while (sqrt_integer(val)){
            val = sqrt(val);
            cnt++;
        }

    }

    return 0;
}
