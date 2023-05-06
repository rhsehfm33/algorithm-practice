#include <bits/stdc++.h>

using namespace std;

int get_sum(int num) {
    return (1 + num) * num / 2;
}

void solve(int _ti) {
    int n, k;
    cin >> n >> k;

    int p1 = -1, m1 = -1;
    for (int i = 0; i < n; ++i) {
        int sum = get_sum(max(0, i - 1)) + get_sum(n - i - 1);
        if (sum == k) {
            p1 = i;
            m1 = n - i;
        }
    }

    if (p1 == -1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i = 0; i < p1; ++i) {
        cout << 1 << ' ';
    }
    for (int i = 0; i < m1; ++i) {
        cout << -1 << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int _ti = 1; _ti <= T; ++_ti) {
        solve(_ti);
    }
}