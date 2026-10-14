#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lower_bound_search(vector<int>& arr, int x) {
    int l = -1, r = arr.size();
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (arr[m] < x) {
            l = m;
        } else {
            r = m;
        }
    }
    return r;
}

int upper_bound_search(vector<int>& arr, int x) {
    int l = -1, r = arr.size();
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (arr[m] <= x) {
            l = m;
        } else {
            r = m;
        }
    }
    return r;  
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end()); 
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        int left = lower_bound_search(arr, x);   
        int right = upper_bound_search(arr, x); 
        cout << right - left << (i + 1 < m ? " " : "\n");
    }
    return 0;
}