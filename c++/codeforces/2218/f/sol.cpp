#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int e, o;
    cin >> e >> o;
    if ((e + o) % 2) {
        --o;
    } else {
        --e;
    }
    if (o < 0 or e < 0 or e > o) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    int v = 1;
    while (e > 0) {
        cout << v << ' ' << v + 1 << '\n';
        cout << v + 1 << ' ' << v + 2 << '\n';
        --e;
        --o;
        v += 2;
    }
    while (o > 0) {
        cout << 1 << ' ' << ++v << '\n';
        --o;
    }
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