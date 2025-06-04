#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int x, ans = 0;
    cin >> x;
    vector<int> v(3, x);
    while (v.back()) {
        v[2] = v[1] / 2;
        sort(v.begin(), v.end());
        ++ans;
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