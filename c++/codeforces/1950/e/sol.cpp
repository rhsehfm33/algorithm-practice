#include <bits/stdc++.h>

using namespace std;

int _ti;
vector<int> cnt(26);

bool ok(string& s, int l) {
    int um = 0;
    for (int i = 0; i < l; ++i) {
        int mx = 0;
        fill(cnt.begin(), cnt.end(), 0);
        for (int j = i; j < s.size(); j += l) {
            mx = max(mx, ++cnt[s[j] - 'a']);
        }
        um += s.size() / l - mx;
    }
    return um <= 1;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = n;
    for (int i = 1; i * i <= n and ans > i; ++i) {
        if (n % i == 0) {
            if (ok(s, i)) {
                ans = i;
            } else if (ok(s, n / i)) {
                ans = n / i;
            }
        }
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