#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(ll _ti) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    vector<ll> sorted_a(n);
    for (ll i = 0; i < n; ++i) {
        sorted_a[i] = i;
    }
    sort(sorted_a.begin(), sorted_a.end(), [&](ll l, ll r) {
        return a[l] < a[r];
    });

    vector<pair<ll, ll>> ans;
    for (ll i = 1, cur = a[sorted_a[0]]; i < n; ++i) {
        ll i2 = sorted_a[i];
        if (a[i2] == cur) {
            continue;
        }
        if (a[i2] > cur) {
            cur = (a[i2] % cur == 0 ? a[i2] : a[i2] - (a[i2] % cur) + cur);
        }
        ans.push_back({i2 + 1, cur - a[i2]});
    }

    cout << ans.size() << '\n';
    for (auto [i, x] : ans) {
        cout << i << ' ' << x << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    ll T;
    cin >> T;
    for (ll ti = 1; ti <= T; ++ti) {
        solve(ti);
    }

    return 0;
}