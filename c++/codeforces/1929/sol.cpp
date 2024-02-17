#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll find_min(ll u, ll k) {
    ll low = 1, high = u;
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (mid * k > u + mid) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return high + 1;
}

void solve(int _ti) {
    ll k, x, a;
    cin >> k >> x >> a;

    for (ll i = 2, u = 1; i <= x + 1; ++i) {
        ll b = find_min(u, k);
        if (u + b > a) {
            cout << "NO\n";
            return;
        }
        u += b;
    }
    cout << "YES\n";
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