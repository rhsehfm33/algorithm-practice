#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> b(30, vector<int>(n + 1));
    for (int i = 0; i < 30; ++i) {
        for (int j = 1; j <= n; ++j) {
            b[i][j] = ((a[j] >> i) & 1) + b[i][j - 1];
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int l, k;
        cin >> l >> k;
        int low = l, high = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            int r = 0;
            for (int i = 0; i < 30; ++i) {
                if (b[i][mid] - b[i][l - 1] == mid - l + 1) {
                    r |= (1 << i);
                }
            }
            if (r >= k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        if (high == l - 1) {
            cout << -1 << ' ';
        }
        else {
            cout << low - 1 << ' ';
        }
    }
    cout << '\n';
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