#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, s, r;
    cin >> n >> s >> r;
    vector<int> ans(n - 1);
    for (int i = 0, cr = r; cr; ++i, --cr) {
        ++ans[i % (n - 1)];
    }
    ans.push_back(s - r);

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