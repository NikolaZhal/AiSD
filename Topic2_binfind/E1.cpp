#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

bool good(vector<int>& stalls,int k, int distance){
    int countCows = 1;
    int lcow = stalls[0];

    for(int i = 0; i < stalls.size(); i++){
        if (stalls[i] - lcow >=distance){
            countCows++;
            lcow = stalls[i];
            if (countCows == k){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n, k;
    cin >>n>>k;
    vector<int> stalls(n);
    for (int i =0; i <n; i++){
        cin >>stalls[i];
    }
    
    int l = 0;
    int r = stalls[n-1] - stalls[0]+1;
    while (r - l > 1){
        int m = (r+l) /2;
        if (good(stalls, k, m)){
            l = m;
        } else{
            r = m;
        }

    }
    cout << l;

    return 0;
}
