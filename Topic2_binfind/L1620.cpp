#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, r, c;
    cin >> n >> r >> c;

    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    sort(h.begin(), h.end());

    int left = 0;
    int right = h[n - 1] - h[0];
    int ans = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int count = 0;
        int i = 0;
        while (i + c - 1 < n) {
            if (h[i + c - 1] - h[i] <= mid) {
                count++;
                i += c;
            } else {
                i++;
            }
        }

        if (count >= r) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}