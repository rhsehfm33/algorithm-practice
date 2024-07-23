#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n;
    cin >> n;
    vector<ll> ans;
    for (ll i = 62; i >= 0; --i) {
        if ((n >> i) & 1) {
            ll num = n & (~(1LL << i));
            if (num) {
                ans.push_back(num);
            }
        }
    }
    ans.push_back(n);

    cout << ans.size() << '\n';
    for (auto& ansi : ans) {
        cout << ansi << ' ';
    }
    cout << '\n';
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