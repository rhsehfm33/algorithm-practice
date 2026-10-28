#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    ll ans = 0;
    map<int, int> m;
    m[0] = 1;
    ll rs = accumulate(a.begin(), a.begin() + k, 0LL);
    for (ll i = k, ls = 0; i < n; ++i) {
        rs += a[i];
        ans += m[rs % k];
        ls += a[i - k];
        ++m[ls % k];
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