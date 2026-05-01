#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for (auto& [ar, ai] : a) {
        cin >> ai;
        if (ai % 6 == 0) {
            ar = 3;
        } else if (ai % 3 == 0) {
            ar = 2;
        } else if (ai % 2) {
            ar = 1;
        }
    }
    sort(a.begin(), a.end());
    for (auto& [ar, ai] : a) {
        cout << ai << ' ';
    }
    cout << '\n';
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