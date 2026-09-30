#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int count_balloons(int T, int ti, int zi, int yi) {
    int time_cycle = zi * ti + yi;
    int full_cycles = T / time_cycle;
    int rem = T % time_cycle;
    int b = rem / ti;
    return full_cycles * zi + (b < zi ? b : zi);
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> t(n), z(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> z[i] >> y[i];
    }

    int left = 0;
    int right = 3000000;
    int ans_time = right;

    while (left <= right) {
        int mid = (left + right) / 2;
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += count_balloons(mid, t[i], z[i], y[i]);
            if (total >= m) break;
        }

        if (total >= m) {
            ans_time = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans_time << endl;

    int remaining = m;
    for (int i = 0; i < n; i++) {
        int max_b = count_balloons(ans_time, t[i], z[i], y[i]);
        int take = max_b < remaining ? max_b : remaining;
        cout << take << " ";
        remaining -= take;
    }
    cout << endl;

    return 0;
}