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
        int left = -1;
        int right = n;


        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (arr[mid] <= target) {
                left = mid ;
            } else {
                right = mid;
            }
        }
        if (left == -1 || arr[left] != target){
            cout << "NO" << endl;
        } else {
            cout << "YES"<< endl;
        }

    }

    return 0;
}