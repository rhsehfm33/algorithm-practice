#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, m, k, p = -1;
    cin >> n >> m >> k;
    string a;
    cin >> a;
    while (p < n) {
        int np = p + 1;
        while (np < n and a[np] != 'L') {
            if (np - p >= m) {
                if ((a[np] == 'W' and --k < 0) or (a[np] == 'C')) {
                    cout << "NO\n";
                    return;
                }
            }
            ++np;
        }
        p = np;
    }

    cout << "YES\n";
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