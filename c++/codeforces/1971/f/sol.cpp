#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

ll getAll(ll r) {
    ll result = 0;
    for (ll i = r; i >= -r; --i) {
        ll low = 1, high = r;
        while (low <= high) {
            ll mid = (low + high) / 2;
            if (mid * mid + abs(i * i) < (r + 1) * (r + 1)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        result += low - 1;
    }
    return max(0LL, result * 2 + r * 2);
}

void solve() {
    ll r;
    cin >> r;
    cout << getAll(r) - getAll(r - 1) << '\n';
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