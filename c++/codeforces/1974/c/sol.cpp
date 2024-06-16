#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    long long ans = 0;
    map<vector<int>, int> m;
    for (int i = 0; i + 2 < n; ++i) {
        ans += m[{0, a[i + 1], a[i + 2]}]++;
        ans += m[{a[i], 0, a[i + 2]}]++;
        ans += m[{a[i], a[i + 1], 0}]++;
        ans -= 3 * m[{a[i], a[i + 1], a[i + 2]}]++;
    }
    cout << ans << '\n';
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