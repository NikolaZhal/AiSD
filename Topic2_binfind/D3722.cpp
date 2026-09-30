#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

int main() {
    double a, b, c, d;
    cin >> a >> b >> c >> d;

    double left = -100000.0;
    double right = 100000.0;

    for (int i = 0; i < 100; i++) {
        double mid = (left + right) / 2.0;
        double f_mid = a * mid * mid * mid + b * mid * mid + c * mid + d;
        
        if (a > 0) {
            if (f_mid < 0) {
                left = mid;
            } else {
                right = mid;
            }
        } else {
            if (f_mid > 0) {
                left = mid;
            } else {
                right = mid;
            }
        }
    }

    cout << fixed << setprecision(15) << (left + right) / 2.0 << endl;

    return 0;
}