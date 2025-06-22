#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int ans = 0;
    string l, r;
    cin >> l >> r;
    for (int i = 0, dd = 0; i < l.size(); ++i) {
        if (dd == 1) {
            if (l[i] == '9' and r[i] == '0') {
                ++ans;
                continue;
            } else {
                break;
            }
        }

        int d = (r[i] - l[i] + 10) % 10;
        if (d > 1) {
            break;
        } else if (d == 1) {
            ++ans;
            dd = 1;
        } else {
            ans += 2;
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