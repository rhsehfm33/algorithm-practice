#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n, x, mx = -2e18, sum = 0;
    cin >> n >> x;
    vector<array<ll, 3>> abc(n);
    for (auto& [a, b, c] : abc) {
        cin >> a >> b >> c;
        mx = max(mx, a * b - c);
        sum += a * (b - 1);
    }
    if (sum >= x) {
        cout << "0\n";
        return;
    }
    if (mx <= 0) {
        cout << "-1\n";
        return;
    }
    cout << (x - sum + mx - 1) / mx << '\n';
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