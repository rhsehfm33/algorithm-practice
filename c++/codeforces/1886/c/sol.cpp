#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    string s;
    cin >> s;
    ll p;
    cin >> p;

    ll tn = s.size(), n = s.size();
    while (p - tn > 0) {
        p -= tn--;
    }

    string ans = "";
    for (ll i = 0; i < n; ++i) {
        while (ans.size() and s[i] < ans.back() and (int)ans.size() - 1 + (n - i) >= tn) {
            ans.pop_back();
        }
        if (ans.size() < tn) {
            ans += s[i];
        }
    }
    cout << ans[p - 1];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }
    cout << '\n';

    return 0;
}