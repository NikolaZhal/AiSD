#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
bool good(vector<int>& ropes,int k, int length){
    if (length==0){return true;}
    int count = 0;
  
    for(int i = 0; i < ropes.size(); i++){
        count += ropes[i] / length;
        if (count >= k){
            return true;
        }
    }
    return false;
}
int main() {
    int n;
    int k;

    cin >> n >> k;

    vector<int> ropes(n);
    int r = 0;
    for (int i = 0; i < n; i++) {
        cin >> ropes[i];
        if (ropes[i] > r) {
            r = ropes[i];
        }
    }
    r++;
    int l=0;
    while (r - l > 1){
        int m = (r + l)/2;
        if (good(ropes, k, m)){
            l=m;
        } else{
            r =m;
        }

    }
    cout << l;


    return 0;
}