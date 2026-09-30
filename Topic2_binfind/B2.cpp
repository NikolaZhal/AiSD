#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> queries(k);
    for (int i = 0; i < k; i++) {
        cin >> queries[i];
    }

    for (int q = 0; q < k; q++) {
        int target = queries[q];
        int left = 0;
        int right = n - 1;
        int best = arr[0];

        while (left <= right) {
            int mid = (left + right) / 2;
            int d1 = (int)arr[mid] - target;
            if (d1 < 0) d1 = -d1;
            int d2 = (int)best - target;
            if (d2 < 0) d2 = -d2;

            if (d1 < d2 || (d1 == d2 && arr[mid] < best)) {
                best = arr[mid];
            }

            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        cout << best << endl;
    }

    return 0;
}