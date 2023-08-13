#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, m, k, x, y;
    cin >> n >> m >> k >> x >> y;
    vector<array<int, 2>> f(k);
    for (int i = 0; i < k; ++i) {
        cin >> f[i][0] >> f[i][1];
    }

    int vika = (x + y) % 2;
    for (int i = 0; i < k; ++i) {
        if ((f[i][0] + f[i][1]) % 2 == vika) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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