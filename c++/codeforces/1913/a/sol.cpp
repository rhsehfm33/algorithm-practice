#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    string ab;
    cin >> ab;
    for (int i = 0; i + 1 < ab.size(); ++i) {
        string sa = ab.substr(0, i + 1);
        string sb = ab.substr(i + 1);
        if (sa.front() == '0' or sb.front() == '0') {
            continue;
        }
        int a = stoi(sa);
        int b = stoi(sb);
        if (b > a) {
            cout << a << ' ' << b << '\n';
            return;
        }
    }

    cout << -1 << '\n';
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