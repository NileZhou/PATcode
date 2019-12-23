#include<cstdio>

int main(){
    int K, ifrist, ilast, isum=0, tfirst, tlast, tsum=0, nflag=1; // nflag为1代表所有的数都是负数

    scanf("%d", &K);
    for (int i=0; i<K; ++i) {
        scanf("%d", &num);
        if (num > 0) {
            nflag = 0;
        }
        if (i == 0) {
            ifirst = ilast = tfirst = tlast = num;
            isum = tsum = num;
        } else {
            if (isum < 0) {

            }
            if (isum <= 0) {
                if (num > isum) {
                    first = last = num;
                    tsum = isum = num;
                }
            } else {

                if (num >= 0) {
                    last = num;
                    tsum += num;
                } else {
                    if (num + isum >= 0) {
                        tsum += num;
                    }
                }
            }
        }
    }

    printf("%d %d %d", isum, first, last);

    return 0;
}
