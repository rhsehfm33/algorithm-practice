#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> cnt(26), chs(26);
    for (char ch : s) {
        ++cnt[ch - 'a'];
    }
    iota(chs.begin(), chs.end(), 0);
    sort(chs.begin(), chs.end(), [&](int l, int r) {
        return cnt[l] > cnt[r];
    });

    int i = 0;
    string ans;
    while (ans.size() < n) {
        int chi = chs[i % 26];
        if (cnt[chi]-- > 0) {
            ans += string(1, 'a' + chi);
        }
        ++i;
    }
    cout << ans << '\n';
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