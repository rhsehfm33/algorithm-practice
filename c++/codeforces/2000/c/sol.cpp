#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    cin >> m;
    vector<string> s(m);
    for (auto& si : s) {
        cin >> si;
    }

    for (auto& si : s) {
        if (si.size() != n) {
            cout << "NO\n";
            continue;
        }

        bool result = true;
        set<char> ss;
        map<int, char> a2s;
        for (int j = 0; j < n and result; ++j) {
            if (!a2s.count(a[j])) {
                if (ss.count(si[j])) {
                    result = false;
                }
                a2s[a[j]] = si[j];
                ss.insert(si[j]);
            } else if (si[j] != a2s[a[j]]) {
                result = false;
            }
        }
        cout << (result ? "YES" : "NO") << '\n';
    }
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