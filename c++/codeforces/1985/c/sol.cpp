#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n, sum = 0, ans = 0, mx = 0;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
        sum += ai;
        mx = max(mx, ai);
        if (mx * 2 == sum) {
            ++ans;
        }
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