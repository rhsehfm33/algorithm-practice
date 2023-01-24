#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll ans = 0;

    int mn = 2e9;
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            cin >> a[x][y];
            ans += a[x][y];
            if (n - x - 1 == y) {
                mn = min(mn, a[x][y]);
            }
        }
    }

    cout << ans - mn << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    solve();

    return 0;
}