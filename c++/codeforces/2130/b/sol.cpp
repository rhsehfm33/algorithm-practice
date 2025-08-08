#include <bits/stdc++.h>
using namespace std;

int _ti;

void print_ans(vector<int> cnt) {
    while (cnt[0]--) {
        cout << "0 ";
    }
    while (cnt[2]--) {
        cout << "2 ";
    }
    while (cnt[1]--) {
        cout << "1 ";
    }
    cout << '\n';
}

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> cnt(3);
    for (int i = 0, ai; i < n; ++i) {
        cin >> ai;
        ++cnt[ai];
        s -= ai;
    }
    if (s == 0 or s >= 2) {
        cout << "-1\n";
        return;
    }
    print_ans(cnt);
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