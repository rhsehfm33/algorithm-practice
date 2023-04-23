#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a1(n), a2(n);
    for (int i = 0; i < n; ++i) {
        cin >> a1[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a2[i];
    }

    int dl = 3e5, dr = -1;
    for (int i = 0; i < n; ++i) {
        if (a1[i] != a2[i]) {
            dl = min(dl, i);
            dr = max(dr, i);
        }
    }

    if (dr == -1) {
        cout << 1 << ' ' << n << '\n';
        return;
    }

    while (dl - 1 >= 0 and a2[dl - 1] <= a2[dl]) {
        --dl;
    }
    while (dr + 1 < n and a2[dr + 1] >= a2[dr]) {
        ++dr;
    }

    cout << dl + 1 << ' ' << dr + 1 << '\n';
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