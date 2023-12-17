#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int a, b, xk, yk, xq, yq;
    cin >> a >> b >> xk >> yk >> xq >> yq;

    set<array<int, 2>> s;
    vector<array<int, 2>> v = {{a, b}, {a, -b}, {-a, b}, {-a, -b}, {b, a}, {b, -a}, {-b, a}, {-b, -a}};
    for (auto [x1, y1] : v) {
        int nx = xk + x1;
        int ny = yk + y1;
        for (auto [x2, y2] : v) {
            if (nx == xq + x2 and ny == yq + y2) {
                s.insert({nx, ny});
            }
        }
    }

    cout << s.size() << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }

    return 0;
}