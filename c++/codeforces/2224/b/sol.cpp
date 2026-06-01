#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    ll ans = 0;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    a.insert(a.begin(), a.back());
    while (a.size() < n) {
        a.push_back(a.back());
    }

    set<ll> s;
    for (ll i = 0, mex = 0, mx = 0; i < n; ++i) {
        s.insert(a[i]);
        while (s.count(mex)) {
            ++mex;
        }
        mx = max(mx, a[i]);
        ans += mex + mx;
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