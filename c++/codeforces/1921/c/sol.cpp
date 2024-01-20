#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n, f, a, b;
    cin >> n >> f >> a >> b;
    vector<ll> m(n + 1);
    m[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> m[i];
    }

    for (int i = 0; i < n; ++i) {
        f -= min((m[i + 1] - m[i]) * a, b);
        if (f <= 0) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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