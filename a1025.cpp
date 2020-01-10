#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 100;
const int K = 300;

struct Case{
    long num;
    short score;
    int final_rank;
    short loc_num;
    short loc_rank;
}arr[N*K];

/**
 * 题目原话:
 * The testees with the same score must have the same rank, and the output must be sorted
 * in nondecreasing order of their registration numbers
*/

bool cmp(Case a, Case b) {
    return a.score != b.score ? a.score > b.score : a.num < b.num;
    // if (a.score > b.score) return true;
    // else if (a.score == b.score){
    //    if (a.num < b.num) return true; // 非递减
    //    else return false;
    // }else{
    //    return false;
    // }
    // 错误处:
    // return a.score > b.score; // < 是升序排序, > 是降序排序
}

int p = 0;

int main() {
    int n, k;

    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        scanf("%d", &k);
        for (int j=0; j<k; ++j) {
            // hu: half unsigned int
            // hd: half int
            // ld: long int
            scanf("%ld %hd", &arr[i*p+j].num, &arr[i*p+j].score);
            arr[i*p+j].loc_num = i+1;
        }
        // 当前组排序,注意这里数组局部排序的函数调用方法
        sort(&arr[i*p], &arr[i*p+k], cmp);
        int pre = 1;
        arr[i*p].loc_rank = 1;
        for (int j=1; j<k; ++j) {
            if (arr[i*p+j].score < arr[i*p+j-1].score) {
                arr[i*p+j].loc_rank = j+1;
                pre = j+1;
            }else{
                arr[i*p+j].loc_rank = pre;
            }
        }
        
        p += k;
    }

    // 整体排序
    sort(arr, arr+p, cmp);

    int pre = 1;
    arr[0].final_rank = 1;
    for (int i=1; i<p; ++i) {
        if (arr[i].score < arr[i-1].score) {
            arr[i].final_rank = i+1;
            pre = i+1;
        }else{
            arr[i].final_rank = pre;
        }
    }

    printf("%d\n", p);
    for (int i=0; i<p; ++i) {
        printf("%ld %d %d %d\n", arr[i].num, arr[i].final_rank, arr[i].loc_num, arr[i].loc_rank);
    }

    return 0;
}

