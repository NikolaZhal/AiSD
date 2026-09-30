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
        bool found = false;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == target) {
                found = true;
                break;
            }
            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (found) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}