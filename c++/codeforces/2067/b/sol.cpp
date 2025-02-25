#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    for (int i = 0, ai; i < n; ++i) {
        cin >> ai;
        ++cnt[ai];
    }

    for (int i = n; i >= 1; --i) {
        for (int j = i + 1; j <= n; ++j) {
            while ((cnt[j] < 2 or cnt[j] % 2) and cnt[i] > 2) {
                ++cnt[j];
                --cnt[i];
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (cnt[i] % 2) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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