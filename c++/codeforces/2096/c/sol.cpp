#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

vector<array<ll, 2>> cases = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
const ll INF = 1e18;
int _ti;

ll go(vector<vector<ll>>& h, vector<ll>& cost, ll n, bool ia) {
    array<ll, 2> dp = {0, cost[0]};
    for (ll i = 1; i < n; ++i) {
        array<ll, 2> ndp = {INF, INF};
        for (auto [p, c] : cases) {
            if (dp[p] >= INF) {
                continue;
            }

            bool ok = true;
            for (ll j = 0; j < n and ok; ++j) {
                if ((ia and h[i - 1][j] + p == h[i][j] + c)
                or (!ia and h[j][i - 1] + p == h[j][i] + c)) {
                    ok = false;
                }
            }
            if (ok) {
                ndp[c] = min(ndp[c], dp[p] + cost[i] * c);
            }
        }
        dp = ndp;
    }
    return min(dp[0], dp[1]);
}

void solve() {
    ll n;
    cin >> n;
    vector<vector<ll>> h(n, vector<ll>(n));
    for (auto& hi : h) {
        for (auto& hij : hi) {
            cin >> hij;
        }
    }
    vector<ll> a(n), b(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    for (auto& bi : b) {
        cin >> bi;
    }
    ll ans = go(h, a, n, true) + go(h, b, n, false);
    cout << (ans >= INF ? -1 : ans) << '\n';
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