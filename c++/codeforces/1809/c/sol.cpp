#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, k;
    cin >> n >> k;

    vector<int> ans(n, -1);
    for (int i = 0; i < n and k; ++i) {
        if (k >= n - i) {
            k -= (n - i);
            ans[i] = 1000;
        }
        else if (k > 0) {
            ans[i] = k;
            if (i + k < n) {
                ans[i + k] -= 1;
            }
            k = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
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