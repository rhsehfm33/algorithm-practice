#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n;
    cin >> n;
    vector<ll> p(n);
    for (auto& pi : p) {
        cin >> pi;
    }

    ll ans = 0, sum = 0;
    for (ll i = 0; i < n; ++i) {
        if (i and p[i] > p[i - 1]) {
            ++sum;
        } else {
            sum += i + 1;
        }
        ans += sum;
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