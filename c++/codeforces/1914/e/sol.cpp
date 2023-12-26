#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n), b(n), sab(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sab[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    ll ans = 0;
    sort(sab.begin(), sab.end(), [&](int l, int r) {
        return a[l] + b[l] > a[r] + b[r];
    });
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            ans += (a[sab[i]] - 1);
        } else {
            ans -= (b[sab[i]] - 1);
        }
    }
    cout << ans << '\n';
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