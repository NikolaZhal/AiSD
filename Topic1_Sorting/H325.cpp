#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int d1 = points[j].x * points[j].x + points[j].y * points[j].y;
            int d2 = points[j + 1].x * points[j + 1].x + points[j + 1].y * points[j + 1].y;
            if (d1 > d2) {
                Point temp = points[j];
                points[j] = points[j + 1];
                points[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << points[i].x << " " << points[i].y << endl;
    }

    return 0;
}