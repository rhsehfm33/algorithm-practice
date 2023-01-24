#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n;
    cin >> n;
    vector<ll> p(n);
    for (auto& pi : p) {
        cin >> pi;
    }

    map<ll, ll> m;
    for (ll i = 0; i < n; ++i) {
        m[p[i]] = i;
    }

    ll i0 = find(p.begin(), p.end(), 0) - p.begin();
    ll l1 = i0, r1 = i0;
    ll ans = 0;
    m.erase(0);
    while (m.size()) {
        auto [tn, ti] = *m.begin();
        ll l2 = l1;
        ll r2 = r1;

        if (ti < l1) {
            r2 = min(n - 1, r1 + (tn * 2 - (r1 - l1 + 1)));
            while (l2 > ti) {
                ans += max(0ll, min(r2 - r1, (tn * 2 - (r1 - l2 + 1))) + 1);
                m.erase(p[l2--]);
            }
            m.erase(m.begin());
            l1 = l2;
        }
        else {
            l2 = max(0ll, l1 - (tn * 2 - (r1 - l1 + 1)));
            while (r2 < ti) {
                ans += max(0ll, min(l1 - l2, (tn * 2 - (r2 - l1 + 1))) + 1);
                m.erase(p[r2++]);
            }
            m.erase(m.begin());
            r1 = r2;
        }
    }

    cout << ans + 1 << '\n';
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