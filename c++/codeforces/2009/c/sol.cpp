#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll x, y, k;
    cin >> x >> y >> k;
    ll cx = (x + k - 1) / k;
    ll cy = (y + k - 1) / k;
    cout << (cx > cy ? cx * 2 - 1 : cy * 2) << '\n';
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