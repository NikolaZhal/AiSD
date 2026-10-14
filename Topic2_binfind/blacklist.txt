#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr1(n);
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    sort(arr1.begin(), arr1.end());

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        int count = upper_bound(arr1.begin(), arr1.end(), x) - lower_bound(arr1.begin(), arr1.end(), x);
        cout << count << " ";
    }
    cout << endl;

    return 0;
}