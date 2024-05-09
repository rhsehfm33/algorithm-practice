#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<array<ll, 2>> ab(n);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> ab[j][i];
        }
    }
    sort(ab.begin(), ab.end(), [](auto& l, auto& r) {
        return l[1] < r[1];
    });

    vector<ll> dp(n + 1);
    priority_queue<ll> rq;
    for (ll i = n - 1, rs = 0; i >= 0; --i) {
        rq.push(ab[i][0]);
        rs -= ab[i][0];
        if (rq.size() > k) {
            rs += rq.top();
            rq.pop();
        }
        dp[i] = rs;
    }

    ll ans = 0;
    for (ll i = 0, ls = 0; i < n - k; ++i) {
        if (ab[i][1] > ab[i][0]) {
            ls += ab[i][1] - ab[i][0];
        }
        ans = max(ans, ls + dp[i + 1]);
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