#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        int ci;
        cin >> ci;
        sum += ci;
    }

    cout << -sum << '\n';
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