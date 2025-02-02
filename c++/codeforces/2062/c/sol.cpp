#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll ans = 0;

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
        ans += ai;
    }

    while (a.size() > 1) {
        vector<ll> na;
        ll s1 = 0, s2 = 0;
        for (ll i = 0; i + 1 < a.size(); ++i) {
            na.push_back(a[i + 1] - a[i]);
            s1 += (a[i + 1] - a[i]);
            s2 += (a[i] - a[i + 1]);
        }
        ans = max({ans, s1, s2});
        a.swap(na);
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