#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int color = 0;
    vector<int> ans;
    int lb = 0, rb = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            if (rb > 0) {
                color |= 2;
                ans.push_back(2);
                --rb;
            }
            else {
                color |= 1;
                ans.push_back(1);
                ++lb;
            }
        }
        else {
            if (lb > 0) {
                color |= 1;
                ans.push_back(1);
                --lb;
            }
            else {
                color |= 2;
                ans.push_back(2);
                ++rb;
            }
        }
    }

    if (rb or lb) {
        cout << -1 << '\n';
    }
    else {
        int ans_n = __builtin_popcount(color);
        cout << ans_n << '\n';
        for (auto ai : ans) {
            if (ans_n == 1) {
                cout << 1 << ' ';
            }
            else {
                cout << ai << ' ';
            }
        }
        cout << '\n';
    }
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