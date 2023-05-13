#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, k;
    cin >> n >> k;
    vector<int> x(k), c(k);
    for (int i = 0; i < k; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < k; ++i) {
        cin >> c[i];
    }

    int bi = 0;
    char ch = 'd';
    string base = "abc";
    string ans = "";
    for (int i = 0, pc = 0, px = 0; i < k; ++i) {
        if ((x[i] <= 3 and x[i] != c[i]) or (c[i] - pc > x[i] - px)) {
            cout << "NO\n";
            return;
        }

        for (int j = 0; j < c[i] - pc; ++j) {
            if (ans.size() < 3) {
                ans += base[bi++ % 3];
            }
            else {
                ans += ch;
            }
        }
        for (int j = c[i] - pc; j < x[i] - px; ++j) {
            ans += base[(bi++ % 3)];
        }
        if (ans.size() > 3) {
            ++ch;
        }
        px = x[i];
        pc = c[i];
    }
    cout << "YES\n";
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int _ti = 1; _ti <= T; ++_ti) {
        solve(_ti);
    }
}