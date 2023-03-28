#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    string s;
    cin >> s;
    map<char, int> ch2cnt;
    for (char ch : s) {
        ++ch2cnt[ch];
    }

    if (ch2cnt.size() == 1) {
        cout << "-1\n";
    }
    else if (ch2cnt.size() == 2) {
        if (ch2cnt.begin()->second == 2) {
            cout << "4\n";
        }
        else {
            cout << "6\n";
        }
    }
    else {
        cout << "4\n";
    }
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