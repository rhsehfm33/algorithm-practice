#include <bits/stdc++.h>

using namespace std;

int _ti;

int tn[5] = {15, 10, 6, 3, 1};

int get_min(int n, int i) {
    if (n % tn[i] == 0) {
        return n / tn[i];
    }
    int d = n / tn[i];
    int r1 = d + get_min(n - tn[i] * d, i + 1);
    int r2 = max(0, d - 1) + get_min(n - tn[i] * max(0, d - 1), i + 1);
    return min(r1, r2);
}

void solve() {
    int n;
    cin >> n;
    cout << get_min(n, 0) << '\n';
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