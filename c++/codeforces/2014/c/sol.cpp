#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    if (n <= 2) {
        cout << -1 << '\n';
        return;
    }

    sort(a.begin(), a.end());
    ll sum = accumulate(a.begin(), a.end(), 0LL);
    cout << max(0LL, a[n / 2] * 2 * n + 1 - sum) << '\n';
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