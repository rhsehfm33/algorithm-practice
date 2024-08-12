#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

ll getDis(ll x1, ll y1, ll x2, ll y2) {
    return abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2);
}

void solve() {
    ll n, xs, ys, xt, yt;
    cin >> n;
    vector<array<ll, 2>> xy(n);
    for (auto& [x, y] : xy) {
        cin >> x >> y;
    }
    cin >> xs >> ys >> xt >> yt;

    ll me = getDis(xs, ys, xt, yt);
    for (auto& [x, y] : xy) {
        if (me >= getDis(x, y, xt, yt)) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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