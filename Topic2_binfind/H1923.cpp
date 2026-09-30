#include <iostream>
using namespace std;

int main() {
    long long n, a, b, w, h;
    cin >> n >> a >> b >> w >> h;

    long long left = 0;
    long long right = 1000000000000000000LL;
    long long ans = 0;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        long long wa = a + 2 * mid;
        long long hb = b + 2 * mid;
        long long wb = b + 2 * mid;
        long long ha = a + 2 * mid;

        bool ok = false;

        if (wa <= w && hb <= h) {
            long long cols = w / wa;
            if (cols >= n) {
                ok = true;
            } else {
                long long rows = h / hb;
                if (rows >= (n + cols - 1) / cols) {
                    ok = true;
                }
            }
        }

        if (wb <= w && ha <= h) {
            long long cols = w / wb;
            if (cols >= n) {
                ok = true;
            } else {
                long long rows = h / ha;
                if (rows >= (n + cols - 1) / cols) {
                    ok = true;
                }
            }
        }

        if (ok) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}