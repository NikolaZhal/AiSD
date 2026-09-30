#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double c;
    cin >> c;

    double left = 0.0;
    double right = 100000.0;

    for (int i = 0; i < 100; i++) {
        double mid = (left + right) / 2.0;
        if (mid * mid + sqrt(mid) < c) {
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << fixed << setprecision(9) << (left + right) / 2.0 << endl;

    return 0;
}