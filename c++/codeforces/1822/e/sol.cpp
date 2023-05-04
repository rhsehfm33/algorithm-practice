#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n % 2) {
        cout << -1 << '\n';
        return;
    }

    vector<int> ch2cnt(26);
    for (int i = 0; i < n; ++i) {
        ++ch2cnt[s[i] - 'a'];
    }

    for (int i = 0; i < 26; ++i) {
        if (ch2cnt[i] > n / 2) {
            cout << -1 << '\n';
            return;
        }
    }

    int match = 0;
    fill(ch2cnt.begin(), ch2cnt.end(), 0);
    for (int l = 0, r = n - 1; l < r; ++l, --r) {
        if (s[l] == s[r]) {
            ++match;
            ++ch2cnt[s[l] - 'a'];
        }
    }

    multiset<int> ms;
    for (int i = 0; i < 26; ++i) {
        if (ch2cnt[i]) {
            ms.insert(ch2cnt[i]);
        }
    }

    while (ms.size() > 1) {
        int next1 = *ms.begin() - 1;
        int next2 = *(prev(ms.end())) - 1;
        ms.erase(ms.begin());
        ms.erase(prev(ms.end()));
        if (next1) {
            ms.insert(next1);
        }
        if (next2) {
            ms.insert(next2);
        }
        --match;
    }

    cout << match << '\n';
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