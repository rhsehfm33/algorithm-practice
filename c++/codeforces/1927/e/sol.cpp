#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, k;
    cin >> n >> k;

    vector<int> ans;
    for (int i = 0, l = 1, r = n, rm = n % k; i < k; ++i, --rm) {
        if (i % 2 == 0) {
            ans.push_back(l);
            l += (n / k) + (rm > 0);
        } else {
            ans.push_back(r);
            r -= (n / k) + (rm > 0);
        }
    }

    for (int i = k; i < n; ++i) {
        if (i % 2 == 0) {
            ans.push_back(ans[i - k] + 1);
        } else {
            ans.push_back(ans[i - k] - 1);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
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