#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n, sum = 0, add = 0, sum2 = 0;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
        sum += ai;
        add += (ai - 2) / 2;
        sum2 += ai > 1 ? ai : 0;
    }

    ll ans1 = min(a.back() + a.back() / 2, sum);
    ll ans2 = min(sum2 + add, sum);
    ll ans = max(ans1, ans2);
    cout << (ans < 3 ? 0 : ans) << '\n';
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