#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    int l = 1, h = n;
    while (l <= h) {
        int m = (l + h) / 2;
        int sum = 0;
        for (int i = m; i and sum < n; --i) {
            sum += (m / i) * i;
        }
        if (sum >= n) {
            h = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << ++h << '\n';
    for (int num = h, i = 1; ; --num) {
        for (int j = 0; j < (h / num); ++j, ++i) {
            for (int k = 0; k < num; ++k) {
                cout << i << ' ';
                if (--n <= 0) {
                    cout << '\n';
                    return;
                }
            }
        }
    }
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