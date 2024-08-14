#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n, l, r, ans = 0;
    cin >> n >> l >> r;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    for (ll li = 0, ri = 0, sum = 0; ri < n; ++ri) {
        sum += a[ri];
        while (li < ri and sum > r) {
            sum -= a[li++];
        }
        if (sum >= l) {
            if (sum <= r) {
                ++ans;
            }
            sum = 0;
            li = ri + 1;
        }
    }
    cout << ans << '\n';
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