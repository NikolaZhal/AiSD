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
        int r = n;
        int l = -1;
        int m;

        while (r - l > 1){
            m = (r+l)/2;
            if (arr[m] <= target){
                l = m;
            } else{
                r = m;
            }
        }
        if (l == -1){l = 0;}
        if (r == n){r = n-1;}
        if ( arr[r]- target < target-arr[l]){
            cout << arr[r]<< endl;
        } else{
        cout << arr[l] << endl;
        }

    }

    return 0;
}