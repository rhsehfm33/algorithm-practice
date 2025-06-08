#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    string s;
    int n, k;
    cin >> n >> k >> s;
    array<int, 2> c = {0, 0};
    for (char si : s) {
        ++c[si - '0'];
    }

    int ck = n - k * 2;
    if (ck <= min(c[0], c[1]) * 2
    and (c[0] - ck / 2) % 2 == 0
    and (c[1] - ck / 2) % 2 == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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