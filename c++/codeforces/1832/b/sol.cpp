#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    vector<ll> presum(n + 1);
    for (int i = 1; i <= n; ++i) {
        presum[i] += a[i] + presum[i - 1];
    }

    ll ans = presum[n] - presum[k * 2];
    for (int l = 0, r = k; r >= 0; l += 2, --r) {
        ans = max(ans, presum[n - r] - presum[l]);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int _ti = 1; _ti <= T; ++_ti) {
        solve(_ti);
    }
}