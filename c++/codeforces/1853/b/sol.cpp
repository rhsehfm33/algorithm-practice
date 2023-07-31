#include <bits/stdc++.h>

using namespace std;

bool isPossible(int i, int f2, int f3) {
    if (i == 0) {
        return true;
    }
    if (f3 - f2 > f2) {
        return false;
    }
    return isPossible(i - 1, f3 - f2, f2);
}

void solve(int _ti) {
    int n, k;
    cin >> n >> k;

    int ans = 0;
    for (int f2 = n / 2; f2 <= n; ++f2) {
        ans += isPossible(k - 2,  f2, n);
    }

    cout << ans << '\n';
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