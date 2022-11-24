#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n, c, d;
    cin >> n >> c >> d;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    sort(a.rbegin(), a.rend());

    if (a[0] * d < c) {
        cout << "Impossible\n";
        return;
    }

    vector<ll> presum(n + 1);
    for (int i = 1; i <= n; ++i) {
        presum[i] = presum[i - 1] + a[i - 1];
    }
    if (presum[min(n, d)] >= c) {
        cout << "Infinity\n";
        return;
    }

    ll ans = 0;
    for (ll i = 2; i <= d; ++i) {
        ll result = presum[min(i, n)] * (d / i) + presum[min(n, d % i)];
        if (result >= c) {
            ans = i - 1;
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