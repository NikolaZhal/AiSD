#include <iostream>
using namespace std;

bool good(long long s, long long w, long long h, long long n) {
    long long cols = s / w;  
    long long rows = s / h;  
    return cols * rows >= n;
}
int main() {
    long long n, w, h;
    cin >> w >> h>>n;
    long long l = 0;
    long long r = (w>h ? w:h) *n+1;
    while (r - l >1){
        long long m = (r+l)/2;
        if (good(m, w, h, n)){
            r =m;
        }else{
            l = m;
        }
    }
    cout << r;

   return 0;
}