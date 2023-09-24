#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, k;
    cin >> n;
    map<int, int> c2i;
    for (int i = 0, c; i < n; ++i) {
        cin >> c;
        c2i[c] = i;
    }
    cin >> k;

    vector<array<int, 4>> s;
    for (auto& [c, i] : c2i) {
        if (s.size() and s.back()[1] == 0) {
            break;
        }

        if (s.empty()) {
            s.push_back({k / c, k % c, c, i});
        }
        else if (i > s.back()[3] and c < s[0][2] * 2) {
            int d = min(s.back()[0], s.back()[1] / (c % s.back()[2]));
            int r = s.back()[1] - (c % s.back()[2]) * d;
            s.push_back({d, r, c, i});
        }
    }

    vector<int> ans(n);
    for (int i = 0, j = 0; i < s.size(); ++i) {
        while (j <= s[i][3]) {
            ans[j++] = s[i][0];
        }
    }

    for (int i = 0; i < n; ++i) {
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