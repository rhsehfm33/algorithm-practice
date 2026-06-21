#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1]) {
            swap(a[i], a[i - 1]);
            a[i] += a[i - 1];
        }
    }
    cout << a.back() << '\n';
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