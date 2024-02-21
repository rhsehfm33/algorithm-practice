#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    char t;
    cin >> t;
    map<char, vector<string>> m;
    for (int i = 0; i < n * 2; ++i) {
        string s;
        cin >> s;
        m[s[1]].push_back(s);
    }

    string ans;
    for (auto& [c, r] : m) {
        sort(r.begin(), r.end());
        if (c == t) {
            continue;
        }

        for (int i = 0; i < r.size(); i += 2) {
            if (i + 1 == r.size()) {
                if (m[t].size()) {
                    ans += r[i] + " " + m[t].back() + "\n";
                    m[t].pop_back();
                } else {
                    cout << "IMPOSSIBLE\n";
                    return;
                }
            } else {
                ans += r[i] + " " + r[i + 1] + "\n";
            }
        }
    }

    for (int i = 0; i < m[t].size(); i += 2) {
        ans += m[t][i] + " " + m[t][i + 1] + "\n";
    }
    cout << ans;
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