#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iterator>
#include <cmath>
#include <cstdio>

using namespace std;

struct Point {
    double x, y, z, r;
};
struct Bridge {
    int f, t;
    double d;

    bool operator<(const Bridge b) const {
        return d < b.d;
    }
};

class DisJointSet {
public:
    DisJointSet(int n);
    virtual ~DisJointSet();

    void join(int x, int y);
    bool testJoin(int x, int y);

private:
    int _getFather(int pos);
    std::vector<int> fathers;
};

DisJointSet::DisJointSet(int n) {
    fathers.resize(n);
    for (int i = 0; i < n; i++) {
        fathers[i] = i;
    }
}
DisJointSet::~DisJointSet() {
}

void DisJointSet::join(int x, int y) {
    fathers[_getFather(x)] = _getFather(y);
}

bool DisJointSet::testJoin(int x, int y) {
    return _getFather(x) == _getFather(y);
}

int DisJointSet::_getFather(int pos) {
    if (fathers[pos] == pos) {
        return pos;
    }
    fathers[pos] = _getFather(fathers[pos]);
    return fathers[pos];
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n <= 0) break;

        vector<Point> points;
        vector<Bridge> bridges;
        DisJointSet joinSet(n);
        points.resize(n);
        bridges.resize(0);
        for (int i = 0; i < n; ++i) {
            cin >> points[i].x >> points[i].y >> points[i].z >> points[i].r;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                Bridge bridge;
                bridge.f = i;
                bridge.t = j;
                bridge.d = sqrt(
                    (points[i].x - points[j].x) * (points[i].x - points[j].x) +
                    (points[i].y - points[j].y) * (points[i].y - points[j].y) +
                    (points[i].z - points[j].z) * (points[i].z - points[j].z)
                ) - points[i].r - points[j].r;
                bridges.push_back(bridge);
            }
        }
        sort(bridges.begin(), bridges.end());
        double sum = 0.0;
        for (vector<Bridge>::iterator it = bridges.begin(); it != bridges.end(); ++it) {
            if (!joinSet.testJoin(it->f, it->t)) {
                joinSet.join(it->f, it->t);
                if (it->d > 0.0) {
                    sum += it->d;
                }
            }
        }
        printf("%.3f\n", sum);
    }
    
    return 0;
}