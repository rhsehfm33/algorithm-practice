#include <bits/stdc++.h>

using namespace std;

int _ti;

void get(int x, int y, int& d) {
    cout << "? " << x << ' ' << y << endl;
    cin >> d;
}

array<int, 2> get_xy(int l, int r) {
    return {(r - l) / 2 + 1, l + (r - l) / 2};
}

void solve() {
    int n, m;
    cin >> n >> m;

    array<int, 2> xy;
    vector<int> xs(4, -1);
    get(1, 1, xs[0]);
    ++xs[0];
    get(1, m, xs[1]);
    xs[1] = m - xs[1];
    if (xs[1] <= xs[0] and (xs[0] - xs[1]) % 2 == 0) {
        xy = get_xy(xs[1], xs[0]);
        get(xy[0], xy[1], xs[2]);
    }

    if (xs[2] != 0) {
        get(n, 1, xs[3]);
        xs[3] = 2 - n + xs[3];
        xy = get_xy(xs[3], xs[0]);
    }
    
    cout << "! " << xy[0] << ' ' << xy[1] << endl;
}

int main() {
    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}