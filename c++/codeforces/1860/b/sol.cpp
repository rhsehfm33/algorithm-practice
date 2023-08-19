#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll m, k, a1, ak;
    cin >> m >> k >> a1 >> ak;

    m -= min(m / k, ak) * k;
    ll rem = m % k;
    m -= min(a1, rem);
    a1 -= min(a1, rem);
    m -= min(m / k * k, a1 / k * k);

    cout << m / k + m % k << '\n';
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