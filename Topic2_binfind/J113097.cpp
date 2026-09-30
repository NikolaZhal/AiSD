#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    long long n, a, b, w, h;
    cin >> n >> a >> b >> w >> h;

    long long left = 0;
    long long right = 1000000000000000000LL;
    long long ans = 0;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        
        long long W1 = a + 2 * mid;
        long long H1 = b + 2 * mid;
        long long W2 = b + 2 * mid;
        long long H2 = a + 2 * mid;

        bool ok1 = false;
        if (W1 <= w && H1 <= h) {
            long long C = w / W1;
            long long R = h / H1;
            if (C >= n || R >= n) ok1 = true;
            else if (C >= (n + R - 1) / R) ok1 = true;
        }

        bool ok2 = false;
        if (W2 <= w && H2 <= h) {
            long long C = w / W2;
            long long R = h / H2;
            if (C >= n || R >= n) ok2 = true;
            else if (C >= (n + R - 1) / R) ok2 = true;
        }

        if (ok1 || ok2) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}s