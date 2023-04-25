#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_NUM = 1e5;

void solve(int _ti) {
    ll a, b;
    cin >> a >> b;

    ll ans = 2e9;
    for (ll num = 1; num <= min(MAX_NUM, max(a, b)); ++num) {
        ll result = (num - 1) + (a + num - 1) / num + (b + num - 1) / num;
        ans = min(ans, result);
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