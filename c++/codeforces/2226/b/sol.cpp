#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto& pi : p) {
        cin >> pi;
    }

    int ans = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (max(p[i], p[i + 1]) - min(p[i], p[i + 1]) == gcd(p[i], p[i + 1])) {
            ++ans;
        }
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