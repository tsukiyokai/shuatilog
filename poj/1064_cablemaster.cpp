#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<double> vd;

int Check(vd &L, double x) {
    int cnt = 0;
    for (size_t i = 0; i < L.size(); i++)
        cnt += floor(L[i] / x);
    return cnt;
}

int main() {
    int N, K;
    cin >> N >> K;
    vd L(N);
    for (size_t i = 0; i < N; i++)
        cin >> L[i];
    double l = 0, r = 100000;
    for (int i = 0; i < 100; i++) {
        double mid = (l + r) / 2;
        if (Check(L, mid) >= K) l = mid;
        else r = mid;
    }
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << floor(l * 100) / 100;
}

/*
## Sample Input

4 11
8.02
7.43
4.57
5.39

## Sample Output

2.00
*/