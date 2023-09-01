#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, a, q;
    cin >> n >> a >> q;
    string s;
    cin >> s;

    if (a == n) {
        cout << "YES";
        return;
    }

    int cur = a, sum = a;
    for (char ch : s) {
        if (ch == '+') {
            ++cur;
            ++sum;
        }
        else {
            --cur;
        }

        if (cur == n) {
            cout << "YES";
            return;
        }
    }

    if (sum >= n) {
        cout << "MAYBE";
    }
    else {
        cout << "NO";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
        cout << '\n';
    }

    return 0;
}