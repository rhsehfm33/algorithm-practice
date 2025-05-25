#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    multiset<ll> ms;
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
        ms.insert(ai);
    }

    cout << *ms.rbegin() << ' ';
    for (ll i = n - 1, sum = 0; i; --i) {
        sum += a[i];
        ms.erase(ms.find(a[i]));
        cout << sum + *ms.rbegin() << ' ';
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