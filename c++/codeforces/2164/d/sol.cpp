#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    vector<vector<int>> c2i(26);
    for (int i = 0; i < n; ++i) {
        c2i[s[i] - 'a'].push_back(i);
    }

    int ans_k = 0;
    vector<array<int, 2>> ans;
    for (int i = n - 1, li = n - 1; i >= 0; --i) {
        li = min(li, i);
        if (s[li] == t[i]) {
            continue;
        }
        int ci = t[i] - 'a';
        while (c2i[ci].size() and c2i[ci].back() >= li) {
            c2i[ci].pop_back();
        }
        if (c2i[ci].empty() or i - c2i[ci].back() > k) {
            cout << "-1\n";
            return;
        }
        li = c2i[ci].back();
        ans.push_back({li + 1, i});
        ans_k = max(ans_k, i - li);
    }

    cout << ans_k << '\n';
    while (ans_k--) {
        string ns = s;
        vector<array<int, 2>> nans;
        for (auto& [li, ri] : ans) {
            ns[li] = s[li - 1];
            if (li + 1 <= ri) {
                nans.push_back({li + 1, ri});
            }
        }
        cout << ns << '\n';
        s = ns;
        ans = nans;
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