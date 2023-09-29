#include <bits/stdc++.h>

using namespace std;

pair<int, int> getAB(int num) {
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return {num - i, i};
        }
    }
    return {-1, -1};
}

void solve(int _ti) {
    int l, r;
    cin >> l >> r;
    auto ab1 = getAB(r);
    auto ab2 = getAB(max(l, r - 1));
    auto ans = max(ab1, ab2);

    if (ans.first == -1) {
        cout << -1 << '\n';
    }
    else {
        cout << ans.first << ' ' << ans.second << '\n';
    }
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