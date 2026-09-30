#include <iostream>
using namespace std;

bool check(long long mid, long long A, long long K, long long B, long long M, long long X) {
    long long days_dmitry = mid - mid / K;
    long long days_fedor = mid - mid / M;
    
    if (days_dmitry >= (X + A - 1) / A) return true;
    long long dmitry_trees = A * days_dmitry;
    long long remaining = X - dmitry_trees;
    
    if (days_fedor >= (remaining + B - 1) / B) return true;
    
    return false;
}

int main() {
    long long A, K, B, M, X;
    cin >> A >> K >> B >> M >> X;
    
    long long left = 0, right = 2000000000000000000LL;
    long long ans = right;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        
        if (check(mid, A, K, B, M, X)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << ans << endl;
    return 0;
}