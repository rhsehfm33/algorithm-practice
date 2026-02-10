#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> bs(n);
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            char sij;
            cin >> sij;
            bs[j] |= (1 << (sij - 'a'));
        }
    }
    for (int d = 1; d <= n; ++d) {
        if (n % d) {
            continue;
        }
        string ans = "";
        for (int i = 0; i < d; ++i) {
            int b = bs[i];
            for (int j = i + d; j < n; j += d) {
                b &= bs[j];
            }
            if (b == 0) {
                break;
            }
            ans += ('a' + (int)log2(b));
        }
        if (ans.size() == d) {
            for (int i = 0; i < n / d; ++i) {
                cout << ans;
            }
            cout << '\n';
            return;
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