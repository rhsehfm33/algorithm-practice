#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll l = 1, h = m;
    while (l <= h) {
        ll mid = (l + h) / 2;
        ll sum = n * (m / (mid + 1) * mid + m % (mid + 1));
        if (sum >= k) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << l << '\n';
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