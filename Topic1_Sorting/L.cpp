#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    vector<int> distances;
    string line;
    getline(cin, line);
    stringstream ss1(line);
    int num;
    while (ss1 >> num) {
        distances.push_back(num);
    }

    vector<int> rates;
    getline(cin, line);
    stringstream ss2(line);
    while (ss2 >> num) {
        rates.push_back(num);
    }

    int lenum = distances.size();

    sort(distances.begin(), distances.end());
    sort(rates.begin(), rates.end());

    long long total = 0;
    for (int i = 0; i < lenum; i++) {
        total += (long long)distances[i] * rates[lenum - 1 - i];
    }

    cout << total << endl;

    return 0;
}