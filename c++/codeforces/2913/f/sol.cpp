#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n;
    cin >> n;
    vector<array<ll, 2>> xy(n + 2);
    cin >> xy[0][0] >> xy[0][1] >> xy[n + 1][0] >> xy[n + 1][1];
    for (ll i = 0; i < 2; ++i) {
        for (ll j = 1; j <= n; ++j) {
            cin >> xy[j][i];
        }
    }
    sort(xy.begin(), xy.end());

    vector<array<ll, 2>> sy;
    for (ll i = 0, j = 0; i < n + 2;) {
        while (j < n + 2 and xy[i][0] == xy[j][0]) {
            ++j;
        }
        sy.push_back({xy[i][1], xy[j -  1][1]});
        i = j;
    }

    ll y1 = 1e18, y2 = 1e18, cy1 = 0, cy2 = 0;
    for (ll i = 1; i < sy.size(); ++i) {
        ll len = abs(sy[i][0] - sy[i][1]);
        y1 = min(y1, cy1 + abs(sy[i][1] - sy[i - 1][0]) + len);
        y2 = min(y2, cy1 + abs(sy[i][0] - sy[i - 1][0]) + len);
        y1 = min(y1, cy2 + abs(sy[i][1] - sy[i - 1][1]) + len);
        y2 = min(y2, cy2 + abs(sy[i][0] - sy[i - 1][1]) + len);
        cy1 = y1;
        cy2 = y2;
        y1 = y2 = 1e18;
    }
    cout << xy[n + 1][0] - xy[0][0] + min(cy1, cy2) << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}