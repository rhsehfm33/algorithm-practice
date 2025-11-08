#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;

int _ti;

ll help(vector<ll>& a) {
    vector<ll> dp(a.size() + 1, inf);
    dp[0] = 0;
    for (ll i = 0; i + 1 < a.size(); ++i) {
        if (dp[i] == inf) {
            continue;
        }

        dp[i + 2] = min(dp[i + 2], dp[i] + abs(a[i] - a[i + 1]));
        if (i + 2 < a.size()) {
            ll mx = max({a[i], a[i + 1], a[i + 2]});
            ll mn = min({a[i], a[i + 1], a[i + 2]});
            dp[i + 3] = min(dp[i + 3], dp[i] + mx - mn);
        }
    }
    a.insert(a.begin(), a.back());
    a.pop_back();
    return dp[a.size()];
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    cout << min({help(a), help(a), help(a)}) << '\n';
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