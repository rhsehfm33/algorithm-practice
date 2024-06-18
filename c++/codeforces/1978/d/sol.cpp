#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    multiset<ll> ms;
    ll n, c;
    cin >> n >> c;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
        ms.insert(ai);
    }

    for (ll i = 0, sum = 0, lm = a[0] + c; i < n; ++i) {
        ms.erase(ms.find(a[i]));
        if (a[i] <= lm or (ms.size() and a[i] < *ms.rbegin())) {
            cout << i + (ms.size() ? (a[i] + sum + c < *ms.rbegin()) : 0) << ' ';
        } else {
            cout << "0 ";
        }
        lm = max(lm, a[i]);
        sum += a[i];
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