#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int m;
    cin >> m;
    if (m % 2 == 0) {
        cout << "-1\n";
        return;
    }

    vector<int> ans;
    for (int i = log2((double)m); i > 0; --i) {
        if ((m >> i) & 1) {
            ans.push_back(2);
        }
        else {
            ans.push_back(1);
        }
    }

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
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