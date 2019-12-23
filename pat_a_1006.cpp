#include<cstdio>
#include<cstring> // ÄÚ²¿°üº¬strcpy

// if a is early than b
bool is_early(char a[9], char b[9]){
    int ah, bh, am, bm, as, bs;

    ah = (a[0] - '0') * 10 + (a[1] - '0');
    bh = (b[0] - '0') * 10 + (b[1] - '0');

    if (ah > bh) {
        return false;
    } else if (ah < bh) {
        return true;
    } else {
        am = (a[3] - '0') * 10 + (a[4] - '0');
        bm = (b[3] - '0') * 10 + (b[4] - '0');
        if (am > bm) {
            return false;
        } else if (am < bm) {
            return true;
        } else {
            as = (a[6] - '0') * 10 + (a[7] - '0');
            bs = (b[6] - '0') * 10 + (b[7] - '0');
            if (as > bs) {
                return false;
            } else if (as < bs) {
                return true;
            }
        }
    }
}

int main(){
    int M;
    char idnumber[16], intime[9], outime[9];
    char early[9], inman[16], last[9], outman[16];

    scanf("%d", &M);

    for (int i=0; i<M; ++i) {
        scanf("%s %s %s", idnumber, intime, outime);
        if (i == 0) {
            strcpy(early, intime);
            strcpy(last, outime);
            strcpy(inman, idnumber);
            strcpy(outman, idnumber);
        } else {
            if (is_early(intime, early)) {
                strcpy(early, intime);
                strcpy(inman, idnumber);
            }
            if (is_early(last, outime)) {
                strcpy(last, outime);
                strcpy(outman, idnumber);
            }
        }
    }

    printf("%s %s", inman, outman);

    return 0;
}
