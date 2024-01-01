#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    cout << a[0] << ' ';
    ll sum = a[0], odd = a[0] % 2;
    for (ll i = 1; i < n; ++i) {
        odd += a[i] % 2;
        sum += a[i];
        cout << sum - (odd / 3 + (odd % 3 == 1)) << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }

    return 0;
}