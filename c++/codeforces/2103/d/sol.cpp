#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, li;
    cin >> n;
    vector<int> ans(n);
    vector<array<int, 2>> sa;
    for (int i = 0, ai; i < n; ++i) {
        cin >> ai;
        if (ai == -1) {
            li = i;
        } else {
            sa.push_back({ai, i});
        }
    }
    sort(sa.begin(), sa.end(), [&](auto& l, auto& r) {
        if (l[0] != r[0]) {
            return l[0] < r[0];
        } else {
            return abs(li - l[1]) > abs(li - r[1]);
        }
    });

    int l = 1, h = n;
    for (auto& [ai, i] : sa) {
        if (ai % 2) {
            ans[i] = h--;
        } else {
            ans[i] = l++;
        }
    }
    ans[li] = l;

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
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