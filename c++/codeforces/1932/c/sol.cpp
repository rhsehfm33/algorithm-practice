#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    vector<int> bt;
    for (int i = 0, l = 0, r = n - 1; i < n; ++i) {
        char ch;
        cin >> ch;
        if (ch == 'L') {
            bt.push_back(a[l++]);
        } else {
            bt.push_back(a[r--]);
        }
    }

    vector<int> ans;
    int cur = 1;
    for (int i = n - 1; i >= 0; --i) {
        cur = (cur * bt[i]) % m;
        ans.push_back(cur);
    }
    for (int i = n - 1; i >= 0; --i) {
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