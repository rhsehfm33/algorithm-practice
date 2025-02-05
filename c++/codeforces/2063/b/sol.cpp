#include <bits/stdc++.h>

using namespace std;

int _ti;

typedef long long ll;

ll sum(vector<ll> a, ll l, ll r, ll k) {
    sort(a.begin() + l, a.begin() + r);
    return accumulate(a.begin() + l, a.begin() + l + k, 0ll);
}

void solve() {
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    cout << min(sum(a, 0, r, r - l + 1), sum(a, l - 1, n, r - l + 1)) << '\n';
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