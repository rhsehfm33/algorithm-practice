#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    vector<array<int, 2>> xy(4);
    for (int i = 0; i < 4; ++i) {
        cin >> xy[i][0] >> xy[i][1];
    }
    sort(xy.begin(), xy.end());

    cout << (xy.back()[0] - xy.front()[0]) * (xy.back()[1] - xy.front()[1]) << '\n';
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