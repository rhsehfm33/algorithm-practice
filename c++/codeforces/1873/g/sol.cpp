#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    string s;
    cin >> s;

    bool b1 = true;
    int sum = 0, mn = 2e9;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'B') {
            if (i and s[i - 1] == 'B') {
                b1 = false;
            }
            continue;
        }

        int j = i;
        while (j < s.size() and s[j] == 'A') {
            ++j;
        }
        sum += (j - i);
        mn = min(mn, j - i);
        i = j;
    }

    if (s.front() == 'A' and s.back() == 'A' and b1) {
        cout << max(0, sum - mn) << '\n';
    }
    else {
        cout << sum << '\n';
    }
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