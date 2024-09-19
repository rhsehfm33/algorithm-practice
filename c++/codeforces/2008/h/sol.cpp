#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> ps(n + 1);
    for (int i = 0; i < n; ++i) {
        int ai; cin >> ai;
        ++ps[ai];
    }
    for (int i = 1; i <= n; ++i) {
        ps[i] += ps[i - 1];
    }

    vector<int> ans(n + 1, -1);
    while (q--) {
        int x; cin >> x;

        if (ans[x] == -1) {
            int low = 0, high = x - 1;
            while (low <= high) {
                int sum = 0;
                int mid = (low + high) / 2;
                for (int i = 0; i <= n; i += x) {
                    int l = i ? ps[i - 1] : 0;
                    int r = ps[min(n, i + mid)];
                    sum += (r - l);
                }
                if (sum - 1 >= n / 2) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            ans[x] = high + 1;
        }

        cout << ans[x] << ' ';
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