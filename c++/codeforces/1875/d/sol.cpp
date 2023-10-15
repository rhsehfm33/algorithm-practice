#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 8e18;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    sort(a.begin(), a.end());

    int mx = 0;
    vector<int> cnt(5001);
    for (auto& ai : a) {
        if (ai == mx) {
            ++mx;
        } else if (ai > mx) {
            break;
        }
        ++cnt[ai];
    }

    if (mx == 0) {
        cout << "0\n";
        return;
    }

    vector<vector<ll>> dp(mx + 1, vector<ll>(mx + 1, INF));
    for (int i = 0; i < mx; ++i) {
        dp[i][mx] = 0;
    }

    for (ll i = mx - 1; i > 0; --i) {
        for (ll j = mx; j > i; --j) {
            dp[i - 1][j] = min(dp[i - 1][j], dp[i][j]);
            dp[i - 1][i] = min(dp[i - 1][i], dp[i][j] + j * (cnt[i] - 1) + i);
        }
    }

    ll ans = INF;
    for (ll i = mx; i > 0; --i) {
        ans = min(ans, dp[0][i] + (ll)i * (cnt[0] - 1));
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