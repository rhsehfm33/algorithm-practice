#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    string s;
    cin >> s;

    if (s.find_first_of('0') == string::npos) {
        cout << (ll)s.size() * (ll)s.size() << '\n';
        return;
    }

    s += s;

    ll ans = 0;
    for (ll i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            continue;
        }

        ll j = i;
        while (j < s.size() and s[i] == s[j]) {
            ++j;
        }

        ll len = j - i;
        if (len % 2) {
            ans = max(ans, (len / 2 + 1) * (len / 2 + 1));
        }
        else {
            ans = max(ans, (len / 2) * (len / 2 + 1));
        }

        i = j;
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