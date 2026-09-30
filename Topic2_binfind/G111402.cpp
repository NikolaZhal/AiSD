#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    int n;
    int k;

    cin >> n >> k;

    vector<int> ropes(n);
    int max_len = 0;
    for (int i = 0; i < n; i++) {
        cin >> ropes[i];
        if (ropes[i] > max_len) {
            max_len = ropes[i];
        }
    }

    int left = 1;
    int right = max_len;
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += ropes[i] / mid;
        }

        if (count >= k) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << answer << endl;

    return 0;
}