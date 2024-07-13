#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    string a, b;
    cin >> a >> b;
    int ans = a.size() + b.size();
    for (int i = 0; i < b.size(); ++i) {
        int j = i, k = 0;
        while (j < b.size()) {
            while (k < a.size() and a[k] != b[j]) {
                ++k;
            }
            if (k < a.size() and a[k] == b[j]) {
                ++k;
                ++j;
            } else {
                break;
            }
        }
        ans = min(ans, (int)a.size() + (int)b.size() - (j - i));
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