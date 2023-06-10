#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    ll ans = 0;
    for (ll i = 0, j = 0; i < n; ++i) {
        while (j < n and a[j] <= q) {
            ++j;
        }

        ll s = j - i - k + 1;
        if (s > 0) {
            ans += s * (s + 1) / 2;
        }
        i = j++;
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