#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX = 1e5;
const ll MOD = 1000000007;

ll ans[MAX + 1];

void preset() {
    memset(ans, 0, sizeof(ans));
    for (ll i = 2, pm = 1, sum = 0; i <= MAX; ++i) {
        sum = (sum + i - 1) % MOD;
        pm = (pm * i) % MOD;
        ans[i] = (((sum * 2) % MOD) * pm) % MOD;
    }
}

void solve(int _ti) {
    ll n;
    cin >> n;
    cout << ans[n] << '\n';
}

int main() {
    preset();

    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }

    return 0;
}