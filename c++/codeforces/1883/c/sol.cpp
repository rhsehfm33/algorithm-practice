#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, k;
    cin >> n >> k;

    int c2 = 0, mn = 1e9;
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        mn = min(mn, (k - ai % k) % k);
        while (ai % 2 == 0) {
            c2 += 1;
            ai /= 2;
        }
    }
    if (k == 4) {
        mn = min(mn, 2 - c2);
    }

    cout << max(0, mn) << '\n';
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