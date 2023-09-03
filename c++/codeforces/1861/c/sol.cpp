#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    string s;
    cin >> s;

    int downs = 0;
    vector<int> ups;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '+') {
            ups.push_back(0);
        }
        else if (s[i] == '-') {
            if (ups.size() and ups.back() == -1) {
                --downs;
            }
            ups.pop_back();
        }
        else if (s[i] == '1') {
            if (downs) {
                cout << "NO\n";
                return;
            }
            for (int i = ups.size() - 1; i >= 0 and ups[i] == 0; --i) {
                ups[i] = 1;
            }
        }
        else if (s[i] == '0') {
            if (ups.size() <= 1 or ups.back() == 1) {
                cout << "NO\n";
                return;
            }

            if (ups.back() == 0) {
                ups.back() = -1;
                ++downs;
            }
        }
    }

    cout << "YES\n";
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