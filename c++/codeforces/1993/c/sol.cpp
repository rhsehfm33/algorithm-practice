#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n, k, mx = 0;
    cin >> n >> k;
    k *= 2;
    vector<ll> a(n), on(k), off(k);
    for (auto& ai : a) {
        cin >> ai;
        ++on[ai % k];
        mx = max(mx, ai);
    }

    for (ll i = mx - k, cnt = 0; i < mx + k; ++i) {
        ll l = (i + k) % k;
        ll r = (i + k + k / 2) % k;
        cnt += on[l] - off[l];
        off[r] = on[l];
        if (i >= mx and cnt == n) {
            cout << i << '\n';
            return;
        }
    }
    cout << "-1\n";
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