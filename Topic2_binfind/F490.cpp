#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    if (n == 1) {
        cout << (x < y ? x : y) << endl;
        return 0;
    }

    int first_copy_time = (x < y ? x : y);
    int n_remaining = n - 1;

    int left = 0;
    int right = n_remaining * first_copy_time;
    int ans = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int copies = mid / x + mid / y;

        if (copies >= n_remaining) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << first_copy_time + ans << endl;

    return 0;
}