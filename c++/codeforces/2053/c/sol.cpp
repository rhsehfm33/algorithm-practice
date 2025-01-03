#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

pair<ll, ll> go(ll k, ll len) {
    if (len < k) {
        return {0, 0};
    }

    auto [sum, cnt] = go(k, len / 2);
    if (len % 2) {
        sum += sum + (cnt + 1) * ((len + 1) / 2);
        cnt += cnt + 1;
    } else {
        sum += sum + cnt * (len / 2);
        cnt += cnt;
    }
    return {sum, cnt};
}

void solve() {
    ll n, k;
    cin >> n >> k;
    cout << go(k, n).first << '\n';
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