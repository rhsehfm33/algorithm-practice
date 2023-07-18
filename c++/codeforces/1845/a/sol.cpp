#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, k, x;
    cin >> n >> k >> x;

    if (k == 1 and x == 1) {
        cout << "NO" << '\n';
        return;
    }
    if (k == 2 and x == 1 and n % 2) {
        cout << "NO" << '\n';
        return;
    }

    vector<int> ans;
    if (x != 1) {
        ans.resize(n, 1);
    }
    else {
        if (n % 2) {
            n -= 3;
            ans.push_back(3);
        }
        while (n) {
            ans.push_back(2);
            n -= 2;
        }
    }

    cout << "YES" << '\n';
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