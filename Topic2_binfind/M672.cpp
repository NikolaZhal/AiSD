#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> wires(n);
    int max_len = 0;
    for (int i = 0; i < n; i++) {
        cin >> wires[i];
        if (wires[i] > max_len) {
            max_len = wires[i];
        }
    }

    int left = 0;           
    int right = max_len + 1;

    while (right - left > 1) {
        int mid = left + (right - left) / 2;

        int count = 0;
        for (int i = 0; i < n; i++) {
            count += wires[i] / mid;
            if (count >= k) {
                break;
            }
        }

        if (count >= k) {
            left = mid;   
        } else {
            right = mid;  
        }
    }

    cout << left << endl; 

    return 0;
}