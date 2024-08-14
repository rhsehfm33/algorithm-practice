#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll x, y, k, pd = -1;
    cin >> x >> y >> k;
    while (k) {
        ll m = min(k, y - x % y);
        if (x + m == pd) {
            x += k % m; 
            break;
        }
        k -= m;
        x += m;
        pd = x;
        while (x % y == 0) {
            x /= y;
        }
    }
    cout << x << '\n';
}

int main() {
    // ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}