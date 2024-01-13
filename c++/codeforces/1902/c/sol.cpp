#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    set<ll> s;

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
        s.insert(ai);
    }

    if (n == 1) {
        cout << 1 << '\n';
        return;
    }

    ll g = 0;
    for (ll i = 0; i + 1 < a.size(); ++i) {
        g = gcd(g, abs(a[i + 1] - a[i]));
    }

    ll ans = 0, mx = *max_element(a.begin(), a.end());
    for (ll i = n - 1; i >= 0; --i) {
        ans += abs(mx - a[i]) / g;
    }

    for (ll i = mx; ;i -= g) {
        if (!s.count(i)) {
            ans += abs(mx - i) / g;
            break;
        }
    }

    cout << ans << '\n';
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