#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll l = min(max(0LL, b - a), n);
    cout << (b + b - l + 1) * l / 2 + a * (n - l) << '\n';
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