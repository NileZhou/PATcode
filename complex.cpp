#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<complex>

typedef long long ll;

using namespace std;

const double eps = 1e-5;
const int N = 12;
const double PI = acos(-1.0);

int main() {
    complex <double> invs[N];
    complex <double> omgs[N];
    for (int i=0; i<N; ++i) {
        omgs[i] = complex <double> (cos(2*PI*i/N), sin(2*PI*i/N));
        invs[i] = conj(omgs[i]);
        cout << omgs[i] << " " << invs[i] << endl;
    }
    
    return 0;
}
