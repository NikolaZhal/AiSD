#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

bool good(int n, int a, int b, int t){
    t = t -a;
    if (t < 0){return false;}
    n--;
    return n <= (t / a + t/ b);
}

int main (){
    int n, x, y;
    cin >> n >> x >> y;
    int a = (x > y ? y : x);
    int b = (x < y ? y : x);
    int l = 0;
    int r = b * n;
    while (r - l > 1){
        int m = (r + l)/2;
        if (good(n, a, b, m)){
            r = m;
        } else {
            l = m;
        }
        
    }
    cout << r;
    return 0;
}