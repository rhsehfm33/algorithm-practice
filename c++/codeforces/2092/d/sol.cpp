#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> m;
    m['L'] = m['I'] = m['T'] = 0;
    for (auto& c : s) {
        ++m[c];
    }

    vector<int> ans;
    s = " " + s;
    for (int i = n + 1; i <= 3 * n; ++i) {
        map<char, int> m2;
        for (int j = 1; j + 1 < s.size(); ++j) {
            if (s[j] == s[j + 1]) {
                continue;
            }
            if (s[j] != 'L' and s[j + 1] != 'L') {
                m2['L'] = j + 1;
            } else if (s[j] != 'I' and s[j + 1] != 'I') {
                m2['I'] = j + 1;
            } else if (s[j] != 'T' and s[j + 1] != 'T') {
                m2['T'] = j + 1;
            }
        }

        vector<pair<char, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), [](auto& l, auto& r) {
            return l.second < r.second;
        });
        for (auto [c, cnt] : v) {
            if (m2.count(c)) {
                ans.push_back(m2[c] - 1);
                s.insert(s.begin() + m2[c], c);
                ++m[c];
                break;
            }
        }
        if (s.size() <= i) {
            cout << -1;
            return;
        }
    }

    cout << ans.size();
    for (auto ans_i : ans) {
        cout << '\n' << ans_i;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
        cout << '\n';
    }

    return 0;
}