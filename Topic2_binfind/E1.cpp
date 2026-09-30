#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

bool canPlaceCows(vector<int>& stalls, int k, int distance) {
    int cowsPlaced = 1;
    int lastPosition = stalls[0];
    
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPosition >= distance) {
            cowsPlaced++;
            lastPosition = stalls[i];
            if (cowsPlaced >= k) {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> stalls(n);
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }
    
    int left = 0;
    int right = stalls[n - 1] - stalls[0];
    int answer = 0;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (canPlaceCows(stalls, k, mid)) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << answer << endl;
    
    return 0;
}