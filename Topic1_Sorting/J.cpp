#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    vector<string> parts;
    string s;
    while (cin >> s) {
        parts.push_back(s);
    }

    int lenum = parts.size();
    bool swaped = true;
    int i = 0;
    while (swaped && i < lenum) {
        swaped = false;
        for (int j = 0; j < lenum - i - 1; j++) {
            if (parts[j] + parts[j + 1] < parts[j + 1] + parts[j]) {
                string temp = parts[j];
                parts[j] = parts[j + 1];
                parts[j + 1] = temp;
                swaped = true;
            }
        }
        i++;
    }

    for (int i = 0; i < lenum; i++) {
        cout << parts[i];
    }
    cout << endl;

    return 0;
}