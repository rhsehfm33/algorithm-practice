#include <bits/stdc++.h>

using namespace std;

const string v = "aeiou";

int _ti;

void solve() {
    string ans;
    int n; cin >> n;
    for (int i = 0; i < 5; ++i) {
        ans += string(n / 5, v[i]);
        ans += i + 1 <= n % 5 ? string(1, v[i]) : "";
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