#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> a(n);
    vector<array<int, 2>> a2(n, {0, -1});
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a2[i][0] = a[i];
    }

    int last = -2;
    for (int i = 0, b, c; i < m; ++i) {
        cin >> b >> c;
        --b;
        if (a2[b][1] < last) {
            a2[b][0] = a[b];
        }
        if (a2[b][0] + c > h) {
            a2[b][0] = a[b];
            last = i;
        } else {
            a2[b][0] += c;
        }
        a2[b][1] = i;
    }
    for (int i = 0; i < n; ++i) {
        cout << (a2[i][1] < last ? a[i] : a2[i][0]) << ' ';
    }
    cout << '\n';
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