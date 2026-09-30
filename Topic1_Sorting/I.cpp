#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int lenum1 = s1.length();
    int lenum2 = s2.length();

    if (lenum1 != lenum2) {
        cout << "NO" << endl;
        return 0;
    }

    int count1[256] = {0};
    int count2[256] = {0};

    for (int i = 0; i < lenum1; i++) {
        count1[(int)s1[i]]++;
    }
    for (int i = 0; i < lenum2; i++) {
        count2[(int)s2[i]]++;
    }

    bool same = true;
    for (int i = 0; i < 256; i++) {
        if (count1[i] != count2[i]) {
            same = false;
        }
    }

    if (same) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}