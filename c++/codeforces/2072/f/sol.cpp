#include <bits/stdc++.h>

using namespace std;

int _ti;

int get2(int num) {
    int cnt = 0;
    while (num % 2 == 0) {
        ++cnt;
        num /= 2;
    }
    return cnt;
}

void solve() {
    int n, k;
    cin >> n >> k;
    cout << k << ' ';
    for (int i = 1, l2 = 0, r2 = 0; i < n; ++i) {
        l2 += get2(i);
        r2 += get2(n - i);
        cout << (r2 - l2 <= 0 ? k : 0) << ' ';
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