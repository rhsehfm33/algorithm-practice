#include <bits/stdc++.h>

using namespace std;

int _ti;

int get_ti(string& s, int k) {
    for (int i = 0, j = 0, ch = s[0]; i < s.size(); ch ^= 1, i = j) {
        while (j < s.size() and s[j] == ch) {
            ++j;
        }

        int d = j - i;
        if (d > k) {
            return i + d - k;
        } else if (d < k) {
            return i + d;
        }
    }
    return s.size();
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int ti = get_ti(s, k);

    string ls = s.substr(0, ti);
    reverse(ls.begin(), ls.end());
    string s2 = s.substr(ti) + ls;
    for (int i = 0, ch = s2[0]; i < n; i += k, ch ^= 1) {
        for (int j = 0; j < k; ++j) {
            if (s2[i + j] != ch) {
                cout << "-1\n";
                return;
            }
        }
    }

    cout << ti << '\n';
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