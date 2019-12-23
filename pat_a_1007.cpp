#include<cstdio>

int main() {
    int K, num, first, last, isum=0, tfirst, tlast, tsum=0, mfirst;
    int nflag = 1;

    scanf("%d", &K);

    for (int i=0; i<K; ++i) {
        scanf("%d", &num);
        if (i == 0) mfirst = num;
        if (num >= 0) nflag = 0;
        if (tsum == 0) {
            tfirst = tlast = num;
        }
        tsum += num;
        tlast = num;
        if (tsum > isum) {
            first = tfirst;
            last = tlast;
            isum = tsum;
        } else if (tsum < 0) {
            tsum = 0;
        }
    }

    if (nflag == 1) printf("0 %d %d", mfirst, tlast);
    else if (isum == 0) printf("0 0 0");
    else printf("%d %d %d", isum, first, last);

    return 0;
}
