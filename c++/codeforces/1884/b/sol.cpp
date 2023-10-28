#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    for (long long i = s.size() - 1, cnt = 0, sum = 0; i >= 0; --i) {
        while (i - cnt >= 0 and s[i - cnt] == '1') {
            ++cnt;
        }

        if (i - cnt < 0) {
            cout << -1 << ' ';
            continue;
        }

        sum += cnt;
        cout << sum << ' ';
    }
    cout << '\n';
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