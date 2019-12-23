#include<cstdio>

const int maxn=1000;

int arr[maxn];

int main(){
    int n, cnt;

    //freopen("inputs.txt", "r", stdin);

    while (~scanf("%d", &n)){
        for (int i=0; i<n; ++i){
            scanf("%d", &arr[i]);
        }
        int cnt=1, i_cnt=0, max_cnt = 0, i_max = -1;
        for (int i=1; i<n; ++i){
            if (arr[i] == arr[i-1] + 1){
                cnt++;
                if (cnt > max_cnt){
                    max_cnt = cnt;
                    i_max = i_cnt;
                }
            }else{
                cnt = 1;
                i_cnt = i;
            }
        }
        if (arr[i_max] == 1){
            max_cnt += 1;
        }
        if (arr[i_max+max_cnt-1] == 1000){
            max_cnt += 1;
        }
        max_cnt -= 2;
        if (max_cnt < 0) max_cnt = 0;
        printf("%d\n", max_cnt);
    }

    return 0;
}
