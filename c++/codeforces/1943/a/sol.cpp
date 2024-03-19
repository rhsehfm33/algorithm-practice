#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0, ai; i < n; ++i) {
        cin >> ai;
        ++m[ai];
    }

    int ans = n;
    for (int i = 0, c1 = 0; i < n; ++i) {
        if ((m[i] == 1 and c1) or !m[i]) {
            ans = i;
            break;
        }
        if (m[i] == 1) {
            ++c1;
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