#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int q;
    cin >> q;
    string ans = string(q, '0');
    vector<int> left, right;
    for (int qi = 0; qi < q; ++qi) {
        int x;
        cin >> x;
        if (left.empty()) {
            if (right.empty() or x >= right.back()) {
                ans[qi] = '1';
                right.push_back(x);
            }
            else if (x <= right.front()) {
                ans[qi] = '1';
                left.push_back(x);
            }
        }
        else {
            if (x >= left.back() and x <= right.front()) {
                ans[qi] = '1';
                left.push_back(x);
            }
        }
    }

    cout << ans << '\n';
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