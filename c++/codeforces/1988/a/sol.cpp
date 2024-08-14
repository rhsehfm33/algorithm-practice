#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, k;
    cin >> n >> k;
    --n;
    --k;
    cout << (n + k - 1) / k << '\n';
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