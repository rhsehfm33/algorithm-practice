#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll ans = 0;
    ll s1m = accumulate(a.begin(), a.begin() + m, 0ll);
    priority_queue<ll, vector<ll>, less<ll>> lpq;
    for (ll i = m - 1, s1i = s1m; i > 0; --i) {
        s1i -= a[i];
        lpq.push(a[i]);
        while (s1i < s1m) {
            s1m += -2 * lpq.top(); lpq.pop();
            ++ans;
        }
    }

    priority_queue<ll, vector<ll>, greater<ll>> gpq;
    for (ll i = m, s1i = s1m; i < n; ++i) {
        s1i += a[i];
        gpq.push(a[i]);
        while (s1i < s1m) {
            s1i += -2 * gpq.top(); gpq.pop();
            ++ans;
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