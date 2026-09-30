#include <iostream>
#include <vector>
using namespace std;

void build(int l, int r, int& val, vector<int>& a) {
    if (l > r) return;
    int mid = (l + r) / 2;
    a[mid] = val--;
    build(mid + 1, r, val, a);
    build(l, mid - 1, val, a);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int val = n;
    build(1, n, val, a);
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}