#include <bits/stdc++.h>

using namespace std;

bool is_parent(vector<int>& lc, vector<int>& rc) {
    for (int i = 0; i < 26; ++i) {
        if (rc[i] > lc[i]) {
            return false;
        }
    }
    return true;
}

int get_min(string& s, int pi) {
    int result = s.size() - pi * 2;
    vector<int> lc(26), rc(26);
    for (int i = pi; i < s.size() - pi; ++i) {
        ++lc[s[i] - 'a'];
    }
    for (int i = s.size() - 1 - pi; i > pi; --i) {
        if (i >= s.size() / 2) {
            --lc[s[i] - 'a'];
            ++rc[s[i] - 'a'];
            if (!is_parent(lc, rc)) {
                break;
            }
        } else {
            --lc[s[i] - 'a'];
            --rc[s[s.size() - 1 - i] - 'a'];
            if (s[i] != s[s.size() - 1 - i] or !is_parent(lc, rc)) {
                break;
            }
        }
        result = i - pi;
    }
    return result;
}

void solve(int _ti) {
    string s;
    cin >> s;
    int pi = -1;
    for (int l = 0, r = s.size() - 1; l < r; ++l, --r) {
        if (s[l] != s[r]) {
            pi = l;
            break;
        }
    }
    if (pi == -1) {
        cout << "0\n";
        return;
    }

    string rs = s;
    reverse(rs.begin(), rs.end());
    cout << min(get_min(s, pi), get_min(rs, pi)) << '\n';
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