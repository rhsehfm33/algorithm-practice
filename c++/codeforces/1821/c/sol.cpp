#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    string s;
    cin >> s;

    int ans = 1e6;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        if (s.find_first_of(ch) == string::npos) {
            continue;
        }
        
        vector<pair<char, int>> pos;
        for (int i = 0; i < s.size(); ++i) {
            pos.push_back({s[i], i});
        }

        int cnt = 0;
        while (true) {
            pair<char, int> last_deleted = {'X', -100};
            vector<pair<char, int>> next_pos;
            for (int i = 0, ni = 0; i < pos.size(); ++i) {
                if (pos[i].first == ch or pos[i].second - last_deleted.second == 1) {
                    next_pos.push_back({pos[i].first, ni++});
                }
                else {
                    last_deleted = {pos[i].first, i};
                }
            }

            if (pos.size() == next_pos.size()) {
                break;
            }

            pos = next_pos;
            ++cnt;
        }

        ans = min(ans, cnt);
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