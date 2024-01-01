#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    set<ll> s;
    s.insert(0);
    for (ll i = 0, b = 0; i < n; ++i) {
        b += a[i] * (i % 2 == 0 ? 1 : -1);
        if (s.count(b)) {
            cout << "YES\n";
            return;
        }
        s.insert(b);
    }

    cout << "NO\n";
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