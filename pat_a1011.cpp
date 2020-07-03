#include<cstdio>
#include<algorithm>

using namespace std;

int main() {
    double game[9] = {0};
    double res[3] = {0};

    for (int i=0; i<3; ++i) {
        scanf("%lf %lf %lf", &game[i*3 + 0], &game[i*3 + 1], &game[i*3 + 2]);
    }

    for (int i=0; i<3; ++i) {
        if (game[i*3] > game[i*3+1]) {
            if (game[i*3] > game[i*3+2]) {
                res[i] = game[i*3];
                printf("W ");
            } else {
                res[i] = game[i*3 + 2];
                printf("L ");
            }
        } else {
            if (game[i*3+1] > game[i*3+2]) {
                res[i] = game[i*3+1];
                printf("T ");
            } else {
                res[i] = game[i*3+2];
                printf("L ");
            }
        }
    }

    double fres = 1;

    for (int i=0; i<3; ++i) {
        fres *= res[i];
    }
    fres = (fres * 0.65 - 1) * 2;

    printf("%.2lf", fres);
    
    return 0;
}
