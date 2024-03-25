#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

int _ti;

void solve() {
    ll sum = 0, mx = -2e9, mn = 0;
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
        sum += ai;
        mx = max(mx, sum - mn);
        mn = min(mn, sum);
    }
    sum = (sum + MOD * n) % MOD;

    if (mx > 0) {
        for (ll i = 0, sum2 = mx % MOD; i < k; ++i) {
            sum = (sum + sum2) % MOD;
            sum2 = (sum2 + sum2) % MOD;
        }
    }

    cout << sum << '\n';
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