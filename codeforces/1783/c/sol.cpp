#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0];
        a[i][1] = i;
    }

    sort(a.begin(), a.end(), [](auto& l, auto& r) {
        if (l[0] != r[0]) {
            return l[0] < r[0];
        }
        else {
            return l[1] > r[1];
        }
    });

    int wins = 0, mx = 0;
    for (int i = 0; i < n; ++i) {
        if (m >= a[i][0]) {
            mx = max(mx, a[i][0]);
            m -= a[i][0];
            a[i][0] = -1;
            ++wins;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (a[i][1] == wins and mx + m >= a[i][0]) {
            ++wins;
            break;
        }
    }

    cout << n - wins + 1 << '\n';
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